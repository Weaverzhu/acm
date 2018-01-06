#include<bits/stdc++.h>
using namespace std;
int x1, y1, x2, y2, x, y;
void solve()
{
	scanf("%d%d", &x, &y);
	int dx = int(abs(x1 - x2)), dy = int(abs(y1 - y2));
	if (dx%x == 0 && dy%y == 0 && (dx/x - dy/y)%2==0) printf("YES\n");
	else printf("NO\n");
}


int main()
{
	while(scanf("%d%d%d%d", &x1, &y1, &x2, &y2) != -1) solve();
	return 0;
}