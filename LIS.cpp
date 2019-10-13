/*
  ajay_pal_11
  13/10/19
  complexity : O(n*log(n))
*/

#include "bits/stdc++.h"
using namespace std;
{
	int t,x,n;
    scanf("%d",&t) ;
    
        while(t--)
        {
            scanf("%d",&n);
            set<int>mp;
            set<int>::iterator it ;
            for(int i=0;i<n;i++){
                scanf("%d",&x);
                it=mp.lower_bound(x);
                
                if(it!=mp.end())mp.erase(it);
                
                mp.insert(x);
            }
            
            printf("%d\n",(int)mp.size());
        }
	return 0;
}
