#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n, m;
const int N = 12;
const int T = 2;
const int INF = 0x3f3f3f3f;
vector<int> G[N], W[N];
void add(int u, int v, int w){
	G[u].pb(v);
	G[v].pb(u);
	W[u].pb(w);
	W[v].pb(w);
}
int dp[200000][N];
int Pow[N+5], g[N][N];
int main(){
	int i, j, k;
	Pow[0] = 1;
	for (int i=1; i<=12; ++i)
		Pow[i] = Pow[i-1]*3;
	// cout << Pow[11] << endl;
	while(~scanf("%d%d", &n, &m)){
		memset(g, INF, sizeof(g));
		memset(dp, INF, sizeof(dp));
		for (i=0; i<m; ++i){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			// add(u, v, w);
			g[u][v] = min(g[u][v], w);
			g[v][u] = min(g[v][u], w);
		}
//		memset(dp, 0, sizeof(dp));
		for(i=1;i<=n; ++i)
			dp[Pow[i]][i] = 0;
		int ans = INF;
		for (i=1; i<=Pow[n+1]; ++i){
			bool suc = true;
			for (j=1; j<=n; ++j){
				if (i/Pow[j] % 3 == 0){
						suc = false;
						continue;
				}
				if (dp[i][j] < INF){
					
					for (k=1; k<=n; ++k)
						if (k != j && (i/Pow[k]%3)<2)
							dp[i+Pow[k]][k] = min(dp[i+Pow[k]][k], dp[i][j] + g[j][k]);
				}


			}
			if (suc){
				for (j=1; j<=n; ++j)
					if (dp[i][j] < ans)
						ans = dp[i][j];
			}
		}
		if (ans < INF)
		cout << ans << endl;
		else printf("-1\n");
	}
	return 0;
}