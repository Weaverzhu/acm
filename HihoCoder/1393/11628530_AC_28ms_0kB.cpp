#include<bits/stdc++.h>
using namespace std;
const int maxn = 310;
#define pb push_back
const int INF = 0x3f3f3f3f;

class edge{
public:
	int to, cap, rev;
};
class Dinic{
public:
	int n, m, S, T, target;
	vector<edge> G[maxn];
	int level[maxn], iter[maxn];

	
	void add2(int from, int to, int cap){
		edge newe = {to, cap, G[to].size()};
		G[from].pb(newe);
		newe = {from, 0, G[from].size()-1};
		G[to].pb(newe);
	}
	void bfs(int s){
		memset(level, -1, sizeof(level));
		queue<int> que;
		level[s] = 0;
		que.push(s);
		while(!que.empty()){
			int v = que.front(); que.pop();
			for (int i=0; i<G[v].size(); ++i){
				edge &e = G[v][i];
				if (e.cap > 0 && level[e.to] < 0){
					level[e.to] = level[v] + 1;
					que.push(e.to);
				}

			}
		}
	}
	int dfs(int v, int t, int f){
		if (v == t) return f;
		for (int &i = iter[v]; i < G[v].size(); ++i){
			edge &e = G[v][i];
			if (e.cap > 0 && level[v] < level[e.to]){
				int d = dfs(e.to, t, min(f, e.cap));
				if (d){
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	int max_flow(int s, int t){
		int flow = 0;
		while(1){
			bfs(s);
			if (level[t] < 0) return flow;
			memset(iter, 0, sizeof(iter));
			int f;
			while((f = dfs(S, T, INF)) > 0){
				flow += f;
			}
		}
	}
	void init(int n_, int m_){
		for (int i=0; i<maxn; ++i)
			G[i].clear();
		target = 0;
		n = n_, m = m_;
		S = 0, T = n+m+1;
		int x;
		for  (int i=n+1; i<=n+m; ++i){
			scanf("%d", &x);
			target += x;
			add2(i, T, x);
		}
		int a, b;
		for (int i=1; i<=n; ++i){
			scanf("%d%d", &a, &b);
			add2(S, i, a);
			for (int j=1; j<=b; ++j){
				scanf("%d", &x);
				x += n;
				add2(i, x, 1);
			}
		}
	}
	void solve(int n, int m){
		init(n, m);
		int f = max_flow(S, T);
		if (f < target) printf("No\n");
		else printf("Yes\n");
	}

} dinic;


int main(){
	// freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		scanf("%d%d", &n, &m);
		dinic.solve(n, m);
	}
	return 0;
}