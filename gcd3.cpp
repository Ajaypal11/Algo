#include <bits/stdc++.h>
using int64 = long long int ;
using namespace std;
const int MAX = 1e5 + 9 ;
int arr[MAX];
int64 cnt[MAX] ;
int gcd(int x,int y){
    int t;
    while(x&&y){
        t=x%y;
        x=y;
        y=t;
    }
    return (x+y);
}
void solve(int n,int q){
    int mx=0,k;
    for(int i=1;i<=n;i++)cnt[arr[i]]++,mx=max(mx,arr[i]);
    for(int i=1;i<=mx;i++){
        for(int j=i+i;j<=mx;j+=i){
            cnt[i] += cnt[j] ;
        }
    }

    for(int i=mx;i;i--){
        cnt[i] = (1LL * cnt[i] * (cnt[i]+1))/2;
        for(int j=i+i;j<=mx;j+=i) cnt[i] -= cnt[j];
        //cout << i << " " << cnt[i] << endl;
    }
    while(q--){
        scanf("%d",&k);
        printf("%lld\n",cnt[k]);
    }
}
void bruteForce(int n,int q){
    int k;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            cnt[gcd(arr[i],arr[j])]++;

    while(q--){
        scanf("%d",&k);
        printf("%lld\n",cnt[k]);
    }
}
int main(){
    int n,q,k,mx=0;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",arr+i);
    //bruteForce(n,q);
    solve(n,q);
}
