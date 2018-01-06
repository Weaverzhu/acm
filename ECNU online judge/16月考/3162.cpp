#include<cstdio>


int main()
{
	int a, b;
	while(scanf("%d%d", &a, &b) != -1)
	{
		printf("%d\n%d\n%d\n", a||b, a|b, a^b);
	}
}