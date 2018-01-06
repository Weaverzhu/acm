#include<cstdio>
#include<iostream>
using namespace std;
const int M = 1e9+7;
typedef long long ll;
ll n,k,s;
ll power(ll a, ll b){
	ll n = a %M, k = b , s = 1;
	while (k){
		if (k % 2) s = s * n % M;
		n = n * n % M;
		k /= 2;
	}
	return s;
}
int main(){
	int kase = 0;
	while(scanf("%lld",&n)!=EOF){
		++kase;
		scanf("%lld",&k);
		s = power(n,k);
		printf("Case #%d: %lld\n", kase, s);
		
		
	}
	return 0;
}