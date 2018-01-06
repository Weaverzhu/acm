#include<cstdio>
#include<cmath>
using namespace std;
const double eps = 1e-15;
double dxf(double x)
{
	return 6*x*x-8*x+3;
}
double f(double x)
{
	return 2*x*x*x-4*x*x+3*x-6;
}

int main()
{
	double xn = 1.5;
	// printf("%lf\n%lf\n", f(xn), dxf(xn));
	int cnt = 0;
	while(fabs(f(xn)) >= eps)
	{
		xn = xn-(f(xn)/dxf(xn));
		cnt ++;
	}
	printf("%.2lf %d\n", xn, cnt);

	return 0;
}