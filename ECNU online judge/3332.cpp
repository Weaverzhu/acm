#include<stdio.h>
long long n, k, a[70], b[70];
void init(){
	a[1] = 1; b[1] = 10%k;
	for (int i=2; i<=62; ++i){
		a[i] = a[i-1]*b[i-1]%k + a[i-1];
		a[i] = a[i]%k;
		b[i] = (b[i-1]*b[i-1])%k;
	}
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld", &n, &k);
		init();
		int now = 1;
		long long res = 0;

		while(n){
			if(n%2){
				res = res * b[now] + a[now];
				res = res % k;
			}
			now++;
			n /= 2;
		}
		printf("%lld\n", res);
	}
	return 0;
}