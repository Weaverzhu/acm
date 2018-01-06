#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt", "w", stdout);
	int n = 500000;
	printf("%d\n", n);
	for (int i=1; i<=n; ++i) printf("%d ", i);
	printf("\n");
	printf("%d\n", n+1);
	for (int i=1; i<=n; ++i)
		printf("1 %d %d\n", i, 0);
	printf("2 1 500000\n");
	return 0;
}