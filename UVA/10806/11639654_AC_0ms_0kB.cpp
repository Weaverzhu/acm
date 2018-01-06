#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 105;
const int INF = 0x3f3f3f3f;
struct edge
{
	int to, cap, rev, flow, cost;
	edge(int t, int c, int r, int f, int co):
		to(t), cap(c), rev(r), flow(f), cost(co){};
};
class MinCostF{
public:
	int S, T, n, m, Cost, Flow;
	vector<edge> G[maxn];
	// void init(int n_, int m_);
	// void add(int from, int to, int cost, int cap);
	// void solve(int n_, int m_);
	// bool spfa(int s, int t);
	// int min_cost_flow(int s, int t);
	void add(int from, int to, int cost, int cap){
		edge newe = edge(to, cap, G[to].size(), 0, cost);
		G[from].pb(newe);
		newe = {from, 0, G[from].size()-1, 0, -cost};
		G[to].pb(newe);
	}
	void init(int n_, int m_){
		for (int i=0; i<=n_; ++i) G[i].clear();
		n = n_, m = m_;
		S = 1; T = n;
		Cost = 0; Flow = 0;
		int u, v, w;
		for (int i=0; i<m; ++i){
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w, 1); 
			add(v, u, w, 1);
		}
		
	}
	bool spfa(int s, int t){
		int prevv[maxn], preve[maxn], f[maxn], dist[maxn];
		bool vis[maxn];
		memset(dist, INF, sizeof(dist));
		memset(f, 0, sizeof(f));
		memset(vis, 0, sizeof(vis));

		queue<int> Q;
		Q.push(s); vis[s] = true;
		f[s] = INF; dist[s] = 0;

		
		while(!Q.empty()){
			int now = Q.front(); vis[now] = false; Q.pop();
			for (int j=0; j<G[now].size(); ++j){
				edge &e = G[now][j];
				int v = e.to;
				if (e.cap > e.flow && dist[v] > dist[now] + e.cost){
					dist[v] = dist[now]+e.cost;
					f[v] = min(f[now], e.cap-e.flow);
					prevv[v] = now; preve[v] = j;
					if (!vis[v]) Q.push(v);
				}
			}
		}
		// cerr << "shortest path found\n";
		cerr << "dist[t] = " << dist[t] << endl;
		// cerr << "f[t] = " << f[t] << endl;
		
		if (dist[t] == INF) return false;
		// cerr << "hello" << endl;
		Flow += f[t]; Cost += f[t]*dist[t];

		int now = t, last, newf = f[t];
		// cerr << "newf = " << newf << endl;
		// system("pause");
		while(now != s){
			last = prevv[now];
			edge &e = G[last][preve[now]];
			// cerr << "e = G " << last << " " << preve[now] << endl; 
			// cerr << "G[1][0].cap - G[1][0].flow = " << G[1][0].cap-G[1][0].flow << endl;
			e.flow += newf;
			
			G[now][e.rev].flow -= newf;
			// cerr << "G[1][0].cap - G[1][0].flow = " << G[1][0].cap-G[1][0].flow << endl;
			now = last;
		}
		return true;
	}
	int min_cost_flow(int s, int t){
		Flow = 0; Cost = 0;
		while(spfa(S, T)){
			if (Flow == 2) return Flow;
		}
		return Flow;
	}
	void solve(int n_, int m_){
		init(n_, m_);
		// cerr << "n,m = " << n << "," << m << endl;
		int flow = min_cost_flow(S, T);
		if (flow < 2) printf("Back to jail\n");
		else cout << Cost << endl;
	}



} mincostf;



int main(){
	// cerr << "hello\n";
	int t, n, m;
	while(scanf("%d", &n)!=-1){
		if (n == 0) break;
		scanf("%d", &m);
		// printf("n = %d m = %d\n", n, m);
		mincostf.solve(n, m);
	}
	return 0;
}