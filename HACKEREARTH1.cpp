/*
    given string consisting of only '{' , '}' and every open bracket is close with two 2 '}' bracket.
    we need to insert minimum number of bracket to product balanced expression
  
    ajay_pal_11
    26/01/2020
    complexity : O(n)
*/
#include "bits/stdc++.h"
using namespace std;
int main(){
    string str = "{}}}}}}" ;
    int n = str.size(),i=0,ans=0,open=0;
    
    while(i<n){
        int close=0;
        while(i<n && str[i]=='{'){
            ++i;
            ++open;
        }
        while(i<n && str[i]=='}'){
            ++i;
            if(++close==2){
                if(open)--open;
                else ans++;
                close=0;
            }
        }
        
        if(close){
            ans++;
            if(open)open--;
            else ans++;
        }
    }
    ans += 2*open;
    cout<< ans << "\n" ;
}
