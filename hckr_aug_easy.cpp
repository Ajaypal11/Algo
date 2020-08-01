/*
    ajay_pal_11
    Maximum bitwise pairs
    https://www.hackerearth.com/problem/algorithm/maximum-bitwise-pair-bb846052/?layout=old
*/
#include <cstdio>
const int maxN = 4e5 + 100;
int f[maxN],arr[maxN];
int mymax(const int&x,const int&y){return (x>=y?x:y);}
int main(){
    int tc,n;
    scanf("%d",&tc);
    while (tc--){
        scanf("%d",&n);
        int mb=32-__builtin_clz(n),mask=(1<<mb)-1;
        for(int i=0;i<mask;i++)f[i]=arr[i]= -(2e9+100);
        for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
        for(int j=1;j<=mask;j++){
            f[j]=arr[j];
            for(int l=0;l<mb;l++){
                if(j&(1<<l))f[j]=mymax(f[j],f[j^(1<<l)]);
            }
        }
        int q,index;
        scanf("%d",&q);
        while (q--){
            scanf("%d",&index);
            if( f[index ^ mask]<0 )puts("-1"); else printf("%d\n",f[index ^ mask]+arr[index]);
        }
    }
    return 0;
}
