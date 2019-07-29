/*
  author : ajay_pal_11 
  29/07/19
*/

#include<bits/stdc++.h>
using namespace std;

int f(int *a,int n){
    if(n<4)return -1;
    
    // find max a[j]-a[i]+a[l]-a[k];   i<j<k<l
    
    int left[n] ; left[0]=INT_MIN; // find max value of a[j]-a[i];
    int ai=a[0];
    
    for(int j=1;j<n;j++){
        left[j]=max(left[j-1],a[j]-ai);
        ai=min(ai,a[j]);
    }
    
    // 0 1 2 3 4 5 6 7 8
    
    int al=a[n-1],max_sum_al_minus_ak=INT_MIN;
    int result=INT_MIN;
    
    for(int k=n-2;k>=2;k--){
        max_sum_al_minus_ak=max(max_sum_al_minus_ak,al-a[k]);
        result=max(result,left[k-1]+max_sum_al_minus_ak);
        al=max(al,a[k]);
    }
    
    return result;
}

int main()
 {
	int t ;
    scanf("%d",&t) ;
    
        while(t--)
        {
          int n;scanf("%d",&n); int a[n];
          for(int i=0;i<n;i++)scanf("%d",a+i);
          
          printf("%d\n",f(a,n));
        }
	return 0;
}
