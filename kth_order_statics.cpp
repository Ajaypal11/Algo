/*
    ajay_pal_11
    9/11/19
    complexity : O(log) per operation add / query
*/
#include "bits/stdc++.h"
using namespace std;
struct tree{
    int data,nc,lc,rc,h;
    tree *left,*right;
};
int readInt() {
  int c, n=0;
  while ((c = getchar()) < '0');
  n = c - '0';
  while ((c = getchar()) >= '0') n = n * 10 + (c - '0') ;
  return n;
}
tree *getNode(int data){
    tree *node = new tree ;
    node->data = data ;
    node->left = node->right = NULL ;
    node->nc = node->h = 1 ;
    node->lc = node->rc = 0 ;
    return node ;
}
int H(tree *node){
    if(!node)return 0;
    return node->h;
}
int getCnt(tree *node){
    if(!node)return 0;
    return node->nc + node->lc + node->rc ;
}
void updateNode(tree *node){
    node->lc = getCnt(node->left);
    node->rc = getCnt(node->right);
}
tree *leftRotation(tree *node){
    tree *x = node->right ;
    tree *t2 = x->left ;
    
    node->right = t2 ;
    x->left = node; 
    
    updateNode(node);
    updateNode(x);
    
    node->h = 1 + max(H(node->left),H(node->right));
    x->h = 1 + max(H(x->left),H(x->right));
    return x;
}
tree *rightRotation(tree *node){
    tree *x = node->left ;
    tree *t2 = x->right ;
    
    node->left = t2 ;
    x->right = node; 
    
    updateNode(node);
    updateNode(x);
    
    node->h = 1 + max(H(node->left),H(node->right));
    x->h = 1 + max(H(x->left),H(x->right));
    return x;
}
tree *insert(tree *node,int data){
    if(!node)return getNode(data);
    else if(node->data==data){node->nc++;return node;}
    else if(node->data>data)node->left = insert(node->left,data);
    else node->right = insert(node->right,data);
    
    node->h = 1 + max(H(node->left),H(node->right));
    int b = H(node->left)-H(node->right);
    
    if(b>1){
        if(node->left->data<data)node->left = leftRotation(node->left);
        return rightRotation(node);
    }
    if(b<-1){
        if(node->right->data>data)node->right = rightRotation(node->right);
        return leftRotation(node);
    }
    
    updateNode(node);
    return node;
}
tree *deleteTree(tree *node){
    if(!node)return node;
    node->left = deleteTree(node->left);
    node->right = deleteTree(node->right);
    delete(node);
    node = NULL;
    return NULL ;
}
int query(tree *root,int k){
    int cnt=0;
    int ans=0;
    tree *node = root ;
    while(node){
        if(cnt+node->lc+node->nc >= k){
            ans = node->data;
            node = node->left;
        }else{
            cnt += node->lc + node->nc ;
            node = node->right ;
        }
    }
    return ans;
}
int main(){
    int tc=readInt(),n,x,y;
    double d;
    while(tc--){
        n = readInt();
        tree *node = NULL ;
        for(int i=1;i<=n;i++){
            x = readInt();
            node = insert(node,x);
            if(i&1){
                printf("%d\n",query(node,(i+1)/2));
            }else{
                d = query(node,i/2) + query(node,1+(i/2));
                d = d/2.0 ;
                cout<<d<<"\n";
            }
        }
        deleteTree(node);
    }
    return 0;
}
