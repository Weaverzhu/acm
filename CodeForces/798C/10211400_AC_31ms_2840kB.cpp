#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll a[maxn];
ll n,ans=0;
ll gcd(ll a,ll b){
	ll c;
	while (b>0){
		c=a%b;
		a=b;b=c;
	}
	return a;
}
ll abss(ll a){
	return a<0?-a:a;
}
int main(){
	cout << "YES\n";
	scanf("%I64d",&n);
	for (int i=1;i<=n;++i){
		scanf("%I64d",&a[i]);
		a[i]=abss(a[i]);
	}
	ll g=gcd(a[1],a[2]);
	for (int i=3;i<=n;++i){
		g=gcd(g,a[i]);
	}
	if (g>1){
		cout<<"0"<<endl;
		return 0;
	}
	for (int i=1;i<=n-1;++i){
		if (a[i]%2==1&&a[i+1]%2==1){
			ll t1=a[i],t2=a[i+1];
			a[i]=t1-t2;a[i+1]=t1+t2;
			a[i]=abss(a[i]);
			a[i+1]=abss(a[i+1]);
			++ans;
		}
	}
	for (int i=1;i<=n-1;++i){
		ll s=0;
		if (a[i]%2)++s;
		if (a[i+1]%2)++s;
		if (s==1){
			ll t1=a[i],t2=a[i+1];
			a[i]=t1-t2;a[i+1]=t1+t2;
			a[i]=abss(a[i]);
			a[i+1]=abss(a[i+1]);
			t1=a[i];t2=a[i+1];
			a[i]=t1-t2;a[i+1]=t1+t2;
			a[i]=abss(a[i]);
			a[i+1]=abss(a[i+1]);
			ans+=2;
		}
	}
	cout << ans<<endl;
//	cout << -1%2<<endl;
	return 0;
}