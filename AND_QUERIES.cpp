#include <cstdio>
#define int64 long long int
const int maxB = 8 , maxN = 1<<maxB , maxS = 1e5+10 , mod = 1e9+7 ;
int arr[maxN] ;
int64 p1[maxN+1];
int cnt[maxS][maxN] ;
void walsh_hadamard_transfer(int64 *coeff,int n,int invert){
    for(int len=1;2*len<=n;len<<=1){
        for(int i=0;i<n;i+=2*len){
            for(int j=0;j<len;j++){
                int64 u=coeff[i+j],v=coeff[i+j+len];
                coeff[i+j]=u+invert*v,coeff[i+j+len]=v;
            }
        }
    }
}
int main(){
    int n , q , L , R , X ;
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);
        for(int j=0;j<maxN;j++)cnt[i][j]=cnt[i-1][j];
        cnt[i][x]++;
    }
    scanf("%d",&q);
    while (q--){
        scanf("%d%d%d",&L,&R,&X);
        for(int i=0;i<maxN;i++)p1[i]=cnt[R][i]-cnt[L-1][i];
        walsh_hadamard_transfer(p1,maxN,1);
        for(int i=0;i<maxN;i++)p1[i]=p1[i] * p1[i] * p1[i] ;
        walsh_hadamard_transfer(p1,maxN,-1);
        printf("%lld\n",p1[X]%mod);
    }
    return 0 ;
}
