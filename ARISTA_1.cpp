/*
 
 given tree with n nodes where each node is assign with some character value . we need to output number of subtree in which 
 parent node doesnt have value in this subtree
 */
#include "bits/stdc++.h"
#define IOS ios_base::sync_with_stdio(0)
#define TIE cin.tie(0)
using namespace std;
const int MAX = 1e5 + 9 ;
bool visited[MAX] ;
char str[MAX] ;
vector<int> graph[MAX] ;
int ret ;
int f(char c){return (c-'a');}
void __init_(int n){
    for(int i=0;i<=n;i++){
        graph[i].clear();
        visited[i] = false ;
    }
}
int dfs(int node){
    visited[node] = 1 ;
    int mask = 0 , d = f(str[node-1]) ;
    for( int &child : graph[node]){
        if(!visited[child]) mask |= dfs(child);
    }
    ret += ( mask & d ? 0 : 1 ) ;
    return( mask |= d );
}
int main(){

    IOS ;
    TIE ;

    int tc,n,u,v;
    cin>>tc;

    while (tc--){
        cin>>n ;
        cin>>str;
        ret = 0 ;
        for(int i=1;i<n;i++){
            cin>> u >> v ;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }

        dfs(1);
        printf("%d\n",ret);
    }
    return 0 ;
}
