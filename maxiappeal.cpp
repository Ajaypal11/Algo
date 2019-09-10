/*
 *
    ajay_pal_11
    10/9/19
    complexity : O(n)
 * */

/*
given an array of n elements find maximum appeal of an array
appeal of an array = a[i] + a[j] + abs(i-j)
        */

#include "bits/stdc++.h"
using namespace std ;
int main(){
    int ans=-999999 , max_val = -9999999 ,x ;
    int n ; scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        ans = max(ans,x+i+max_val);
        max_val = max(max_val,x-i);
    }
    printf("%d",ans);
}
