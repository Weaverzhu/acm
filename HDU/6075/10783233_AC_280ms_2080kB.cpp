#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
const int INF=0x3f3f3f3f;
int a[maxn];
	
int main()
{
	/*
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int mina=INF,mini;
		for (int i=1;i<=n;++i) 
		{
			scanf("%d",&a[i]);
			if (a[i]<mina)
			{
				mina=a[i];
				mini=i;
			}
		}
	*/	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a1=0,a2=0;
		for (int i=1;i<=n;++i) 
		{
			scanf("%d",&a[i]);
			if (a[i]%2) ++a1;else++a2;
		}
		if (a2>a1) cout<<2<<" "<<0<<endl;
		else cout<<2<<" "<<1<<endl;
	}
	return 0;
}
			
		