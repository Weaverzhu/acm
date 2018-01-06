#include<iostream>
#include<cstdio>
void swap(int &a, int &b)
{
	int k=a;a=b;b=k;
	return;
}
int a,b;
int main()
{
	bool f = true;
	while(scanf("%d%d", &a, &b)!=-1)
	{
//		if (n == 0) break;
		if (a==0 && b==0) break;
		f = true;
		while(1)
		{
			if (a>b) swap(a, b);
			if (b%a == 0) break;
			if (b-a>a) break;
			b -= a;
			f = !f;
		}
		if (f) puts("Stan wins");
			else puts("Ollie wins");
	}
	return 0;
 } 