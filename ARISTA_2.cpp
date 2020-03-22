/*
    given a string of length n , we find to find maximum length of consecutive one such that it can have have atmost one 
    zero .
*/
#include "bits/stdc++.h"
#define IOS ios_base::sync_with_stdio(0)
#define TIE cin.tie(0)
using namespace std;
const int MAX = 1e5 + 9 ;
char str[MAX] ;
int main(){

    IOS ;
    TIE ;
    int tc , n , prev , curr0 , curr1 , ret , j ;
    cin>>tc;
    while(tc--){
        cin>>n;
        cin>>str;
        ret = prev = j = 0 ;
        while(j<n){
            curr0 = curr1 = 0 ;
            while(j<n && str[j]=='0'){++j,++curr0;}
            while(j<n && str[j]=='1'){++j,++curr1;}
            if(curr0<=1) ret = max( ret , prev + curr0 + curr1);
            ret = max( ret , curr1 + !!curr0);
            ret = max( ret , prev  + !!curr0);
            prev = curr1 ;
        }
        cout << ret << endl ;
    }

}
