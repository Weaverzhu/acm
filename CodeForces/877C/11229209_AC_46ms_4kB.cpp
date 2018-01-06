#include<iostream>
#include<cstdio>
using namespace std;


int main()
{
	int n;
	while(scanf("%d", &n) != -1)
	{
		printf("%d\n2", n+n/2);
		for (int i=4; i<=n; i+=2)
			printf(" %d", i);
		for (int i=1; i<=n; i+=2)
			printf(" %d", i);
		for (int i=2; i<=n; i+=2)
			printf(" %d", i);
		printf("\n");
	}

	return 0;
}