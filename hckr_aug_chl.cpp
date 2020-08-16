#include <bits/stdc++.h>
using namespace std;
#define int64 long long int
int64 dp[10][20];
int a[20];
int getDigit(int64 n){
	int l=0;
	while(n>0){
		a[l]=n%10;
		n/=10;
		++l;
	}
	return l-1;
}
int64 f(int64 n,int k){
	if(n==0)return 1;
	int d=getDigit(n);
	int64 ret=0;
	
	for(int i=0;i<=d;i++)ret+=dp[k][i];
	
	for(int i=d;i>=0;i--){
		if(i==0)return (ret+1+(a[i]/k)) ;
		for(int j=(i==d?k:0);j<a[i];j+=k){
			for(int l=1;l<=i;l++)ret+=dp[k][l];
		}
		if(a[i]%k)return ret;
	}
	return ret;
}
int64 solve(int64 l,int64 r,int k){
	return f(r,k)-f(l-1,k);
}
int main(){
	for(int d=1;d<=9;d++){
		int64 k=(9/d);
		dp[d][1]=1+k;
		int64 s=dp[d][1];
		for(int l=2;l<20;l++){
			dp[d][l] = 1LL*k*s;
			s+=dp[d][l];
		}
	}
		
	int tc,k;
	scanf("%d",&tc);
	while(tc--){
		int64 l,r;
		scanf("%lld%lld%d",&l,&r,&k);
		printf("%lld\n",solve(l,r,k));
	}
	return 0;
}
