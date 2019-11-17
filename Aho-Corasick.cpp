/*
  ajay_pal_11
  18/11/19
  aho-corasick
*/

#include "bits/stdc++.h"
using namespace std;
const int ALPHABET_SIZE = 26 ;
string str[] = {"hers"} ;

struct Vertex{
    int next[ALPHABET_SIZE];
    int go[ALPHABET_SIZE];
    bool leaf = false ;
    int p = -1 ;
    int link = -1 ;
    char pch ;
    int index = -1 ; 
    
    Vertex(int p=-1 , char ch = '$'): p(p) , pch(ch) {
        fill( begin(next) , end(next) , -1 ) ;
        fill( begin(go) , end(go) , -1 ) ;
    }
};

vector<Vertex> t(1);
void add_string(string s,int index){
    int v = 0 ;

    for(char ch : s){
        int c = ch - 'a';
        if( t[v].next[c] == -1 ){
            t[v].next[c] = t.size();
            t.emplace_back(v,ch);
        }
        v = t[v].next[c];
    }
    t[v].index = index ;
    t[v].leaf=true;
}

int go(int v,char ch);
int get_link(int v){
    if( t[v].link == -1 ){
        if( v==0 || t[v].p == 0 )t[v].link = 0 ;
        else t[v].link = go( get_link(t[v].p) , t[v].pch );
    }
    return t[v].link ;
}
int go(int v,char ch){
    int c = ch-'a';
    if( t[v].go[c] == -1 ){
        if( t[v].next[c] != -1 )t[v].go[c] = t[v].next[c];
        else t[v].go[c] = !v ? 0 : go( get_link(v),ch ) ;
    }
    return t[v].go[c];
}
void match(string s){
    int v = 0 ;

    for(char ch:s){
        v = go(v,ch);
        if( t[v].leaf )cout<<str[t[v].index]<<"\n";
    }
}
int main(){
    int index = 0;
    for( string s : str ) add_string(s,index),++index;
    match( "shishershineshhersquit" ) ;
}
