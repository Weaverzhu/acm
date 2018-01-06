#include <bits/stdc++.h>
#define Maxn 2507
using namespace std;
int n,m,q;
map<pair<pair<int,int>,pair<int,int> >,pair<unsigned long long,unsigned long long> > mp;
pair<unsigned long long,unsigned long long> s[Maxn][Maxn];
void add(int x,int y,pair<unsigned long long,unsigned long long> del)
{
	for (int kx=x;kx<=2503;kx+=kx&(-kx))
		for (int ky=y;ky<=2503;ky+=ky&(-ky))
		{
			s[kx][ky].first+=del.first;
			s[kx][ky].second+=del.second;
		}
}
pair<unsigned long long,unsigned long long> query(int x,int y)
{
	pair<unsigned long long,unsigned long long> res=make_pair(0,0);
	for (int kx=x;kx;kx-=kx&(-kx))
		for (int ky=y;ky;ky-=ky&(-ky))
		{
			res.first+=s[kx][ky].first;
			res.second+=s[kx][ky].second;
		}
	return res;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	memset(s,0,sizeof(s));
	srand(20001206);
	mp.clear();
	for (int i=1;i<=q;i++)
	{
		int t,r1,c1,r2,c2;
		scanf("%d%d%d%d%d",&t,&r1,&c1,&r2,&c2);
		pair<unsigned long long,unsigned long long> del,udel;
		if (t==1)
		{
			del.first=rand();
			del.second=rand();
			udel=make_pair(-del.first,-del.second);
			mp[make_pair(make_pair(r1,c1),make_pair(r2,c2))]=del;
			add(r1,c1,del);
			add(r1,c2+1,udel);
			add(r2+1,c1,udel);
			add(r2+1,c2+1,del);
		} else if (t==2)
		{
			del=mp[make_pair(make_pair(r1,c1),make_pair(r2,c2))];
			mp[make_pair(make_pair(r1,c1),make_pair(r2,c2))]=make_pair(0,0);
			udel=make_pair(-del.first,-del.second);
			add(r1,c1,udel);
			add(r1,c2+1,del);
			add(r2+1,c1,del);
			add(r2+1,c2+1,udel);
		}
		else
		{
			del=query(r1,c1);
			udel=query(r2,c2);
			if (del==udel) printf("Yes\n"); else printf("No\n");
		}
	}
	return 0;
}