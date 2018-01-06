#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100005
#define mid (r+l >> 1)
#define lc (d << 1)
#define rc ( d << 1 | 1)

struct Tr {
	int lz, v, lzx;
}tr[N << 2];
struct Q{
	int t, l, r, x;
}que[N];
int val[N];
void Push(int d){
	tr[d].v = max(tr[lc].v, tr[rc].v);
}
void build(int d, int l, int r){
	if (l == r){
		tr[d].v = val[l];
		tr[d].lz = 0, tr[d].lzx = -1;
		return;
	}
	tr[d].lz = 0, tr[d].lzx = -1;
	build(lc, l, mid);
	build(rc, mid+1, r);
	Push(d);
}
void lazy(int d){
	if (tr[d].lzx != -1){
		tr[lc].lzx = tr[d].lzx, tr[rc].lzx = tr[d].lzx;
		tr[lc].v = tr[d].lzx, tr[rc].v = tr[d].lzx;
		tr[d].lzx = -1;
	}
}
int cal(int a, int b){
	if (b == 0) return a;
	return cal(b, a%b);
}
void updatex(int d, int l, int r, int L, int R, int x, int t){
	if (l == L && r == R) {
		tr[d].lzx = x;
		tr[d].v = x;
		return;
	}
	lazy(d);
	if (R <= mid) updatex(lc, l, mid, L, R, x, t);
	else if (L > mid) updatex(rc, mid+1, r, L, R, x, t);
	else updatex(lc, l, mid, L, mid, x, t), updatex(rc, mid+1, r, mid+1, R, x, t);
	Push(d);
}
void update(int d, int l, int r, int L, int R, int x, int t){
	if (l == L && r == R){
		if (tr[d].v <= x) return;
		if (tr[d].lzx != -1){
			tr[d].lzx = cal(tr[d].lzx, x);
			tr[d].v = tr[d].lzx;
			if (l == r) val[l] = tr[d].lzx;
			return;
		}
		if (l == r){
			if (val[l] > x) val[l] = cal(val[l], x);
			return;
		}
		lazy(d);
		update(lc, l, mid, L, mid, x, t);
		update(rc, mid+1, r, mid+1, R, x, t);
		Push(d);
		return;
	}
	lazy(d);
	if (R <= mid) update(lc, l, mid, L, R, x, t);
	else if (L > mid) update(rc, mid+1, r, L, R, x, t);
	else update(lc, l, mid, L, mid, x, t), update(rc, mid+1, r, mid+1, R, x, t);
	Push(d);
}
void out(int d, int l, int r){
	if (tr[d].lzx != -1){
		for(int i=l; i<=r; ++i) printf("%d ", tr[d].lzx);
		return;
	}
	if (l == r){
		printf("%d ", val[l]);
		return;
	}
	lazy(d);
	out(lc, l, mid);
	out(rc, mid+1, r);
}
int main(){
	int T, n, i, j, m;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for (i=1; i<=n; ++i){
			scanf("%d", &val[i]);
		}
		build(1, 1, n);
		scanf("%d", &m);
		for (i=1; i<=m; ++i){
			scanf("%d%d%d%d", &que[i].t, &que[i].l, &que[i].r, &que[i].x);
		}
		for (i=1; i<=m; ++i){
			if (que[i].t == 1){
				updatex(1, 1, n, que[i].l, que[i].r, que[i].x, i);
			}else{
				update(1, 1, n, que[i].l, que[i].r, que[i].x, i);
			}
		}
		out(1, 1, n); puts("");
	}
}





