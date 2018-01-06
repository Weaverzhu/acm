#include<bits/stdc++.h>
using namespace std;

int n;
void solve(int t)
{
	scanf("%d", &n);
	// cout << n << endl;
	printf("Case #%d: ", t);
	bool suc = true;
	for (int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d", &x);
		if (x%3) {suc = false; }
	}
	if (suc) printf("Yes\n");
	else printf("No\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; ++i)
		solve(i);
	return 0;

}