#include<bits/stdc++.h>
using namespace std;
const int MAX_V = 2*1000 + 10;

int V;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
int ctn[MAX_V][MAX_V];



bool used[MAX_V];
int cmp[MAX_V];

vector<int> col[MAX_V], row[MAX_V];

void add_edge(int from, int to)
{
	G[from].push_back(to);
	rG[to].push_back(from);
}
void dfs(int v)
{
	used[v] = true;
	for (int i=0; i<G[v].size(); ++i)
	{
		if (!used[G[v][i]]) dfs(G[v][i]);
	}
	vs.push_back(v);
}
void rdfs(int v, int k)
{
	used[v] = true;
	cmp[v] = k;
	for (int i=0; i<rG[v].size(); ++i)
	{
		if (!used[rG[v][i]]) rdfs(rG[v][i], k);
	}
}

int scc()
{
	memset(used, 0, sizeof(used));
	vs.clear();
	for (int v=0; v<V; ++v)
	{
		if (!used[v]) dfs(v);
	}
	memset(used, 0, sizeof(used));
	
	int k = 0;
	for (int i=vs.size()-1; i>=0; --i)
	{
		if (!used[vs[i]]) rdfs(vs[i], k++);
		
	}
	return k;
}
int n, k, r;
void solve()
{
	V = 2*k;
	int cnt = 0;
	for (int i=1; i<=n; ++i)
	{
		row[i].clear();
		col[i].clear();
	}
	
	for (int i=1; i<=k; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		row[u].push_back(v);
		col[v].push_back(u);
		ctn[u][v] = i-1;
	}
	
	for (int i=1; i<=n; ++i)
	{
		int sz = row[i].size();
		for (int i1=0; i1<sz; ++i1)
			for (int j1=0; j1<sz; ++j1)
				if (i1 != j1 && abs(row[i][i1]-row[i][j1])<=r)
				{
					int n1 = ctn[i][row[i][i1]], n2 = ctn[i][row[i][j1]];
//					printf("%d %d\n",n1, n2);
					add_edge(n1, n2+k);
					add_edge(n2, n1+k);
				}
		sz = col[i].size();
		for (int i1=0; i1<sz; ++i1)
			for (int j1=0; j1<sz; ++j1)
				if (i1 != j1 && abs(col[i][i1]-col[i][j1])<=r)
				{
//					printf("%d %d\n%d %d\n",p1.x,p1.y,p2.x,p2.y);
					
					int n1 = ctn[col[i][i1]][i], n2 = ctn[col[i][j1]][i];
//					printf("%d %d\n",n1, n2);
					add_edge(n1+k, n2);
					add_edge(n2+k, n1);
				}
	}
		

	scc();
	for (int i=0; i<k; ++i)
	{
		if (cmp[i] == cmp[k+i])
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	
}

int main()
{

	while(scanf("%d%d%d", &n, &r, &k) != -1) solve();
	return 0;
	
}
