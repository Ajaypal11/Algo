/*
    ajay_pal_11
    19/5/2020
    complexity : O(n*k)
*/
#include <iostream>
#include <vector>
#define int64 long long int
const int MAXN = 50009 , MAXK = 509 ;
int K , dist[MAXN][MAXK] , info[MAXN][MAXK];
std::vector<int> tree[MAXN];
void dfs(int node=1,int parent=0){
    dist[node][0] = 1 ;
    for(int &child : tree[node]){
        if( child != parent){
            dfs(child,node);
            for(int i=0;i<MAXK-1;i++) dist[node][i+1] += dist[child][i] ;
        }
    }
}
int64 dfs2(int node=1,int parent=0){
    int64 ret = dist[node][K] + info[node][K] ;
    for(int &child : tree[node]){
        if( child != parent){
            for(int i=1;i<MAXK;i++) info[child][i] = info[node][i-1] + ( dist[node][i-1] - (i>=2?dist[child][i-2]:0) ) ;
            ret += dfs2( child , node );
        }
    }
    return ret;
}
int main(){
    int n , u , v ;
    scanf("%d %d",&n,&K);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs();
    printf("%lld\n",dfs2()/2);
}
