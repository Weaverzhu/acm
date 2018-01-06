#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 300000, maxp = 100000+10;
int n, p;
int f[maxn+10], sz[maxn+10], h[maxn+10];
char ch;
int a, b;
int sz1, sz2;
int pa[maxn+10];
int findroot(int x)
{
	int fa = f[x];
	if (f[fa] == fa)
		return fa;
	int ps = 0;
	sz1 = sz[x];
	bool flag = false;
	while(x != f[x])
	{
		pa[ps++] = x;
		x = f[x];
		// flag = true;
	}
	// if (flag) sz1 += sz[x];
	for (int i=ps-1; i>=0; --i)
		h[pa[i]] += h[f[pa[i]]], f[pa[i]] = x;
	
	return x;
}
void uni(int x, int y)
{
	f[y] = x;
	h[y] += sz[x];
	sz[x] += sz[y];
	// printf("x=%d y=%d sz[y]=%d\n", x, y, sz[1]);
	// sz[x] = 0;
}
void debug()
{
	printf("ch=%c a=%d b=%d\n", ch, a, b);
}
void getch()
{
	while(!(ch =='M' || ch == 'C'))
		ch = getchar();
}
int main()
{
	while(scanf("%d", &p) != -1)
	{
		ch = '1';
		for (int i=1; i<=maxn; ++i)
			f[i] = i, sz[i] = 1, h[i] = 0;
		for (int i=0; i<p; ++i){
			getch();
			if (ch == 'M')
			{
				scanf("%d%d", &a, &b);
				a = findroot(a); b = findroot(b);
				uni(a, b);
				// printf("%c %d %d %d\n", ch, a, b, i);
			}
			else if (ch == 'C')
			{
				scanf("%d", &a);
				int root = findroot(a);
				// int root = findroot(a);
				// root = 1;
				// printf("a=%d\n", a);
				printf("%d\n", sz[root]-h[a]-1);
				// printf("%c %d %d\n", ch, a, i);
			}
			ch = getchar();
			
		}
			
		// debug();
	}

	return 0;
}