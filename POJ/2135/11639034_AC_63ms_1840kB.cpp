#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1005;
#define pb push_back
const int INF = 0x3f3f3f3f;
struct edge
{
	int to, cap, rev, cost, flow;
};
class MinCostF{
public:
	int n, m, S, T, Cost, Flow;
	int preve[maxn], prevv[maxn];
	
	vector<edge> G[maxn];
	void add(int from, int to, int cost, int cap){
		edge newe = {to, cap, G[to].size(), cost};
		G[from].pb(newe);
		newe = {from, 0, G[from].size()-1, -cost};
		G[to].pb(newe);
		Cost = 0; Flow = 0;
	}
	void init(int n_, int m_){
		n = n_; m = m_;
		S = 0, T = n+1;
		for (int i=0; i<m; ++i){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w, 1); add(v, u, w, 1);
		}
		add(S, 1, 0, 2); add(n, T, 0, 2);
	}
	bool spfa(int s, int t){
		int dist[maxn], f[maxn];
		bool vis[maxn];
		memset(dist, INF, sizeof(dist));
		memset(vis, 0, sizeof(vis));
		memset(f, 0, sizeof(f));
		dist[s] = 0; f[s] = INF;
		queue<int> Q;
		Q.push(s); vis[s] = true;
		while(!Q.empty()){
			int now = Q.front(); Q.pop(); vis[now] = false;
			for (int j=0; j<G[now].size(); ++j){
				edge &e = G[now][j];
				int v = e.to, cost = e.cost;
				if (e.cap > e.flow && dist[now]+cost < dist[v]){
					f[v] = min(f[now], e.cap - e.flow);
					dist[v] = dist[now]+cost;
					prevv[v] = now;
					preve[v] = j;
					if (!vis[v]) Q.push(v);
				}
			}
		}
		if (dist[t] == INF) return false;
		Flow += f[t]; Cost += f[t]*dist[t];
		int now = t, last, newf = f[t];
		while(now != s){
			int last = prevv[now];
			edge &e = G[last][preve[now]];
			e.flow += newf;
			G[e.to][e.rev].flow -= newf;
			now = last;
		}
		return true;

		
	}
	int min_cost_flow(int s, int t){
		while(spfa(s, t));
		return Cost;
	}
	void solve(int n_, int m_){
		init(n_, m_);
		printf("%d\n", min_cost_flow(S, T));
		return;
	}
} mincostf;

int main(){
	int n, m;
	while(~scanf("%d%d", &n, &m))
		mincostf.solve(n, m);
	return 0;
}