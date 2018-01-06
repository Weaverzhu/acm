#include<iostream>
#include<cstdio>
int n;
int main()
{
	while(scanf("%d", &n) != -1)
	{
		if (n == 0) break;
		if (n <= 2) puts("Alice");
			else puts("Bob");
	}
	return 0;
 } 