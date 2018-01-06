#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 10000
#define inf 1ll<<60
#define mod 100001
#define maxm 500000
int n,m;
int level[maxn],que[maxn];
int head[maxn],lon;
__int64 min(__int64 a,__int64 b)
{
    if(a<b) return a;
    else return b;
}
struct EDGE
{
    int next,to;
    __int64 c;
}e[maxm];
void edgeini()
{
    memset(head,-1,sizeof(head));
    lon=-1;
}
void edgemake(int from,int to,__int64 c)
{
    e[++lon].c=c;
    e[lon].to=to;
    e[lon].next=head[from];
    head[from]=lon;
}
void make(int from,int to,__int64 c)
{
    edgemake(from,to,c);
    edgemake(to,from,0);
}

bool makelevel(int s,int t)
{
    memset(level,0,sizeof(level));
    int front=1,end=0;
    que[++end]=s;
    level[s]=1;
    while(front<=end)
    {
        int u=que[front++];
        if(u==t) return true;
        for(int k=head[u];k!=-1;k=e[k].next)
        {
            int v=e[k].to;
            if(!level[v]&&e[k].c)
            {
                que[++end]=v;
                level[v]=level[u]+1;
            }
        }
    }
    return false;
}

__int64 dfs(int now,int t,__int64 maxf)
{
    if(now==t||maxf==0) return maxf;
    __int64 ret=0;
    for(int k=head[now];k!=-1;k=e[k].next)
    {
        int u=e[k].to;
        if(level[u]==level[now]+1&&e[k].c)
        {
            __int64 f=dfs(u,t,min(e[k].c,maxf-ret));
            e[k].c-=f;
            e[k^1].c+=f;
            ret+=f;
            if(ret==maxf) return ret;
        }
    }
    if(ret==0) level[now]=0;
    return ret;
}

__int64 maxflow(int s,int t)
{
    __int64 ret=0;
    while(makelevel(s,t))
    {
        ret+=dfs(s,t,inf);
    }
    return ret;
}

int main()
{
    int cas;
    int sum=0;
    scanf("%d",&cas);
    while(cas--)
    {
        sum++;
        int i;
        int u,v;
        int s, t;
        __int64 w;
        scanf("%d%d",&n,&m);
        scanf("%d %d", &s, &t);
        edgeini();
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%I64d",&u,&v,&w);
            make(u-1,v-1,w*mod+1);
        }
        printf("%I64d\n",maxflow(s-1,t-1)%mod);
    }
}
