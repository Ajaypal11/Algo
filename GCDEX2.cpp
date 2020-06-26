/*
    ajay_pal_11
    sub-linear algo start
    need to improve a lot 
*/

#include <cstdio>
#include <map>
#include <cmath>
using namespace std;
#define int64 long long int
#define uint64 unsigned long long int
static constexpr int LIMIT = 1e7 + 9 , mod = 1e9+7 ;
int phi[LIMIT] , primes[LIMIT] , sp[LIMIT] , sz;
int64 tsum[LIMIT];
map<int64,uint64> cache ;
uint64 rangeSum(int64 L,int64 R){
    uint64 ret = 1ULL * (R * (R+1)) - 1ULL * (L * (L-1));
    return (ret/2);
}
uint64 smallN(int N){
    int64 ret = 0 ;
    for(int d=1;d<=N;d++){
        ret += tsum[d] * (  (N/d) - (N/(d+1)));
    }
    return ret;
}
int64 LargeTotient(int64 N){

    if(N<LIMIT) return tsum[N];
    if(cache.count(N))return cache[N];
    uint64 ret = rangeSum(1,N) ;
    int64 u,v;
    int nsqrt = sqrt(N) , ymax = nsqrt;
    if( nsqrt == int(N/nsqrt))--ymax;
    for(int x=2;x<=nsqrt;x++) {
        v = N/x;
        u = cache[v] = LargeTotient(v);
        ret -= u ;
    }
    for(int y=1;y<=ymax;y++)ret -= 1ULL * ( (N/y) - (N/(y+1))) * tsum[y] ;
    return cache[N] = ret ;
}
uint64 solve(int64 N){
    uint64 ret = 0 ;
    int64 x = 1 , u , val ;
    while (x<=N){
        u = N/x ;
        if( u < LIMIT ){
            val = tsum[u] ;
        }else if( cache.count(u) ){
            val = cache[u];
        }else{
            val = cache[u] = LargeTotient(u);
        }
        ret += 1ULL * val * rangeSum(x,N/u);
        x = (N/u) + 1 ;
    }
    return ret - (N * (N+1))/2 ;
}
int main(){
    phi[1] = sp[1] = tsum[1] = 1 ;
    for(int i=2;i<LIMIT;i++){
        if(!sp[i]){sp[i]=i;primes[sz++]=i;}
        for(int j=0;j<sz && 1LL * i * primes[j]<LIMIT;j++){
            sp[i * primes[j]] = primes[j] ;
            if(i%primes[j]==0)break;
        }
        if(sp[i]==i) phi[i]=i-1;
        else if( sp[i/sp[i]] != sp[i]) phi[i] = phi[sp[i]] * phi[i/sp[i]];
        else phi[i] = phi[i/sp[i]] * sp[i] ;
        tsum[i] = tsum[i-1] + phi[i] ;
    }

    int tc;
    scanf("%d",&tc);
    clock_t start = clock();
    while (tc--){
        int64 N ;
        scanf("%lld",&N);
        printf("%llu\n",solve(N));
    }
    printf("%ld",(clock()-start)/CLOCKS_PER_SEC);
}
