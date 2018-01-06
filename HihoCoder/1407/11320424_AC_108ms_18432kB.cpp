#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
int sa[maxn], wa[maxn], wb[maxn], wv[maxn], wss[maxn];
int cmp(int *r, int a, int b, int len)
{
	return r[a] == r[b] && r[a+len] == r[b+len];
}
void da(int *r, int *sa, int n, int m)
{
	int i, j, p, *x=wa, *y=wb, *t;
	for (i=0; i<m; ++i)
		wss[i] = 0;
	for (i=0; i<n; ++i)
		wss[x[i]=r[i]]++;
	for (i=0; i<m; ++i)
		wss[i] += wss[i-1];
	for (i=n-1; i>=0; --i)
		sa[--wss[x[i]]] = i;
	for (j=1, p=1; p<n; j*=2, m=p)
	{
		for (p=0, i=n-j; i<n; ++i)
			y[p++] = i;
		for (i=0; i<n; ++i)
			if (sa[i] >= j)
				y[p++] = sa[i]-j;
		for (i=0; i<n; ++i)
			wv[i] = x[y[i]];
		for (i=0; i<m; ++i)
			wss[i] = 0;
		for (int i=0; i<n; ++i)
			wss[wv[i]]++;
		for (int i=1; i<m; ++i)
			wss[i] += wss[i-1];
		for (int i=n-1; i>=0; --i)
			sa[--wss[wv[i]]] = y[i];
		for (t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i<n; ++i)
			x[sa[i]] = cmp(y, sa[i-1], sa[i], j)? p-1:p++;

	}
}
int rnk[maxn], height[maxn];
void callheight(int *r, int *sa, int n)
{
	int i, j, k=0;
	for (i=1; i<=n; ++i)
		rnk[sa[i]] = i;
	for (int i=0; i<n; height[rnk[i++]]=k)
		for(k? k--:0, j=sa[rnk[i]-1]; r[i+k] == r[j+k]; k++);

}
int n;
int a[maxn];
bool check(int K)
{
	int minsa = 2147483647, maxsa = 0;
	for (int i=1; i<=n; ++i)
	{
		if (height[i] < K)
		{
			minsa = sa[i];
			maxsa = sa[i];
		}
		else
		{
			minsa = min(minsa, sa[i]);
			maxsa = max(maxsa, sa[i]);
			if (maxsa-minsa >= K) return true;
		}

	}
	return false;
}
const int maxm = 1000+10;
void solve()
{
	for (int i=0; i<n; ++i) 
		scanf("%d", &a[i]);
	a[n] = 0;
	da(a, sa, n+1, maxm);
	callheight(a, sa, n);

	int l = 0, r = n+1;
	while(l < r-1)
	{
		int mid = (l+r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	cout << l << endl;
	
}
int main()
{
	
	while(scanf("%d", &n) != -1) solve();
	return 0;
}