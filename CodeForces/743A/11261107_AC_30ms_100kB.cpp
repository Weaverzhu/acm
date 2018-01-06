#include<bits/stdc++.h>
using namespace std;
int n, a, b;
const int maxn = 1e5+10;
char s[maxn];
int main()
{
	while(scanf("%d%d%d", &n, &a, &b) != -1)
	{
		scanf("%s", s);
		if (s[a-1] != s[b-1]) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}