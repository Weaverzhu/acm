#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
vector <int> G[maxn];
int n, m;
int col[maxn];
bool vis[maxn];
bool suc;
void dfs(int now)
{
	if (!suc) return;
	vis[now] = true;
	int sz = G[now].size();
	for (int e=0; e<sz; ++e)
	{
		int v = G[now][e];
		if (col[v] == col[now])
		{
			suc = false; return;
		}
		else if (col[v] == 0)
		{
			if (col[now] == 1) col[v] = 2;
			else col[v] = 1;
			dfs(v);
			if (!suc) return;
		}
	} 
}
void solve()
{
	for (int i=0; i<=n; ++i) G[i].clear();
	memset(vis, false, sizeof(vis));
	memset(col, 0, sizeof(col));
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	suc = true;
	for (int i=1; i<=n; ++i)
		if (col[i] == 0)
		{
			col[i] = 1;
			dfs(i);
		}
	if (suc) printf("Correct\n");
	else printf("Wrong\n");
}
int main()
{
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
