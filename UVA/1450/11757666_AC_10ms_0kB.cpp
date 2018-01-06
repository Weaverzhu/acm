#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N], b[N];
int n;
int main(){

	int t;
	cin >> t;
	for (int q=0; q<t; ++q) {
		scanf("%d", &n);
		for (int i=1; i<=n; ++i){
			scanf("%d%d", &a[i], &b[i]);
		}
		int l = 1, r = 20*N, ans = -1, mid;
		while(l<=r){
			mid = (l+r) >> 1;
			bool suc = true;
			int cnta = 0, cntb = 0, res = 0;
			for (int i=1; i<=n; ++i){
				cnta += a[i];
				cntb += b[i];
				int ta = max(cnta-mid, 0),
				tb = max(cntb-mid, 0);
				if (ta+tb > res) {
					suc = false; break;
				}
				if (cnta && cntb && cnta+cntb > res)
					++res;
				else if (cnta && cntb == 0) --cnta;
				else if (cntb && cnta == 0) --cntb;

			}
			if (suc){
				ans = mid;
				r = mid-1;
			}else l = mid+1;
		}
		cout << ans-1 << endl;
	}


	return 0;
}