/*
  author : ajay_pal_11
  29/07/19
  
  Description : given an array with 3<=n<=10^6 elements , where each element   -10^6 <= a[i] <= 10^6 ,
  find maximum value of a[i]-a[j]+a[k] such that i<j<k.
  
  brute force => O(n^3) run three loops.
  Optimized  => O(n) maintain suffix array where each element will contain maximum value till j from n.
  
*/

#include "bits/stdc++.h"
using namespace std;

int main(){
    
    int n ; cin>>n;
    int max_suff[n],a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];    

    max_suff[n-1] = a[n-1];
    
    for(int i=n-2;i>=0;i--)
    max_suff[i] = max( a[i] , max_suff[i+1]);
    
    int max_so_far=a[0],result=INT_MIN ;
    
    for(int i=1;i<n-1;i++){
        result = max( result , max_so_far + max_suff[i+1] - a[i]);
        max_so_far = max( max_so_far , a[i]);
    }
    
    cout<<result<<endl;
    return 0;
}
