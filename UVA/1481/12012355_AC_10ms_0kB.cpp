#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
int a[N], b[N], c[N];
int n;
int main(){
	while(~scanf("%d", &n)){
		if (n == 0) break;
		for (int i=1; i<=n; ++i)
			scanf("%d", &a[i]);
		for (int i=1; i<=n; ++i)
			scanf("%d", &b[i]);

		for (int i=1; i<=n; ++i)
			c[b[i]] = i;
		int ans = 0;
		for (int i=1; i<=n; ++i){
			int l = c[a[i]], r = c[a[i]];
			// if (l == r) ++ans;
			for (int j=i+1; j<=n; ++j){
				if (c[a[j]] < l) l = c[a[j]];
				if (c[a[j]] > r) r = c[a[j]];
				
				if (j-i == r-l) ++ans;
			}
		}
		cout << ans << endl;
	}


	return 0;
}