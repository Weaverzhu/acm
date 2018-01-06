#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int x[maxn];
int n,q;
int INF=1<<30;
int main()
{
	while(scanf("%d",&n)!=-1)
	{
		x[0]=0;x[n+1]=INF;
		for (int i=1;i<=n;++i) scanf("%d",&x[i]);
		sort(x+1,x+n+1);
		scanf("%d",&q); 
		for (int i=1;i<=q;++i)
		{
			int key;
			scanf("%d",&key);
			int l=0,r=n+1;
			while(l<r-1)
			{
				int mid=(l+r)/2;
				if (x[mid]>key) r=mid;
				else l=mid;
			}
			cout<<l<<endl;
		}
		
	}
	
	
}