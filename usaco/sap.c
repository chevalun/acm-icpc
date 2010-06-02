#include <cstdio>
#include <cstring>
using namespace std;
const int V=220,E=220;

int n,m,h[V],vh[V];

struct etype
{
    int t,u;
    etype *next,*pair;
    etype(){}
    etype(int t_,int u_,etype* next_):t(t_),u(u_),next(next_){}
    void* operator new(unsigned,void* p){return p;}
} *e[V],*eb[V],Te[E+E],*Pe=Te;

int aug(int no,int m)
{
    if(no==n)return m;
    int l=m;
    for(etype *&i=e[no];i;i=i->next)if(i->u && h[i->t]+1==h[no])
    {
        int d=aug(i->t,l<i->u?l:i->u);
        i->u-=d,i->pair->u+=d,l-=d;
        if(h[1]==n || !l)return m-l;
    }
    int minh=n;
    for(etype *i=e[no]=eb[no];i;i=i->next)if(i->u)
        if(h[i->t]+1<minh)minh=h[i->t]+1;
    if(!--vh[h[no]])h[1]=n;else ++vh[h[no]=minh];
    return m-l;
}
    
int main()
{
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    scanf("%d %d",&m,&n);
    memset(e,0,sizeof(e));
    while(m--)
    {
        int s,t,u;
        scanf("%d %d %d",&s,&t,&u);
        e[s]=new(Pe++)etype(t,u,e[s]);
        e[t]=new(Pe++)etype(s,0,e[t]);
        e[s]->pair=e[t];
        e[t]->pair=e[s];
    }
    memmove(eb,e,sizeof(e));
    memset(h,0,sizeof(h));
    memset(vh,0,sizeof(vh));
    vh[0]=n;
    int ans=0;
    while(h[1]<n)ans+=aug(1,~0U>>1);
    printf("%d\n",ans);
    return 0;
}