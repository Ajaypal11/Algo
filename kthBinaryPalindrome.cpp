#include <bits/stdc++.h>
using namespace std;
int main(){
    int k=0,n,mask,l,r,j;
    cin>>n;
    while(n>(1<<(k>>1)))n-=(1<<((k>>1))),++k;
    mask=(1<<k)|1,--n,++k,l=(k-1)>>1,r=l+((k-1)&1);
    for(j=0;j<32;j++){
        if((n>>j)&1){
            mask|=(1<<l)|(1<<r);
        }
        --l,++r;
    }
    cout<<mask<<endl;
}
