// https://cses.fi/problemset/task/1741/
#include <cstdio>
#include <algorithm>
const int maxN = 3e6;
int st[maxN][2],reduced[(int)3e5+100];
struct Events{
    int x,y1,y2,o;
    Events(int _x=0,int _y1=0,int _y2=0,int _o=0):x(_x),y1(_y1),y2(_y2),o(_o){}
    bool operator<(const Events&other)const{
        return (x<other.x||(x==other.x&&o<other.o));
    }
}events[(int)3e5+100];
void update(int ql,int qh,int v,int l,int h,int pos){
    if(h<=ql||l>=qh||l>=h)return;
    if(l>=ql&&h<=qh){
        st[pos][0]=(st[pos][1]+=v)?reduced[h]-reduced[l]:st[2*pos+1][0]+st[2*pos+2][0];
        return;
    }
    int m=(l+h)>>1;
    update(ql,qh,v,l,m,2*pos+1),update(ql,qh,v,m,h,2*pos+2);
    st[pos][0]=st[pos][1]?reduced[h]-reduced[l]:st[2*pos+1][0]+st[2*pos+2][0];
}
int main(){
    int n,x1,x2,y1,y2,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        events[2*i]=Events(x1,y1,y2,-1);
        events[2*i+1]=Events(x2,y1,y2,1);
        reduced[2*i]=y1,reduced[2*i+1]=y2;
    }
    std::sort(reduced,reduced+2*n);
    int m=std::unique(reduced,reduced+2*n)-reduced;
    for(int i=0;i<n;i++){
		events[2*i].y1=std::lower_bound(reduced,reduced+m,events[2*i].y1)-reduced;
		events[2*i].y2=std::lower_bound(reduced,reduced+m,events[2*i].y2)-reduced;
		events[2*i+1].y1=events[2*i].y1,events[2*i+1].y2=events[2*i].y2;
	}
    std::sort(events,events+2*n);
    long long ret=0;
    for(i=0,x1=events[0].x;i<2*n;i++){
        ret += 1LL*(events[i].x-x1)*st[0][0],x1=events[i].x;
        update(events[i].y1,events[i].y2,-events[i].o,0,m-1,0);
    }
    printf("%lld\n",ret);
}
