#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn = 100+10;
int n, m, k;
int sumx[maxn][maxn], sumy[maxn][maxn], ans, sans;
int mp[maxn][maxn];
int main()
{
	while(scanf("%d%d%d", &n, &m, &k) != -1)
	{
		sans = 0; ans = 0;
		for (int i=1; i<=n; ++i)
		{
			sumx[i][0] = 0;
			for (int j=1; j<=m; ++j)
			{
				scanf("%d", &mp[i][j]);
				sumx[i][j] = sumx[i][j-1]+mp[i][j];
				sumy[j][i] = sumy[j][i-1]+mp[i][j];
			}
		}
		if (n == k)
		{
			int cnt = 0;
			for (int i=1; i<=n; ++i)
				for (int j=1; j<=m; ++j)
					cnt += mp[i][j];
			printf("%d %d\n", cnt, 0);
			continue;
		}
		for (int i=1; i<=m; ++i)
		{
			int now = 0;
			for (int j=1; j<=k; ++j)
				now += mp[j][i];
			int max = now, lo = 0;
			for (int j=k+1; j<=n; ++j)
			{
				now += (mp[j][i]-mp[j-k][i]);
				if (now > max)
				{
					lo = sumy[i][j-k-1];
					max = now;
				}
			}
			sans += lo; ans += max;
		}
		printf("%d %d\n", ans, sans);

	}


	return 0;
}
