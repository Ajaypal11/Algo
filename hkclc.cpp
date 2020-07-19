/*
    ajay_pal_11
    complexity : O(n*log(n)^2)
    20/7/2020
*/
#include <cstdio>
#include <map>
#define int64 long long  int
#define pi std::pair<int,int>
const int maxN = 3e5+100;
pi edges[maxN];
int parent[maxN] , order[maxN];
std::map<int,int> T[maxN];
int64 ans[maxN];
void swap(int &x,int &y){int t=x;x=y,y=t;}
int io(){
    int n,c;
    while((c=getchar_unlocked())<'0');n=(c-'0');
    while((c=getchar_unlocked())>='0')n=10*n+(c-'0');
    return n;
}
int find(int p){
    if(p==parent[p])return p;
    return (parent[p]=find(parent[p]));
}
int64 unionTree(int u,int v){
    int64 ret=0;
    int a = find(u) , b = find(v);
    if( T[a].size() < T[b].size()) swap(a,b);
    parent[b]=a;
    for(auto &it : T[b]){
        int x = T[a][it.first];
        ret += 1LL * x * it.second;
        T[a][it.first] = x +  it.second;
    }
    T[b].clear();
    return ret;
}
int main(){
    int n = io();
    for(int i=1;i<n;i++) edges[i] =  pi(io(),io());
    for(int i=1;i<=n;i++)T[i][io()]=1,parent[i]=i;
    for(int i=1;i<n;i++)order[i]=io();
    for(int i=n-1;i>=1;i--)ans[i] = unionTree(edges[order[i]].first,edges[order[i]].second);
    for(int i=1;i<n;i++)printf("%lld\n",ans[i]);
    return 0 ;
}
