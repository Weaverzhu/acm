#include<iostream>
#include<cstdio>
const int maxn=50+10;
const int maxm=1e4+10;
int a[maxn],b[maxm];
using namespace std;
void solve(){
	int n,m;
	int ans[maxn],tans=-1;
	scanf("%d%d",&n,&m);
	for (int i=0;i<=m;++i) scanf("%d",&b[i]);
	bool flag=true;
	while(flag){
		int num=0;
		int now;
		flag=false;
		for (int i=1;i<=m;++i){
			if (b[i]!=0){
				flag=true;
				now=i;
				ans[++tans]=i;
				break;
				
			}
		}
		for (int i=now;i<=m;++i) b[i]-=b[i-now];
		
	}
	for (int i=0;i<tans;++i) printf("%d ",ans[i]);
	printf("%d\n",ans[tans]);
	return;
}
	
int main(){
	int t;
	scanf("%d",&t);
	for (int i=0;i<t;++i) solve();
	return 0;
}