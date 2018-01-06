#include<bits/stdc++.h>
using namespace std;
int remain, n, k;
const int maxn = 100000+5;
int a[maxn];
void doit(int l, int r){
	if (remain == 1) return;
	int mid = (l+r)/2;
	int l1 = l, r1 = mid-1, l2 = mid, r2 = r-1;
	if (l+1 == r) return;
	if (remain == 1) return;
	remain -= 2;
	swap(a[r1], a[l2]);
	doit(l, mid);
	if (remain == 1) return;

	doit(mid, r);
}
void solve(){
	for (int i=1; i<=n; ++i){
		a[i] = i;
	}
	remain = k;
	if (remain%2 == 0){
		printf("-1\n");
		return;
	}
	doit(1, n+1);
	if (remain == 1){
		printf("%d", a[1]);
		for (int i=2; i<n; ++i) printf(" %d", a[i]);
		if (n>1) printf(" %d\n", a[n]);
		else printf("\n");
	}else printf("-1\n");
}

int main(){
	while(scanf("%d%d", &n, &k) != -1){
		solve();
	}
	return 0;
}