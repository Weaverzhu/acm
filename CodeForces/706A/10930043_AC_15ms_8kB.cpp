#include<bits/stdc++.h>
using namespace std;

double xa,ya;
double mint;

int main()
{
	
	while(scanf("%lf%lf",&xa,&ya)!=-1)
	{
		int n;
		scanf("%d",&n);
		double x,y,v,dx,dy;
		scanf("%lf%lf%lf",&x,&y,&v);
		dx=xa-x;dy=ya-y;
		mint=sqrt(dx*dx+dy*dy)/v;
		for (int i=2;i<=n;++i)
		{
			scanf("%lf%lf%lf",&x,&y,&v);
			dx=xa-x;dy=ya-y;
			double tmpt=sqrt(dx*dx+dy*dy)/v;
			if (tmpt<mint) mint=tmpt;
		}
		printf("%.7lf\n",mint);
	}
	
	
	return 0;
}