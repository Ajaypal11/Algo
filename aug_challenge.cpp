#include <bits/stdc++.h>
#define int64 long long int
using namespace std;
const int maxN=150;
int main(){
    int64 k;
    cin >> k ;
    vector<pair<int,int>> g;
    for(int i=2;i<=maxN;i++){
        g.push_back(make_pair(i-1,i));
    }

    if(k>1){
        int b = 63 - __builtin_clzll(k);
        int start = maxN-10 , c = b ;
        while (c--){
            g.push_back(make_pair(start-2,start));
            start-=2;
        }
        start = maxN-10 - 2 * (b-1);
        c = b-1;
        while (~c){
            if(k&(1LL<<c)){
                g.push_back(make_pair(start+2*c-1,maxN));
            }
            --c;
        }
    }

    assert((int)g.size() <= 400);
    cout << maxN << " " << (int)g.size() << endl;
    for(pair<int,int> &edge : g)cout << edge.first <<" " << edge.second << endl ;
}
