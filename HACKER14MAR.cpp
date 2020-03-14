/*
    ajay_pal_11
    14/3/2020
    https://www.hackerearth.com/challenges/competitive/data-structures-and-algorithms-march-2020/algorithm/unique-subsequence-264057c9/
 */


#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc , n , dp[26];
    string str ;
    cin>>tc;
    
    while (tc--){
        cin>>n;
        cin>>str;
        fill( dp , dp + 26 , 0 ) ;
        
        for(int i=0;i<n;i++){
            int c =  str[i] - 'a'  ;
            for(int j=0;j<26;j++){
                if( j!=c){
                    dp[c] = max( dp[c] , 1 + dp[j]);
                }
            }
        }
        
        for(int j=1;j<26;j++) dp[0] = max( dp[0] , dp[j]);
        cout<< dp[0] << endl ;
    }
}
