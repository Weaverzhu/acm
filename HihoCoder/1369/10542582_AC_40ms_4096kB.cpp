
#include<cstring>
#include<iostream>
using namespace std;
const int INF = 1 << 30;
const int maxn = 500 + 10;
const int maxm = 2e4 + 10;
struct edge {
	int c, f,k,cf;
};
edge g[maxn][maxn];
int maxFlow, delta;
int S, T,flow;
int queue[maxn], path[maxn], capacity[maxn], tail;
bool vis[maxn];
int min(int a, int b) {
	return a > b ? b : a;
}
bool findaugmentpath() {
	memset(queue, 0, sizeof(queue));
	memset(path, 0, sizeof(path));
	memset(capacity, 0, sizeof(capacity));
	memset(vis, false, sizeof(vis));
	tail = 0;
	queue[tail] = S;
	capacity[S] = INF;
	vis[S] = true;
	int i = 0,u;
	while (i <= tail) {
		u = queue[i];
		if (u == T) {
			return capacity[T];
		}
		for (int e = 1; e <= g[u][0].k; ++e) {
			int v = g[u][e].k;
			if (!vis[v] && g[u][v].cf > 0) {
				path[v] = u;
				capacity[v] = min(g[u][v].cf, capacity[u]);
				vis[v] = true;
				++tail;
				queue[tail] = v;

			}
		}
		++i;
	}
	return false;
}
void modifyGraph() {
	flow = capacity[T];
	int now = T;
	while (now != S) {
		int fa = path[now];
		g[fa][now].cf -= flow;
		g[now][fa].cf += flow;
		now = fa;
	}

}
void ford_fulkerson() {
	while (findaugmentpath()) {
		maxFlow = maxFlow + capacity[T];
		modifyGraph();
	}
	return;

}
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m) {
		memset(g, 0, sizeof(g));
		S = 1; T = n;
		for (int i = 1; i <= m; ++i) {
			int u, v, k;
			
			cin >> u >> v >> k;
			g[u][0].k++;
			g[u][ g[u][0].k ].k=v;
			g[u][v].cf += k;
		}
		ford_fulkerson();
		cout << maxFlow << endl;
	}

    return 0;
}

