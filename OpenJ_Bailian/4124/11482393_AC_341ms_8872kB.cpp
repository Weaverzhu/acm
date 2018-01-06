#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 17;
int g[maxn][maxn];
int p2[maxn];
int dp[1<<maxn][maxn];
const int INF = 0x3f3f3f3f;
int get(int i, int j){
	int ans = i/p2[j] % 2;
	return ans;
	
}
void solve(){
	int ans = INF;
	for (int i=0; i<=n-1; ++i)
		for (int j=0; j<=n-1; ++j)
			scanf("%d", &g[i][j]);
	memset(dp, INF, sizeof(dp));
	dp[1][0] = 0;
	for (int i=0; i<=1<<maxn-1; ++i){
		bool suc = true;
		for (int j=0; j<=n-1; ++j){
			if (!get(i, j)){
				suc = false;
				continue;
			}
			for (int k=0; k<n; ++k){
				if (!get(i, k)){
					dp[i+p2[k]][k] = min(dp[i+p2[k]][k], dp[i][j]+g[j][k]);
				}
			}
		}
	}
	cout << dp[p2[n]-1][n-1] << endl;
	
}

int main(){

	p2[0] = 1;
	for (int i=1; i<=17; ++i)
		p2[i] = p2[i-1]*2;
	while(~scanf("%d", &n))
		solve();
	return 0;
} 