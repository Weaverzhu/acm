#include<bits/stdc++.h>
using namespace std;

const int N1 = 2e5+5, N2 = N1*20;

int tot;
vector<int> v[N2];
int ls[N2], rs[N2];
int x[N1], y[N1];
int ans;

int check(int x1, int y1, int x2, int y2){
	if (1LL* (x1-x2)*(x1-x2) + 1LL* (y1-y2)*(y1-y2) < 1LL*y1*y1)
		return 1;
	else return 0;
}

void insert(int &now, int l, int r, int L, int R, int id){
	if (!now)
		now = ++tot;
	if (L <= l && R >= r){
		v[now].push_back(id);
		return;
	}
	int mid = (l+r) >> 1;
	if (L <= mid) insert(ls[now], l, mid, L, R, id);
	if (R > mid) insert(rs[now], mid+1, r, L, R, id);
}

void ask(int now, int l, int r, int xx, int yy){
	if (!now) return;
	for (int i=0; i<v[now].size(); ++i){
		if (check(x[v[now][i]], y[v[now][i]], xx, yy)){
			ans = v[now][i];
			return;
		}
	}
	if (l == r) return;
	int mid = (l+r) >> 1;
	if (xx <= mid) ask(ls[now], l, mid, xx, yy);
	else ask(rs[now], mid+1, r, xx, yy);
}

void del(int now, int l, int r, int L, int R){
	if (L <= l && r <= R){
		vector<int> y;
		for (int i=0; i<v[now].size(); ++i)
			if (v[now][i] != ans) y.push_back(v[now][i]);
		v[now] = y;
		return;
	}
	int mid = (l+r) >> 1;
	if (L <= mid) del(ls[now], l, mid, L, R);
	if (R > mid) del(rs[now], mid+1, r, L, R);
}

int main(){
	// freopen("in.txt", "r", stdin);

	int n;
	scanf("%d", &n);
	int rt = 0;
	tot = 0;
	for (int i=1; i<=n; ++i){
		int t, xx, yy;
		scanf("%d%d%d", &t, &xx, &yy);
		if (t == 1){
			x[i] = xx; y[i] = yy;
			insert(rt, -1e9, 1e9, xx-yy, xx+yy, i);
		}else{
			ans = -1;
			ask(rt, -1e9, 1e9, xx, yy);
			printf("%d\n", ans);
			if (ans != -1)
				del(rt, -1e9, 1e9, x[ans]-y[ans], x[ans]+y[ans]);
		}
	}
	return 0;
}
