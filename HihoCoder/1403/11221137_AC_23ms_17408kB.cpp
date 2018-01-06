#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
const int maxm = 120;
int sa[maxn], wa[maxn], wb[maxn], wv[maxn], wss[maxn];
int cmp(int *r, int a, int b, int len)
{
	return r[a] == r[b] && r[a+len] == r[b+len];
}
void da(int *r, int *sa, int n, int m)
{
	int i, j, p, *x = wa, *y = wb, *t;
	for (int i=0; i<m; ++i) 
		wss[i] = 0;
	for (int i=0; i<n; ++i) 
		wss[x[i]=r[i]]++;
	for (int i=0; i<m; ++i)
		wss[i] += wss[i-1];
	for (int i=n-1; i>=0; i--)
		sa[--wss[x[i]]] = i;
	for (int j=1, p=1; p<n; j*=2, m=p)
	{
		for (p=0, i=n-j; i<n; ++i)
			y[p++] = i;
		for (i=0; i<n; ++i)
			if (sa[i] >= j)
				y[p++] = sa[i]-j;
		for (int i=0; i<n; ++i)
			wv[i] = x[y[i]];
		for (int i=0; i<m; ++i)
			wss[i] = 0;
		for (int i=0; i<n; ++i)
			wss[wv[i]]++;
		for (int i=1; i<m; ++i)
			wss[i] += wss[i-1];
		for (int i=n-1; i>=0; --i)
			sa[--wss[wv[i]]] = y[i];
		for (t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i<n; ++i)
			x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1 : p++;

	}
}
int rnk[maxn], height[maxn];
void callheight(int *r, int *sa, int n)
{
	int i, j, k=0;
	for (int i=1; i<=n; ++i)
		rnk[sa[i]] = i;
	for (int i=0; i<n; height[rnk[i++]]=k)
		for (k? k--:0, j=sa[rnk[i]-1]; r[i+k] == r[j+k]; ++k);
}
int n, k;
int a[maxn];
void solve()
{

	for (int i=0; i<n; ++i) 
		scanf("%d", &a[i]);
	if (k == 1) {cout << n << endl; return;}
	a[n] = 0;
	da(a, sa, n+1, maxm);
	callheight(a, sa, n);
	// for (int i=0; i<n; ++i)
	// {
	// 	cout << sa[i] << " ";
	// 	for (int j=sa[i]; j<n; ++j) cout << a[j];
	// 	cout << endl;
	// }
	// cout << "sa:\n";
	// for (int i=0; i<n; ++i) cout << sa[i] << endl;

	// cout << "rank:\n";
	// for (int i=0; i<=n; ++i) cout << rank[i] << endl;

	// cout << "height[rank[i]]:\n";
	// for (int i=0; i<=n; ++i) cout << height[rank[i]] << endl;

	// cout << "height[i]:\n";
	// for (int i=0; i<=n; ++i) cout << height[i] << endl;
	int l=1, r=n;
	while(l < r-1)
	{
		bool suc = false;
		int mid = (l+r) >> 1;
		for (int i=1; i<n; ++i)
			if (height[i] >= mid)
			{
				int cnt = 0;
				while(cnt<k-1 && i<n && height[i] >= mid)
					++i, ++cnt;
				if (cnt >= k-1) {suc = true;  break;}
			}
		if (suc) l = mid;
		else r = mid;
	}
	cout << l << endl;
}
int main()
{
	while(scanf("%d%d", &n, &k) != -1) solve();
	return 0;
}