#include<bits/stdc++.h>
using namespace std;
const int maxn = 5 * (1e5) + 10;
const int INF = 0x3f3f3f3f;
int n, N;
struct Tnode{
	int maxv, minv;
	long long sumv;
};
struct segmentT{
	Tnode dat[30000000];
	void init(int n_){
		N = 1;
		while (N < n_) N *= 2;
		for (int i=0; i<2*N-1; ++i)
			dat[i] = (Tnode){
				-INF, INF, 0
			};
	}
	void update(int k, int a){
		k += N-1;
		dat[k] = {
			a, a, a
		};
		while(k){
			k = (k-1)/2;
			int ls = k*2+1, rs = k*2+2;
			dat[k].maxv = max(dat[ls].maxv, dat[rs].maxv);
			dat[k].minv = min(dat[ls].minv, dat[rs].minv);
			dat[k].sumv = dat[ls].sumv+dat[rs].sumv;
		}
	}
	void query(int &amax, int &amin, long long &asum, int a, int b, int k, int l, int r){
		int tmax, tmin, tmax1, tmin1;
		long long tsum=0, tsum1=0;
		if (r <= a || b <= l){
			amax = -INF, amin = INF, asum = 0;
			return; 
		}else if (a <= l && r <= b){
			amax = dat[k].maxv;
			amin = dat[k].minv;
			asum = dat[k].sumv;
			return;
		}else{
			query(tmax, tmin, tsum, a, b, k*2+1, l, (l+r)/2);
			query(tmax1, tmin1, tsum1, a, b, k*2+2, (l+r)/2, r);
			amax = max(tmax, tmax1);
			amin = min(tmin, tmin1);
			asum = tsum+tsum1;
			return;
		}
	}
} SegmentTree;

int main()
{
	// freopen("in.txt", "r", stdin);
	while(scanf("%d", &n) != -1){
		int m;
		scanf("%d", &m);
		SegmentTree.init(n);
		for (int i=1; i<=n; ++i){
			int tmp;
			scanf("%d", &tmp);
			SegmentTree.update(i-1, tmp);
		}
		// printf("N = %d\n", N);
		// for (int i=0; i<2*N-1; ++i){
		// 	printf("%d %d %lld\n", SegmentTree.dat[i].maxv, SegmentTree.dat[i].minv, SegmentTree.dat[i].sumv);
		// }
		// int m;
		
		for (int i=0; i<m; ++i){
			int op, a, b;
			scanf("%d%d%d", &op, &a, &b);
			if (op == 1){
				SegmentTree.update(a-1, b);
				// for (int i=0; i<2*N-1; ++i){
				// 	printf("%d %d %lld\n", SegmentTree.dat[i].maxv, SegmentTree.dat[i].minv, SegmentTree.dat[i].sumv);
				// }
			}
			else{
				int ans1, ans2;
				long long ans3;
				SegmentTree.query(ans1, ans2, ans3, a-1, b, 0, 0, N);
				printf("%lld\n", ans3);
			}
		}
	}

	return 0;
}