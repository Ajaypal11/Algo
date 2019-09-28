/*
  ajay_pal_11
  29/9/19
  complexity => O(q*log(n)) 
  q=>number of queries 
  n=>number of nodes
*/

#include "bits/stdc++.h"
using namespace std ;
const int MAX=1e5+1e3 , MAX2=1e6+1e3;
int value[MAX] , size[MAX] , nodeToPosition[MAX] , positionTonode[MAX] , st[4*MAX2] , mod3div[MAX2];
vector<int>g[MAX];
int itr ;

int dfs(int node,int parent){
    size[node]++;
    nodeToPosition[node] = itr ;
    positionTonode[itr] = node ;
    itr++;

    for(int i=0;i<g[node].size();i++){
        if( g[node][i] != parent )
            size[node] += dfs(g[node][i],node);
    }
    return size[node];
}

void build(int low,int high,int pos){
    if(low==high){
        st[pos] = mod3div[value[positionTonode[low]]];
        return ;
    }
    int mid = (low+high)>>1;
    build(low,mid,2*pos+1);
    build(mid+1,high,2*pos+2);
    st[pos] = st[2*pos+1] + st[2*pos+2];
}

int query(int qlow,int qhigh,int low,int high,int pos){
    if(low>qhigh || high<qlow)return 0;
    if(low>=qlow && high<=qhigh)return st[pos];
    int mid=(low+high)>>1;
    return query(qlow,qhigh,low,mid,2*pos+1) + query(qlow,qhigh,mid+1,high,2*pos+2);
}

void update(int qidx,int low,int high,int val,int pos){
    if(low>qidx || high<qidx)return ;
    if(low==high){
        st[pos] = val;
        return ;
    }
    int mid=(low+high)>>1;
    update(qidx,low,mid,val,2*pos+1);
    update(qidx,mid+1,high,val,2*pos+2);
    st[pos] = st[2*pos+1] + st[2*pos+2];
}

int main(){

    for(int i=1;i<MAX2;i++){
        int x = i%3 ;

        for(int j=i;j<MAX2;j+=i)
            mod3div[j] += x ;

        mod3div[i] = (mod3div[i]%3 == 0 );
    }

    int n,q,u,v,type;
    scanf("%d%d",&n,&q);
    itr = 0 ;

    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,-1);
    for(int i=1;i<=n;i++)scanf("%d",&value[i]);

    build(0,n-1,0);

    while(q--){
        scanf("%d",&type);
        if(type==1){
            scanf("%d%d",&u,&v);
            update(nodeToPosition[u],0,n-1,mod3div[v],0);
        }
        else{
            scanf("%d",&u);
            printf("%d\n",query(nodeToPosition[u],nodeToPosition[u]+size[u]-1,0,n-1,0));
        }
    }
}
