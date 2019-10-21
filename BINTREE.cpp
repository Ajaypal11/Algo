/*
  minimum distance two nodes in a complete binary tree
  ajay_pal_11
  22/10/19
  complexity : max bits in a num(n,m) - longest prefix match of bits
*/
#include "bits/stdc++.h"
using namespace std;
int main(){
    int tc,n,m;scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&m);
        int res=0;
        while(n!=m){
            if(n>m)n=n>>1;
            else m=m>>1;
            res++;
        }
        printf("%d\n",res);
    }
}
