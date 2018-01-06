#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=20;
int a[20],vis[20];
int n,l,r,x;
int cnt=0;
long long sum;
int ans=0;
void dfs(int now){
	if (now==n+1){
		bool flag=true;
		if (cnt<2){
			flag=false;
			return;
		}
		if (sum<l||sum>r){
			flag=false;
			return;
		}
		int minx,maxx;
		for (int i=1;i<=n;++i){
			if (vis[i]){
				minx=a[i];
				break;
			}
		}
		for (int i=n;i>=1;--i)
			if (vis[i]){
				maxx=a[i];
				break;
			}
		if (maxx-minx<x){
			flag=false;
			return;
		}
		if (flag) ++ans;
		return;
	}
	
	dfs(now+1);
	sum+=a[now];vis[now]=1;cnt++;
	dfs(now+1);
	cnt--;sum-=a[now];vis[now]=0;
	return;
}
int main(){
	
	
	scanf("%d%d%d%d",&n,&l,&r,&x);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dfs(1);
	cout<<ans<<endl;
}