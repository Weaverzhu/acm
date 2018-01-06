#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_V = 300010;
int n, m;
struct edge
{
	int to, cap, rev;
};
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

void add_edge(int from, int to, int cap)
{
	G[from].push_back((edge){to, cap, G[to].size()});
	G[to].push_back((edge){from, 0, G[from].size()-1});
}

void bfs(int s)
{
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while(!que.empty())
	{
		int v = que.front();que.pop();
		for (int i=0; i<G[v].size(); ++i)
		{
			edge &e = G[v][i];
			if (e.cap > 0 && level[e.to] < 0)
			{
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

int dfs(int v, int t, int f)
{
	if (v == t) return f;
	for (int &i=iter[v]; i<G[v].size(); ++i)
	{
		edge &e = G[v][i];
		if (e.cap>0 && level[v]<level[e.to])
		{
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0)
			{
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s, int t)
{
	int flow = 0;
	for(;;)
	{
		bfs(s);
		if (level[t] < 0) return flow;
		memset(iter, 0 ,sizeof(iter));
		int f;
		while((f = dfs(s, t, INF)) > 0) flow += f;
	}
}
const int maxn = 20000+20, maxm = 200000+20;
int A[maxn], B[maxn], a[maxm], b[maxm], w[maxm];
void solve(int n, int m)
{
    
    for (int i=0; i<n; ++i) scanf("%d%d", &A[i], &B[i]);
    for (int i=0; i<m; ++i) scanf("%d%d%d", &a[i], &b[i], &w[i]);
	int s=n, t=s+1;
	for (int i=0; i<n; ++i)
    {
        add_edge(i, t, A[i]);
        add_edge(s, i, B[i]);
    }
    for (int i=0; i<m; ++i)
    {
        add_edge(a[i]-1, b[i]-1, w[i]);
        add_edge(b[i]-1, a[i]-1, w[i]);
    }
	cout << max_flow(s, t) << endl;


}

int main()
{
	while(scanf("%d%d", &n, &m) != -1) solve(n, m);
	return 0;
}