#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int p[maxn + 10];

int main()
{
	int n;
	while(scanf("%d", &n) != -1)
	{
		scanf("%d", &p[1]);
		int minp = p[1], maxp = p[1], ans = 0;
		for (int i=2; i<=n; ++i)
		{
			scanf("%d", &p[i]);
			int get = 0;
			if (p[i] > maxp)
			{
				maxp = p[i];
				get = 1; 
			}
			if (p[i] < minp)
			{
				minp = p[i];
				get = 1;
			}
			ans += get;
		}
		cout << ans << endl;
	}
}