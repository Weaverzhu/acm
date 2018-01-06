#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
char s[maxn*2];
int a1[maxn], a2[maxn];
int n;
bool vis[maxn];
int main()
{
	scanf("%d", &n);
	
		memset(vis, false, sizeof(vis));
		scanf("%s", s);
		for (int i=1; i<=n; ++i)
		{
			a1[i] = s[i-1];
			a2[i] = s[i+n-1];
		}
		sort(a1+1, a1+n+1);
		sort(a2+1, a2+n+1);
		
		bool suc1 = true, found, suc2 = true;
		for (int i=1; i<=n; ++i)
		{
			int na1 = a1[i];
			for (int j=n; j>=1; --j)
			{
				found = false;
				if (!vis[j] && a2[j] < na1)
				{
					found = true;
					vis[j] = true;
					break;
				}
			}
			if (!found)
			{
				suc1 = false; break;
			}
			
		}
		memset(vis, false, sizeof(vis));
		for (int i=1; i<=n; ++i)
		{
			int na1 = a1[i];
			for (int j=1; j<=n; ++j)
			{
				found = false;
				if (!vis[j] && a2[j] > na1)
				{
					found = true;
					vis[j] = true;
					break;
				}
			}
			if (!found)
			{
				suc2 = false; break;
			}
			
		}
		if (suc1||suc2) printf("YES\n"); else printf("NO\n");
		
	
	
	return 0;
}