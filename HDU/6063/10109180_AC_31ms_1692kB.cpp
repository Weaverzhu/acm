#include<cstdio>
#include<iostream>
using namespace std;
#define ll long long
const int mod = 1e9+7;
ll fastpow(ll a, ll b){
	ll res=1,temp=a%mod;
	while(b){
		if (b%2)res=res*temp%mod;
		b/=2;
		temp=temp*temp%mod;
	}
	return res;
}
int main(){
	ll n,k;
	int kase=0;
	while(scanf("%lld%lld",&n,&k)!=EOF){
		printf("Case #%d: %lld\n",++kase,fastpow(n,k));
	}
	return 0;
}