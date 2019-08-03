#include "bits/stdc++.h"
using namespace std ;

int f(string ch,int n,int k,char c){
    
    queue<pair<int,int>>q;
    int res=0,m=0;
    
    for(int i=0;ch[i];i++){
        
        if( ch[i] == c ){
            m++;
            
            if(q.size()<k)
            res=i+1;
            
            else
            res=max(res,i-q.front().first+q.front().second+1);
        }
        
        else{
            
            q.push({i,m});
            
            if(q.size()>k)
            q.pop();
            
            res = max( res , i-q.front().first+q.front().second+1);
            m=0;
        }
        
    }
    
    return res;
}

int main(){
    int n,k;                scanf("%d%d",&n,&k);
    string ch ; cin>>ch ;
    
    int res = max(  max( f(ch,n,k,'a') , f(ch,n,k,'b') ) , f(ch,n,k,'c')  );
    printf("%d\n",res);
}
