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
int n;
char a[maxn], b[maxn];
int s[maxn*2];
void callheight(int *r, int *sa, int n)
{
	// printf("%d\n", n);
	int i, j, k=0;
	for (i=1; i<=n; ++i)
		rnk[sa[i]] = i;
	for (i=0; i<n; height[rnk[i++]]=k)
		for(k? k--:0, j=sa[rnk[i]-1]; r[i+k] == r[j+k]; k++);

}
int ls, la, lb;
void debug()
{
	printf("s:\n");
	for (int i=0; i<ls; ++i)
		printf("%c", s[i]);
	printf("\n");
	printf("la = %d lb = %d\n", la, lb);
	printf("sa:\n");
	for (int i=0; i<ls; ++i)
		printf("%d:%d\n", i, sa[i]);
	printf("height:\n");
	for (int i=0; i<ls; ++i)
		printf("%d:%d\n", i, height[i]);
	printf("rank:\n");
	for (int i=0; i<ls; ++i)
		printf("%d:%d\n", i, rnk[i]);
	system("pause");

}
void solve()
{
	scanf("%s", b);
	la = strlen(a), lb = strlen(b);
	for (int i=0; i<la; ++i)
		s[i] = a[i];
	s[la] = 'A';
	ls = la+lb+1;
	for (int i=0; i<lb; ++i)
		s[i+la+1] = b[i];
	da(s, sa, ls, 200);
	callheight(s, sa, ls-1);

	// debug();
	int ans = 0;
	for (int i=1; i<ls; ++i){
		if ((sa[i]>la && sa[i-1]<la) || (sa[i]<la && sa[i-1]>la))
			if (height[i] > ans)
				ans = height[i];

	}
	cout << ans << endl;
}

int main()
{
	while(scanf("%s", a) != -1) solve();
	return 0;
}