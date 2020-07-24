#include <cstdio>
#define int64 long long int
const int maxN = 1e5+9;
int64 st1[maxN][2],st2[maxN][3];
void pushDown(int low,int high,int pos,int t){
    int mid=(low+high)>>1,m=(high-low+1);
    if(t==1){
        if(st1[pos][0] && low!=high){
            st1[2*pos+1][0]+=st1[pos][0];
            st1[2*pos+2][0]+=st1[pos][0];
        }
        st1[pos][1] += 1LL * st1[pos][0] * m;
        st1[pos][0]=0;
    }else{
        if((st2[pos][0]||st2[pos][1]) && low!=high){
            st2[2*pos+1][0]+=st2[pos][0];
            st2[2*pos+1][1]+=st2[pos][1];
            st2[2*pos+2][0]+=st2[pos][0];
            st2[2*pos+2][1]+=st2[pos][1] + 1LL*(mid-low+1)*st2[pos][0];
        }
        st2[pos][2]+=st2[pos][1]+1LL*st2[pos][0]*(m*(m+1))/2;
        st2[pos][0] = st2[pos][1] = 0 ;
    }
}
void updateNode(int low,int high,int pos,int t){
    int mid=(low+high)>>1,m=(high-low+1);
    if(t==1){
        if(st1[pos][0])pushDown(low,high,pos,1);
        if(st1[2*pos+1][0])pushDown(low,mid,2*pos+1,1);
        if(st1[2*pos+2][0])pushDown(mid+1,high,2*pos+2,1);
        st1[pos][1] = st1[2*pos+1][0] + st1[2*pos+2][0];
    }else{
        if(st2[pos][0])pushDown(low,high,pos,2);
        if(st2[2*pos+1][0])pushDown(low,mid,2*pos+1,2);
        if(st2[2*pos+2][0])pushDown(mid+1,high,2*pos+2,2);
        st1[pos][1] = st1[2*pos+1][0] + st1[2*pos+2][0];
    }
}
void update(int ql,int qh,int64 a,int low,int high,int pos,int t,int sign){
    if(low>qh || high<ql)return;
    if(low>=ql && high<=qh){
        if(t==1)st1[pos][0]+=sign;
        else st2[pos][1]+=a,st2[pos][0]+=sign;
        return;
    }
    int mid=(low+high)>>1;
    pushDown(low,high,pos,t);
    update(ql,qh,a,low,mid,2*pos+1,t,sign);
    update(ql,qh,(mid-ql+1)*sign,mid+1,high,2*pos+2,t,sign);
    updateNode(low,high,pos,t);
}
int64 query(int ql,int qh,int low,int high,int pos,int t){
    if(low>qh || high<ql)return 0;
    pushDown(low,high,pos,t);
    if(low>=ql && high<=qh)return t==1?st1[pos][1]:st2[pos][2];
    int mid=(low+high)>>1;
    int64 lson = query(ql,qh,low,mid,2*pos+1,t),rson=query(ql,qh,mid+1,high,2*pos+2,t);
    updateNode(low,high,pos,t);
    return (lson+rson);
}
int main(){
    int n , q ;
    scanf("%d%d",&n,&q);
    while (q--){
        int type , l , r ;
        scanf("%d%d%d",&type,&l,&r);
        update(l,r,0,0,n,0,type,1);
    }

    for(int i=0;i<=n;i++){
        printf("%d %lld\n",i,query(i,i,0,n,0,1)+query(i,i,0,n,0,2));
    }
}
