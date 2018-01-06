#include<cstdio>
long long gcd(long long a, long long b)
{
	while(b)
	{
		long long c = a%b;
		a = b; b = c;
	}
	return a;
}

int main()
{
	long long x, n;
	scanf("%lld%lld", &x, &n);
	for (int i=2; i<=n; ++i)
	{
		long long g = gcd(i, x);
		printf("%lld\n", i/g);
	}

	return 0;
}