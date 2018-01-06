#include<bits/stdc++.h>
using namespace std;
struct card
{
	int a, b;
};
const int maxn = 1000;
card c[maxn + 10], d[maxn + 10];
int n;

bool cmp1(card a, card b){return a.b>b.b;}
bool cmp2(card a, card b){return a.a>b.a;}
void solve()
{
	memset(c, 0, sizeof(c));
	memset(d, 0, sizeof(d));
	for (int i=1; i<=n; ++i) scanf("%d%d", &c[i].a, &c[i].b);
	sort(c+1, c+n+1, cmp1);
	int counter = 1, ci = 0;
	int ans = 0;
	for (int i=1; i<=n; ++i)
		if (c[i].b == 0) {ci = i; break;}
			else counter += (c[i].b - 1), ans += c[i].a;
	// cout << ans << endl;
	int cnt = 0;
	if (ci == 0) ci = n;
	while(c[ci].b != 0 && ci <= n+1) ++ci;
	// cout << ci << endl;
	for (int i=ci; i<=n; ++i)
		d[++cnt] = c[i];
	sort(d+1, d+cnt+1, cmp2);
	// cout << cnt <<" "<< co5unter << endl;
	for (int i=1; i<=min(cnt, counter); ++i) ans += d[i].a;
	cout << ans << endl;
}

int main()
{
	while(scanf("%d", &n) != -1) solve();
	return 0;
}