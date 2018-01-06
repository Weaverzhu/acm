#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 1e6+5;
int a[maxn];
int main(){
	while(scanf("%d", &n) != -1){
		if (n == 0) break;
		a[1] = 3; a[2] = 1;
		if (n % 2){
			for (int i=3; i<=n-2; i+=2)
				a[i] = i+2;
			a[n] = n-1;
			for (int i=n-1; i>=4; i-=2)
				a[i] = i-2;
		}else{
			for (int i=3; i<=n-2; i+=2)
				a[i] = i+2;
			a[n-1] = n;
			for (int i=n; i>=4; i-=2)
				a[i] = i-2;
		}
		printf("%d", a[1]);
		for (int i=2; i<=n; ++i)
			printf(" %d", a[i]);
		printf("\n");
	}


	return 0;
}