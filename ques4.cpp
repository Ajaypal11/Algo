/**
    ajay_pal_11
    30/7/19
    
    given an boolean array containing zero or one find maximum length of contingous
    sub array which have equal number of zero and one.
    
    find commulative count of zero and one. Let say we have at jth index count of one and 
    zero be (xj,yj) , at ith index count of one and zero be (xi,yi)....
    then we have count of one and zero in the sub array [i,i+1,i+2,....j]....
    {xj-xi,yj-yi},
    then we have count of zero and one equal 
    
        xj-xi = yj-yi
    =>  xj-yj = xi-yi 
    
    we store count of xi-yi at each point and add to our result
**/

#include "bits/stdc++.h"
using namespace std ;
using uint64 = long long int ;
const int MAX=1e6;
int arr[MAX];

int main(){
    
    int n;                      scanf("%d",&n);
    for(int i=0;i<n;i++)        scanf("%d",arr+i);
    
    int x=0,y=0;
    unordered_map<int,uint64>mp;
    uint64 res=0;
    mp[0]=1;

    for(int i=0;i<n;i++){
        if(arr[i])x++;else y++;
        res += mp[x-y] ;
        mp[x-y]++;
    }
    
    printf("%lld\n",res);
}
