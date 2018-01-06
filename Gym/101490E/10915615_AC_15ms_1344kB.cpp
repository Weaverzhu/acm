#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
const int maxm=1e5+10;
const int INF=0x3f3f3f3f;
struct edge
{
    int to,w;
};
vector<edge> G[maxn];
int n,m,s,t,x;
int dist[maxn];
bool vis[maxn];

int spfa(int s,int t,int mm)
{
	if (s==t) return 0;
    memset(vis,false,sizeof(vis));
    memset(dist,INF,sizeof(dist));
    dist[s]=0;
    queue<int> Q;
    while(!Q.empty()) Q.pop();
    Q.push(s);vis[s]=true;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();vis[u]=false;
        for (int e=1;e<=G[u][0].to;++e)
        {
            int v=G[u][e].to,ww=G[u][e].w;
            int tmp=dist[v];
            if (dist[u]+ww<dist[v]&&ww<=mm)
            {
                dist[v]=dist[u]+ww;
                if (!vis[v])
                {
                    Q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    return dist[t];
}
struct edge2
{
	int f,t,w;
};
edge2 ee[maxm];
bool cmp(edge2 a, edge2 b)
{
	return a.w<b.w;
}

void solve()
{
	s=1;t=n;
    for (int i=1;i<=n;++i)
    {
        G[i].resize(1);
        G[i][0].to=0;
    }
    for (int i=1;i<=m;++i)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        ++G[u][0].to;
        G[u].push_back((edge){v,w});
        ++G[v][0].to;
        G[v].push_back((edge){u,w});
        ee[i].f=u;ee[i].t=v;ee[i].w=w;
    }
    int sp=spfa(1,n,INF);
    double mp=1.0*sp*(x+100)/100;
    
    sort(ee+1,ee+m+1,cmp);
    int l=1,r=n,mid;
    int ans1=INF;
    while(l<r)
    {
    	mid=(l+r)/2;
    	int mam=ee[mid].w,t1=ee[mid].f,t2=ee[mid].t;
    	int tmp1=spfa(s,t1,mam),tmp2=dist[t2];
    	long long ans=0;
    	if (tmp1<tmp2)
    	{
    		ans=tmp1+mam+spfa(t2,t,mam);
		}
		else ans=tmp2+mam+spfa(t1,t,mam);
		if (ans<=mp)
		{
			r=mid-1;
			ans1=min(1LL*ee[mid].w,ans);
		}else l=mid+1;
	}
	cout<<ee[mid].w<<endl;
}

int main()
{
    while(scanf("%d%d%d",&n,&m,&x)!=-1) solve();
    return 0;
}