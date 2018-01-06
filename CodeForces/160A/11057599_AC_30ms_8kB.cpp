#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int a[maxn], n;
int main()
{
	while(scanf("%d", &n) != -1)
	{
		int sum = 0, ns = 0, ans;
		for (int i=1; i<=n; ++i)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sort(a+1, a+n+1);
		for (int i=n; i>=1; --i)
		{
			ns += a[i];
			if (ns > sum/2)
			{
				ans = n-i+1;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}