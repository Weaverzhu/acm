#include<bits/stdc++.h>
using namespace std;
const int maxn = 5000000+5;
typedef long long LL;
const int INF = 0x3f3f3f3f;
class SegT{
public:
	LL dat[maxn], n, N;
	void init(int n_){
		n = n_;
		N = 1;
		while(N < n) N <<= 1;
		memset(dat, INF, sizeof(dat));
		int x;
		for (int i=0; i<n; ++i){
			scanf("%d", &x);
			dat[i+N-1] = x;
		}

		for (int i=N-2; i>=0; --i){
			dat[i] = min(dat[i*2+1], dat[i*2+2]);
		}
	}
	void up1(int i, int x){
		i += N-1;
		dat[i] = x;
		while(i){
			i = (i-1)>>1;
			dat[i] = min(dat[i*2+1], dat[i*2+2]);
		}
	}
	LL q(int a, int b, int i, int l, int r){
		if (b <= l || r <= a)
			return INF;
		else if (a <= l && r <= b)
			return dat[i];
		else{
			LL vl = q(a, b, i*2+1, l, (l+r)/2),
			vr = q(a, b, i*2+2, (l+r)/2, r);
			return min(vr, vl);
		}
	}
} segt;
int main(){
	int n, q;
	while(scanf("%d", &n)!=-1){
		segt.init(n);
		cin >> q;
		while(q--){
			int com, a, b;
			scanf("%d%d%d", &com, &a, &b);
			if (com == 0)
				cout << segt.q(a-1, b, 0, 0, segt.N) << endl;
			else segt.up1(a-1, b);
		}
	}
	return 0;
}