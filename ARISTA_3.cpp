/*
    given matrix of size n * m , find sub matrix of size k * k containing maximum number of *
 */
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n , m , k ;
    cin>>n>>m>>k ;

    char mat[n][m] ;
    int dp[n+1][m+1] ;
    for(int i=0;i<=n;i++) dp[i][0] = 0 ;
    for(int j=0;j<=m;j++) dp[0][j] = 0 ;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i+1][j] = dp[i][j+1] + mat[i][j] == '*' ;
        }
    }

    int ret = 0 ;
    for(int i=k;i<=n;i++){
        int sum = 0;
        for(int j=1;j<=m;j++){
            sum += dp[i][j] - dp[i-k][j] ;
            if(j<=k){
                ret = max( ret , sum  ) ;
                sum -= ( dp[i][j-k+1] - dp[i-k][j-k+1] ) ;
            }
        }
    }

    cout << ret << endl ;
}
