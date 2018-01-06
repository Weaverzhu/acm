#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10;
const int maxm=100000+10;
struct node
{
	int x,y;
};
bool cmp(node a,node b)
{
	return a.y>b.y;
}
node d[maxn];
int n,m;
void solve()
{
	for (int i=1;i<=n;++i)
	{
		d[i].x=i;d[i].y=-i;
	}
	for (int i=1;i<=m;++i)
	{
		int tmp;
		scanf("%d",&tmp);
		d[tmp].y=i;
	}
	sort(d+1,d+n+1,cmp);
	for (int i=1;i<=n;++i) printf("%d\n",d[i].x);
}
int main()
{
	while(scanf("%d%d",&n,&m)!=-1) solve();
	
	return 0;
 } 