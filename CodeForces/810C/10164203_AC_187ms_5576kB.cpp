#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 3*(1e5)+10;
const int m = 1e9+7;
typedef long long ll;
int n;
int a[maxn];
ll sum[maxn],ss;
ll pow(int k){
	ll f=2,ans=1,b=k;
	while(b){
		if(b%2)ans=ans*f%m;
		f=f*f%m;
		b/=2;
	}
	ans=ans%m;
	return ans;
}
		
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	sort(a,a+n);
	ss = 0;
	sum[0]=a[0];
	ll ans=0;
	for(int i=1;i<n;++i)sum[i]=sum[i-1]+a[i];
//	for (int i=0;i<n;++i) printf("%lld ",sum[i]);
	for (int i=0;i<=n-2;++i){
		ll t1=sum[n-1]-sum[n-1-i-1]-sum[i];
		t1=t1%m;
		ll t2=pow(i);
		ans=(ans+t1*t2)%m;
	}
	cout << ans << endl;
	return 0;
}