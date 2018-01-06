#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100];
void init()
{
	a[0] = 1;
	for (int i=1; i<=55; ++i)
	{
		LL res = 1;
		for (int j=1; j<=i; ++j)
			res = res * 2;
		a[i] = res;
	}
}
LL n, k;
void solve()
{
	for (int i=1; i<=n; ++i)
	{
		if ((k-a[i-1]) % a[i] == 0)
		{
			cout << i << endl;
			return;
		}
	}
}
int main()
{
	init();
	while(scanf("%I64d%I64d", &n, &k) != -1) solve();
	return 0;
}