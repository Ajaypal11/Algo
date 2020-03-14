/*
    ajay_pal_11
    14/3/2020
    https://www.hackerearth.com/challenges/competitive/data-structures-and-algorithms-march-2020/algorithm/jump-and-achieve-1-4588741c/
 */


#include "bits/stdc++.h"
using namespace std;
using int64 = long long int ;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc ;
    cin>>tc;

    while (tc--){
        int64 x,y;
        cin>>x>>y;

        while( !(x&1) ) x>>=1;
        while( !(y&1) ) y>>=1;

        while(x){
            int64 temp = y%x ;
            y = x ;
            x = temp ;
        }

        puts(y>1?"No":"Yes");
    }
}
