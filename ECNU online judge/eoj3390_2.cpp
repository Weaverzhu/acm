#include<iostream>
#include<cstdio>
#define maxn 1000000
#define INF 2000000000
using namespace std;
long long a[maxn],maxv[3*maxn],minv[3*maxn],sumv[3*maxn];
void build(int L,int R,int o)
{
    if(L==R)maxv[o]=minv[o]=sumv[o]=a[L];
    else
    {
        int m=L+(R-L)/2,lc=o<<1,rc=lc+1;
        build(L,m,lc);
        build(m+1,R,rc);
        maxv[o]=max(maxv[lc],maxv[rc]);
        minv[o]=min(minv[lc],minv[rc]);
        sumv[o]=sumv[lc]+sumv[rc];
    }
    return;
}
long long x,v;
void update(int L,int R,int o)
{
    if(L==R)maxv[o]=minv[o]=sumv[o]=v;
    else
    {
        int m=L+(R-L)/2,lc=o<<1,rc=lc+1;
        if(x<=m)update(L,m,lc);
        if(x>m)update(m+1,R,rc);
        maxv[o]=max(maxv[lc],maxv[rc]);
        minv[o]=min(minv[lc],minv[rc]);
        sumv[o]=sumv[lc]+sumv[rc];
    }
}
long long ql,qr,_max,_min,_sum;
void query(int L,int R,int o)
{
    if(ql<=L&&R<=qr)
    {
        _max=max(_max,maxv[o]);
        _min=min(_min,minv[o]);
        _sum+=sumv[o];
    }
    else 
    {
        int m=L+(R-L)/2,lc=o<<1,rc=lc+1;
        if(ql<=m)query(L,m,lc);
        if(qr>m)query(m+1,R,rc);
    }
    return;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int n,Q;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    build(1,n,1);
    scanf("%d",&Q);
    while(Q--)
    {
        int t;
        scanf("%d", &t);
        if(t==2)
        {
            _sum=0;
            _min=-1u>>1;
            _max=1<<31;
            scanf("%d%d",&ql,&qr);
            query(1,n,1);
            printf("%lld %lld %lld\n",_sum, _max, _min);
        }
        if(t==1)
        {
            scanf("%d%d",&x,&v);
            update(1,n,1);
        }
    }
}