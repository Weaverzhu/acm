#include<bits/stdc++.h>
using namespace std;

const int maxn=200000+10;
struct node
{
	int x,y;
};
node d[maxn];
int a[maxn][3];
int n,m;
bool cmp(node a,node b)
{
	if (a.x==b.x) return a.y>b.y;
	else return a.x<b.x;
}
void solve()
{
	for (int i=1;i<=m;++i) scanf("%d%d",&d[i].x,&d[i].y);
	sort(d+1,d+m+1,cmp);
	memset(a,0,sizeof(a));
	for (int i=1;i<=m;++i)
	{
		int tmp=d[i].y;
		a[tmp][1]=a[tmp+1][1]+1;
		a[tmp+1][0]=a[tmp][0]+1;
	}
	for (int i=1;i<=n;++i)
	{
		if (i!=n) printf("%d ",a[i][0]+a[i][1]+1);
		else printf("%d\n",a[i][0]+a[i][1]+1); 
	}
}
int main()
{
	while(scanf("%d%d",&n,&m)!=-1) solve();
	return 0;
	
}