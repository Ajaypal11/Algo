/*
  ajay_pal_11
  10/9/19
  complexity : O(max*log(max)) => max => maximum element in an array
*/

#include "bits/stdc++.h"
using namespace std ;
const int MAX = 1e6+9 ;
int cnt[MAX] ;
int main() {

    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    int ans = 1 ;
    for(int i=1;i<MAX;i++){

        for(int j=2*i ; j<MAX; j+=i)
            cnt[i] += cnt[j] ;

        if(cnt[i]>1)ans = i;
    }
    printf("%d\n",ans);
}
