#include <bits/stdc++.h>
using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;


const int mxn=1e8+10,mxu=1<<15;
int a[mxn],b[mxn],e[mxn],c[1<<15];


void count_sort(int n){ // assuming numbers are 30 bits atmost 
    
    // sort last 15 bits 
    for(int i=1;i<=n;++i)c[a[i]&(mxu-1)]++;
    for(int i=1;i<mxu;++i)c[i]+=c[i-1];
    for(int i=n;i;--i)b[c[a[i]&(mxu-1)]--]=a[i];
    
    for(int i=1;i<mxu;++i)c[i]=0;
    
    // sort remaining bits
    for(int i=1;i<=n;++i)c[b[i]>>15]++;
    for(int i=1;i<mxu;++i)c[i]+=c[i-1];
    for(int i=n;i;--i)a[c[b[i]>>15]--]=b[i];

    assert(is_sorted(a+1,a+n+1));
}

long double bench_mark_count_sort(const int &n){
    auto t1 = high_resolution_clock::now();
    count_sort(n);
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    return ms_double.count();
}

long double bench_mark_stl_sort(const int &n){
    auto t1 = high_resolution_clock::now();
    sort(e+1,e+n+1);
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    return ms_double.count() ;
}

int main(){
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 rng(seed);
    const int mxb = (1<<30);
    
    int inp;
    std::cin >> inp ;
    for(int i=1;i<=inp;++i)e[i] = a[i] = rng() % mxb ;
    auto t1 = bench_mark_count_sort(inp);
    auto t2 = bench_mark_stl_sort(inp);
    std::cout << "count sort = " << t1 << "ms\n" ;
    std::cout << "stl sort   = " << t2 << "ms\n" ;
    
}
