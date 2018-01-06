#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 400+5;
int g[maxn][maxn], g1[maxn][maxn];
vector<int> G[maxn], G1[maxn];
bool isin[maxn];
int n, m;
void floyed(){
	int i, j, k;
	for (i=1; i<=n; ++i)
		for (j=1; j<=n; ++j)
			for (k=1; k<=n; ++k)
			{
				if (i!=j && j!=k && i!=k)
				{
					if (g[i][k]+g[k][j]<g[i][j])
						g[i][j]=g[i][k]+g[k][j];
					if (g1[i][k]+g1[k][j]<g1[i][j])
						g1[i][j]=g1[i][k]+g1[k][j];
				}
			}
}
int dist[maxn];
int spfa(int s, int t){
	memset(dist, INF, sizeof(dist));
	queue<int> Q;
	memset(isin, 0, sizeof(isin));
	Q.push(s); isin[s] = true;
	dist[s] = 0;
	while(!Q.empty()){
		int now = Q.front();
		Q.pop(); isin[now] = false;
		// printf("now=%d\n", now);
		for (int e=0; e<G[now].size(); ++e){

			int v = G[now][e];
			if (dist[now]+1<dist[v]){
				dist[v] = dist[now]+1;
				if (!isin[v]){
					Q.push(v);
					isin[v] = true;
					
				}
			}
		}
	}
	// for (int i=1; i<=n; ++i) printf("%d ", dist[i]);
	if (dist[t] == INF) return -1;
	
	// puts("");
	return dist[t];

}
void debug(){
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j)
			printf("%d ", g[i][j]);
		printf("\n");
	}
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j)
			printf("%d ", g1[i][j]);
		printf("\n");
	}

}
void solve(){
	memset(g, 0, sizeof (g));
	memset(g1, 0, sizeof(g1));
	
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			if (i != j) g1[i][j] = 1;
	for (int i=0; i<m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u][v] = 1;
		g1[u][v] = INF;
		g[v][u] = 1;
		g1[v][u] = INF;
	}
	if (g[1][n] == 1){
		for (int i=1; i<=n; ++i){
			for (int j=1; j<=n; ++j){
				if (g1[i][j]==1) G[i].push_back(j);
			}
		}
	}else{
		for (int i=1; i<=n; ++i){
			for (int j=1; j<=n; ++j){
				if (g[i][j]==1) G[i].push_back(j);
			}
		}
	}
	// for (int i=1; i<=n; ++i){
	// 	for (int j=0; j<G[i].size(); ++j)
	// 		printf("%d ", G[i][j]);
	// 	printf("\n");
	// }
	// for (int i=1; i<=n; ++i){
	// 	for (int j=1; j<=n; ++j){
	// 		printf("%d ", g[i][j]);
	// 	}
	// 	puts("");
	// }
	// printf("das\n");
	cout << spfa(1, n) << endl;
	// debug();

}


int main(){
	while(scanf("%d%d", &n, &m) != -1){
		memset(g, INF, sizeof(g));
		solve();
	}
	return 0;
}