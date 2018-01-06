#include<bits/stdc++.h>
using namespace std;
#define lc i<<1
#define rc i<<1|1
const int maxn = 5e5+5;
typedef long long LL;
LL val[maxn];
struct tnode{
	LL v;
	int lzx, lz;
};
struct SegT{
	int n, N;
	tnode dat[maxn];
	void init(int n_){
		n = n_;
		N = 1;
		while(N < n) N <<= 1;
		for (int i=1; i<=n; ++i){
			dat[N+i-1].v = val[i];
			dat[N+i-1].lzx = -1;
			dat[N+i-1].lz = 0;
		}
		for (int i=N-1; i>=0; --i){
			dat[i].v = dat[lc].v + dat[rc].v;
			dat[i].lz = 0; dat[i].lzx = -1;
		}
	}
	void u0(int i, LL x){
		i += N-1;
		dat[i].v = x;
		while(i > 0){
			i = i >> 1;
			dat[i].v = dat[lc].v + dat[rc].v;
		}
	}
	void lazy(int i){
		if (dat[i].lzx != -1){
			dat[lc].lzx = dat[i].lzx; dat[rc].lzx = dat[i].lzx;
			dat[lc].v = dat[i].lzx; dat[rc].v = dat[i].lzx;
			dat[i].lzx = -1;
		}
	}
	void u1(int i, int l, int r, int L, int R, LL x){
		int mid = (l+r) >> 1;
		if (l == L && r == R){
			dat[i].lzx = x;
			dat[i].v = x;
			return;
		}
		lazy(i);
		if (R <= mid) u1(lc, l, mid, L, R, x);
		else if (L > mid) u1(rc, mid+1, r, L, R, x);
		else u1(lc, l, mid, L, mid, x), u1(rc, mid+1, r, mid+1, R, x);
		dat[i].v = dat[lc].v + dat[rc].v;
	}
	LL q0(int i, int l, int r, int L, int R){
		int mid = (l+r) >> 1;
		if (L <= l && r <= R){
			return dat[i].v;
		}else if (r < L || l > R) return 0;
		else{
			LL vl = q0(lc, l, mid, L, R),
			vr = q0(rc, mid+1, r, L, R);
			return vl+vr;
		}
	}
	void output(int i, int j){
		i += N-1; j += N-1;
		for (int k=i; k<=j; ++k)
			printf("%d ", dat[k]);
		printf("\n");
	}
} tr;

int main(){
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; ++i){
		scanf("%lld", &val[i]);
	}
	int q;
	tr.init(n);
	scanf("%d", &q);
	for (int kk=1; kk<=q; ++kk){
		int op, l, r, x;
		scanf("%d", &op);
		if (op == 1){
			scanf("%d%d%d", &l, &r, &x);
			tr.u1(1, 1, tr.N, l, r, x);
			tr.output(1, tr.N);
		}else if (op == 2){
			printf("%lld\n", tr.q0(1, 1, tr.N, l, r));
		}
	}

	return 0;
}