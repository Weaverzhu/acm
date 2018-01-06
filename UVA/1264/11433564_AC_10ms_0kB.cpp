#include<bits/stdc++.h>
using namespace std;

const int N = 25;
const int MOD = 9999991;
struct bst{
	int l, r, v, lsz, rsz;
	bst(){
		l = 0, r = 0, v = -1, lsz = 0, rsz = 0;
	}
};
bst dat[N];
int c[30][30];
int cnt;
void add_bst(int x, int v){
	if (dat[x].v == -1){
		dat[x].v = v;
		return;
	}else if(dat[x].v > v){
		if (dat[x].l != 0)
			add_bst(dat[x].l, v);
		else{
			dat[++cnt] = bst();
			dat[x].l = cnt;
			add_bst(dat[x].l, v);
			
		}
		dat[x].lsz++;
	}else if(v > dat[x].v){
		if (dat[x].r != 0)
			add_bst(dat[x].r, v);
		else{
			dat[++cnt] = bst();
			dat[x].r = cnt;
			add_bst(dat[x].r, v);
			
		}
		dat[x].rsz++;
	}
}
void print_bst(const bst &a){
	printf("l=%d r=%d v=%d lsz=%d rsz=%d\n", a.l, a.r, a.v, a.lsz, a.rsz);
}
long long dfs(int x){
	if (!x) return 1LL;
	// print_bst(dat[x]);
	int ls = dat[x].lsz, rs = dat[x].rsz;
	long long ansl = dfs(dat[x].l), ansr = dfs(dat[x].r);
	long long ans = ansl * ansr % MOD * c[ls][ls + rs] % MOD;
	// printf("x=%d ansl=%d ansr=%d ls=%d rs=%d\n",x, ansl, ansr, ls, rs);
	// printf("debug\n");
	return ans;
}

int n;
void solve(){
	// printf("debug\n");
	scanf("%d", &n);
	dat[1] = bst();
	cnt = 1;

	int rootv, tmp;
	scanf("%d", &rootv);
	dat[1].v = rootv;
	// print_bst(dat[cnt]);
	for (int i=2; i<=n; ++i){
		scanf("%d", &tmp);
		add_bst(1, tmp);
		// print_bst(dat[1]);
		// printf("debug\n");
	}
	// printf("debug\n");
	// print_bst(dat[1]);
	cout << dfs(1) << endl;
}

int main(){
	int t;
	c[0][0] = 1;
	c[0][1] = c[1][1] = 1;
	for (int i=2; i<=20; ++i){
		c[0][i] = c[i][i] = 1;
		for (int j=1; j<i; ++j)
			c[j][i] = c[j-1][i-1]+c[j][i-1],
			c[j][i] = c[j][i] % MOD;
	}
	cin >> t;
	while(t--)
		solve();
	return 0;
}