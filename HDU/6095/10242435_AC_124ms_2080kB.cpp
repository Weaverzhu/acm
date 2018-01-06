#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,t,k;
const int maxn=1e5+10;
int a[maxn];

int cmp(int a, int b) {return a>b;}
void solve(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;++i) scanf("%d",&a[i]);
	sort(a,a+n,cmp);
	int ans=1;
//	for (int i=1;i<n;++i)
	bool flag=false;
	while(a[ans-1]-a[ans]<=k&&ans<n){
		++ans;
		flag=true;
	}
	
	cout << ans << endl;
}
	
	
int main(){
	scanf("%d",&t);
	for (int i=0;i<t;++i) solve();
	return 0;
}