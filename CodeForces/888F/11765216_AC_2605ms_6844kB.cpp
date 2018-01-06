#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int MOD = 1e9+7;
typedef long long LL;
LL dp[maxn][maxn][2];
int g[maxn][maxn];
int n, m;
int main(){
	while(~scanf("%d", &n)){
		memset(dp, 0, sizeof(dp));
		memset(g, 0, sizeof(g));

		for (int i=0; i<n; ++i){
			for (int j=0; j<n; ++j){
				scanf("%d", &g[i][j]);
			}
		}
		for (int i=0; i<n; ++i){
			dp[i][i][1] = dp[i][i][0] = 1;
		}
		for (int d=1; d<n; ++d){
			for (int i=0; i<n; ++i){
				int j = (i+d)%n;
				for (int k=i; k!=j; k=(k+1)%n){
					if (g[i][j]){
						dp[i][j][0] += dp[i][k][1]*dp[(k+1)%n][j][1]%MOD;
						dp[i][j][0] = dp[i][j][0] % MOD;
					}
					dp[i][j][1] += dp[i][(k+1)%n][0]*dp[(k+1)%n][j][1]%MOD;
					dp[i][j][1] %= MOD;
				}

			}
		}
		cout << dp[0][n-1][1] << endl;
	}
	return 0;
}