#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef long long LL;
class BIT0{
public:
	LL n, dat[maxn];
	int lowbit(int x){return x & (-x);}
	void init(int n_){
		n = n_;
		memset(dat, 0, sizeof(dat));
	}
	void add(int i, int x){
		for (int j=i; j<=maxn-1;j+=lowbit(j))
			dat[j] += x;
	}
	LL sum(int i){
		LL res = 0;
		for (int j=i; j>0; j-=lowbit(j))
			res += dat[j];
		return res;
	}
} p;
int pos[maxn];
int main(){
	int n, m, t;
	cin >> t;
	while(scanf("%d%d", &n, &m) != -1){
		p.init(n);
		for (int i=1; i<=n; ++i){
			pos[i] = n-i+1;
			p.add(pos[i], 1);
		}
		int N = n;
		for (int i=1; i<=m; ++i){
			int j;
			scanf("%d", &j);
			// printf("pos[%d] = %d\n", j, pos[j]);
			// printf("n = %d sum(pos[j]) = %d ", n, p.sum(pos[j]));
			printf("%lld", n-p.sum(pos[j]));
			if (i == m) printf("\n");
			else printf(" ");
			p.add(pos[j], -1);
			pos[j] = ++N;
			p.add(pos[j], 1);
		}
	}
	return 0;
}