#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
const int M = 1e5;
bool nprime[maxn];

int a, b;
int cnta[maxn], cntb[maxn];

void initial()
{
	memset(nprime, false, sizeof(nprime));
	for (int i=2; i<=M; ++i)
		if (!nprime[i])
		{
			for (int j=2*i; j<=M; j+=i) nprime[j] = true;
		}
}

void solve()
{
	memset(cnta, 0, sizeof(cnta));
	memset(cntb, 0, sizeof(cntb));
	for (int i=2; i<=M; ++i)
	{
		if (!nprime[i])
		{
			while (a%i == 0)
			{
				a /= i; ++cnta[i];
			}
			// if (i == 2) printf("when i == 2 a=%d\n", a);
			while (b%i == 0)
			{
				b /= i; ++cntb[i];
			}
		}
	}
	bool suc = true;
	for (int i=6; i<=M; ++i)
		if (!nprime[i] && cnta[i] != cntb[i]) suc = false;
	if (a != b) suc = false;
	if (suc)
	{
		int ans = 0;
		ans += abs(cnta[2] - cntb[2]) + abs(cnta[3] - cntb[3]) + abs(cnta[5] - cntb[5]);
		cout << ans << endl;
	}
	else cout << -1 << endl;
}

int main()
{
	initial();
	while(scanf("%d%d", &a, &b) != -1) solve();
	return 0;
}