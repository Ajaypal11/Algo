/*
    ajay_pal_11
    22/7/2020
    complexity : O(n+q)*30
*/
#include <cstdio>
#include <vector>
#define int64 long long int
const int maxN = 100500,maxL=24,mod=1e9+7;
int tin[maxN],tout[maxN],depth[maxN],up[maxN][maxL],timer;
int info[3*maxN][31],nCr[maxN][5],arr[maxN],pathInfo[31];
std::vector<int> tree[maxN];
void myswap(int &x,int &y){int t=x;x=y;y=t;}
int check(int64 x){if(x>=mod)x%=mod;return x;}
void dfs(int u,int p){
    up[u][0]=p,tin[u]=++timer,depth[u]=depth[p]+1;
    for(int i=1;i<maxL;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(int &v : tree[u]){
        if(v!=p)dfs(v,u);
    }
    tout[u]=++timer;
}
bool isAncestor(int u,int v){
    return (tin[u]<=tin[v] && tout[u]>=tout[v]);
}
int LCA(int u,int v){
    if(isAncestor(u,v))return u;
    else if(isAncestor(v,u))return v;
    else{
        for(int i=maxL-1;i>=0;i--){
            if(!isAncestor(up[u][i],v))u=up[u][i];
        }
        return up[u][0];
    }
}
int solve(int type,int nodes){
    int64 ret=0,x=1,y;
    int n,m;
    for(int j=0;j<=30;j++){
        n=pathInfo[j],m=nodes-pathInfo[j];
        y=0;
        for(int k=type;k>0;k--){
            y+=check(1LL * nCr[n][k] * nCr[m][type-k]);
        }
        ret = check( ret + check(1LL * x * check(y)));
        x=check(1LL*x*2);
    }
    return ret;
}
int main(){
    nCr[0][0]=1;
    int n,q,u,v,d,type,ancestor;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        nCr[i][0]=1;
        for(int j=1;j<5;j++){
            nCr[i][j]=nCr[i-1][j]+nCr[i-1][j-1];
            if(nCr[i][j]>=mod)nCr[i][j]-=mod;
        }
    }
    for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,1);
    up[1][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=30;j++){
            info[tin[i]][j] = (arr[i]&(1<<j))>0 ? 1 : 0 ;
            info[tout[i]][j] = -info[tin[i]][j];
        }
    }
    for(int i=1;i<=timer;i++){
        for(int j=0;j<=30;j++)info[i][j]+=info[i-1][j];
    }
    scanf("%d",&q);
    while (q--){
        scanf("%d%d%d",&type,&u,&v);
        if(depth[u]>depth[v])myswap(u,v);
        ancestor=LCA(u,v);
        for(int j=0;j<=30;j++){
            if(ancestor==u)pathInfo[j]=info[tin[v]][j]-info[tin[up[ancestor][0]]][j];
            else pathInfo[j]=info[tin[v]][j]+info[tin[u]][j]-info[tin[ancestor]][j]-info[tin[up[ancestor][0]]][j];
        }
        printf("%d\n",solve(type,depth[u]+depth[v]-2*depth[ancestor]+1));
    }
    return 0;
}
