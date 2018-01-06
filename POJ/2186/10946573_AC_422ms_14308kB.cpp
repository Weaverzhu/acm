#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;
const int MAX_V = 5e5 + 10;

int V;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];

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
	int k=0;
	for (int i=vs.size()-1; i>=0; --i)
	{
		if (!used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}
int N, M;
int A[MAX_V], B[MAX_V];

void solve()
{

	V = N;
	for (int i=0; i<M; ++i)
	{
		scanf("%d%d", &A[i], &B[i]);
		add_edge(A[i]-1, B[i]-1);
	}
	int n = scc();
	int u = 0, num = 0;
	for (int v=0; v<V; ++v)
	{
		if (cmp[v] == n-1)
		{
			u = v;
			num++;
		}
	}
	memset(used, 0, sizeof(used));
	rdfs(u, 0);
	for (int v=0; v<V; ++v)
	{
		if(!used[v])
		{
			num = 0;
			break;
		}
	}
	cout << num << endl;
}
int main()
{
	while(scanf("%d%d", &N, &M)!=-1) solve();
	return 0;
}
