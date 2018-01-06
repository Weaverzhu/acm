#include<iostream>
using namespace std;
typedef long long LL;
int n;
const int maxn = 1e6+10;
LL a[maxn], l[maxn], r[maxn];

void solve()
{
	LL res = 0;
	for (int i=1; i<=n; ++i) scanf("%I64d", &a[i]), l[i]=r[i]=i;
	for (int i=2; i<=n; ++i)
	{
		int now = i;
		while(now > 1 && a[i] >= a[now - 1]) now = l[now - 1];
		l[i] = now;
	}
	for (int i=n-1; i>=1; --i)
	{
		int now = i;
		while(now < n && a[i] > a[now+1]) now = r[now + 1];
		r[i] = now;
	}
	for (int i=1; i<=n; ++i) res += 1LL * ((i-l[i]+1) * (r[i]-i+1)) * a[i];
	// for (int i=1; i<=n; ++i)
	// {
	// 	printf("i=%d l[i]=%d r[i]=%d\n", i, l[i], r[i]);
	// }
	for (int i=1; i<=n; ++i) l[i]=r[i]=i;
	for (int i=2; i<=n; ++i)
	{
		int now = i;
		while(now > 1 && a[i] <= a[now - 1]) now = l[now - 1];
		l[i] = now;
	}
	for (int i=n-1; i>=1; --i)
	{
		int now = i;
		while(now < n && a[i] < a[now+1]) now = r[now + 1];
		r[i] = now;
	}
	for (int i=1; i<=n; ++i) res -= 1LL * ((i-l[i]+1) * (r[i]-i+1)) * a[i];
	cout << res << endl;

}
int main()
{
	while(scanf("%d", &n) != -1) solve();
}