#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
LL a[20], b[20];
LL n, delta, pa, sb;
LL ans;
void dfs(int now){
	if (now == n+1){

		if (sb == 0) return;
		// cout << pa << endl << sb << endl;cout << pa << endl << sb << endl;
		delta = pa>sb? pa-sb : sb-pa;
		if (delta<ans) ans = delta;
		return;
	}
	for (int r=0; r<=1; ++r){
		if (r == 1){
			pa *= a[now]; sb += b[now];
			dfs(now+1);
			pa /= a[now]; sb -= b[now];
		}else{
			dfs(now+1);
		}
	}
}

int main(){
	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> a[i] >> b[i];
	ans = 1e18;
	delta = 0; pa = 1; sb = 0;
	dfs(1);
	cout << ans << endl;
	return 0;
}