#include<bits/stdc++.h>
using namespace std;
const int maxn = 100+10;
int a[maxn], b[maxn];
int ans;
int n, k;

void solve()
{
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i=0; i<n; ++i)
	{
		int tmp;
		scanf("%d", &tmp);

		if (tmp == 1) a[i%k]++;
		else b[i%k]++;
	}
	int ans = 0;
	for (int i=0; i<k; ++i)
		ans += min(a[i], b[i]);
	cout << ans << endl;
}


int main()
{
	while(scanf("%d%d", &n, &k) != -1) solve();

	return 0;
}