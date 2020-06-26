/*
    ajay_pal_11
    improved
*/

#include <cstdio>
#include <map>
using namespace std;
#define int64 long long int
#define uint64 unsigned long long int
static constexpr int LIMIT = 1e7 + 9 ;
static constexpr uint64 add = -1 ;
int phi[LIMIT] , primes[LIMIT] , sp[LIMIT] , sz;
uint64 tsum[LIMIT];
map<int64,uint64> cache ;
uint64 handle(uint64 x,uint64 y){
    if(x>y)return x-y;
    uint64 ret = add-y ;
    ret += 1+x;
    return ret;
}
uint64 rangeSum(uint64 L,uint64 R){
    uint64 a,b;
    if(R%2) a = ((R+1)/2) * R ;
    else a = (R/2) * (R+1);
    if(L%2) b = ((L-1)/2) * L ;
    else b = (L/2) * (L-1);
    return handle(a,b);
}
uint64 LargeTotient(int64 N){
    if(N<LIMIT) return tsum[N];
    if(cache.count(N))return cache[N];
    uint64 agg=0 , cac , u , v , x = 2 ;
    while (x<=N){
        u = (N/x) ;
        v = N/u ;
        if( u<LIMIT )cac = tsum[u] ;
        else if(cache.count(u)) cac = cache[u] ;
        else cac = cache[u] = LargeTotient(u);
        agg += (v-x+1) * cac ;
        x = v + 1 ;
    }
    return cache[N] = handle(rangeSum(1,N),agg) ;
}
uint64 solve(int64 N){
    uint64 ret = 0 , val , u ;
    int64 x = 1;
    while (x<=N){
        u = N/x ;
        if( u < LIMIT ){
            val = tsum[u] ;
        }else if( cache.count(u) ){
            val = cache[u];
        }else{
            val = cache[u] = LargeTotient(u);
        }
        ret += val * rangeSum(x,N/u);
        x = (N/u) + 1 ;
    }
    return handle(ret,rangeSum(1,N));
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
    while (tc--){
        int64 N ;
        scanf("%lld",&N);
        printf("%llu\n",solve(N));
    }
}
