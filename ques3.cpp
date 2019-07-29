#include "bits/stdc++.h"
using namespace std;
const int MAX=1e6+9;
int dp[MAX];

int main(){
    
    dp[0]=1;
    
    for(int i=3;i<MAX;i+=3)
    dp[i]=dp[i-3];
    
    for(int i=5;i<MAX;i++)
    dp[i]+=dp[i-5];
    
    for(int i=10;i<MAX;i++)
    dp[i]+=dp[i-10];
    
    int tc,n;scanf("%d",&tc);
    
    while(tc--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    
    return 0;
}
