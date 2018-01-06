#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
const int INF=0x3f3f3f3f;
struct edge
{
    int to,w;
};
vector<edge> G[maxn];
int n,m,s,t;
int dist[maxn];
bool vis[maxn];

int spfa(int s,int t)
{
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
            if (dist[u]+ww<dist[v])
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



void solve()
{
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
    }
    cout<<spfa(s,t)<<endl;
}

int main()
{
    while(scanf("%d%d%d%d",&n,&m,&s,&t)!=-1) solve();
    return 0;
}
