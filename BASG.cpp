/*
    ajay_pal_11
    18/9/19
    complexity => O(n) using prefix array and two pointer
*/

#include "bits/stdc++.h"
using namespace std ;
const int MAX = 600000;
char str[MAX] ;
int dp[4][MAX];
int get_index(int i){
    if(str[i-1]=='A')return 0;
    else if(str[i-1]=='C')return 1;
    else if(str[i-1]=='G')return 2;
    else return 3;
}
int main(){
    int n ; scanf("%d",&n);
    scanf("%s",str);
    
    int k = n/4 , a2 , b2 , c2 ,d2 , res=n , i=1 ;
    int k1,k2,k3,k4;
    
    for(int i=1;i<=n;i++){
        dp[get_index(i)][i]++;
        
        for(int j=0;j<4;j++)
        dp[j][i] += dp[j][i-1];
    }
    
    for(int j=1;j<=n;j++){
        a2 = dp[0][n]-dp[0][j];
        b2 = dp[1][n]-dp[1][j];
        c2 = dp[2][n]-dp[2][j];
        d2 = dp[3][n]-dp[3][j];
        
        if( a2>k || b2>k || c2>k || d2>k )continue ;
        
        k1 = k-a2;
        k2 = k-b2;
        k3 = k-c2;
        k4 = k-d2;
        
        while((i<=j) && (dp[0][i]<=k1 && dp[1][i]<=k2 && dp[2][i]<=k3 && dp[3][i]<=k4) )
        i++;
        
        res = min(res,j-i+1);
    }
    
    printf("%d\n",res);
    return 0;
}
