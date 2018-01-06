#include<bits/stdc++.h>
using namespace std;
int a, b, cc;
const int MOD = 998244353;
typedef long long LL;
const int maxn = 5010;
LL c[maxn][maxn];
LL f[maxn];
LL solve(LL a, LL b)
{
	LL res = 0;
	LL k = min(a, b);
	
	LL tmp = 1;
	for (int i=0; i<=k; ++i)
	res = (res + c[a][i]*c[b][i]%MOD*f[i]%MOD) % MOD;
	return res;
}


int main()
{
	c[1][1] = 1; c[1][0] = 1;
	for (int i=2; i<=5000; ++i)
	{
		c[i][i] = 1; c[i][0] = 1;
		for (int j=1; j<i; ++j)
		{
			c[i][j] = (c[i-1][j-1]+c[i-1][j]) % MOD;
		}
	}
	f[0] = 1;
	for (int i=1; i<=5000; ++i) f[i] = (f[i-1]*i) % MOD;
//	cout << c[10][3] << endl;
 	while(scanf("%d%d%d", &a, &b, &cc) != -1)
	{
		LL ans1, ans2, ans3;
		ans1 = solve(a, b);
		ans2 = solve(b, cc);
		ans3 = solve(a, cc);
		LL ans = (ans1*ans2)%MOD*ans3%MOD;
		cout << ans << endl;
	}

	return 0;
}