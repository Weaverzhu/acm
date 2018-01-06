#include<bits/stdc++.h>
using namespace std;
const int N1 = (1 << 19), N2 = 70, MOD = 1e9+7;
int p[100], cnt, work[100];
int dat[100], n, x;
bool isp[100];
typedef long long LL;
int dp[71][N1+5];
LL len[22];
void init(){
	cnt = 0;
	memset(isp, 0, sizeof(isp));
	for (int i=2; i<=N2; ++i){
		if (!isp[i]){
			p[cnt++] = i;
			for (int j=2*i; j<=N2; j+=i){
				isp[j] = true;
			}
		}
	}
	// for (int i=0; i<cnt; ++i)
		// cout << p[i] << endl;
	len[0] = 1;
	for (int i=1; i<=20; ++i)
		len[i] = len[i-1] * 2;

}
LL pmd(int a, int b){
	LL f = a, res = 1;
	while(b){
		if (b%2) res = res * f % MOD;
		f = f * f % MOD;
		b >>= 1;
	}
	return res;
}
int main(){
	init();
	cin >> n;
	for (int i=0; i<n; ++i){
		scanf("%d", &x);
		dat[x]++;
	}
	if (dat[1] == n){
		cout << pmd(2, dat[1])-1 << endl;
		return 0;
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	int r = 0;
	for (int i=2; i<=70; ++i){
		if (dat[i]){
			++r; work[r] = i;
			int tmp = 0, now = i;
			vector<int> pp;
			for (int j=0; j<cnt; ++j){
				if (now % p[j] == 0){
					tmp = 0;
					while(now % p[j] == 0){
						++tmp;
						now /= p[j];
					}
					if (tmp % 2) pp.push_back(j);
				}
			}
			// cout << pp.size() << endl;
			
			int nextstate;
			for (int j=0; j<N1; ++j){
				if (dp[r-1][j]){
					if (x == 46) cout << dat[x] << endl;
					dp[r][j] = dp[r][j]+1LL*dp[r-1][j] * pmd(2, dat[i]-1) % MOD;
					dp[r][j] = dp[r][j] % MOD;
					nextstate = j;
					for (int k=0; k<pp.size(); ++k){
						if (j / len[pp[k]] % 2 == 1) nextstate -= len[pp[k]];
						else nextstate += len[pp[k]];
					}
					// printf("%d %d\n", r, nextstate);
					dp[r][nextstate] = dp[r][nextstate] + 1LL*dp[r-1][j]*pmd(2, dat[i]-1) % MOD;
					dp[r][nextstate] = dp[r][nextstate] % MOD;
				}
			}
		}
	}
	// cout << r << endl;
	// cout << dp[0] << endl;
	LL ans;
	if (dat[1] == 0){
		ans = dp[r][0]-1;
	}else ans = (dp[r][0]-1)*pmd(2, dat[1])%MOD;
	ans = ans + pmd(2, dat[1]) - 1;
	
	cout << ans%MOD << endl;
	
	return 0;
}