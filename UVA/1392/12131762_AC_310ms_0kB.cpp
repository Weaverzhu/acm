#include<bits/stdc++.h>
using namespace std;

const int N = 2e6;

char s1[N], s2[N];
int n, q, a[N], s[N], key[N];

struct Bit{
	int dat[N*2];
	inline int lowbit(int x){return x & -x;}
	inline void add(int i, int x){
		for (; i<=N; i+=lowbit(i)){
			dat[i] += x;
		}
	}
	inline int sum(int i){
		int res = 0;
		for(; i>0; i-=lowbit(i)){
			res += dat[i];
		}
		return res;
	}
	inline void init(){
		memset(dat, 0, sizeof(dat));
	}
} bit;

struct node {
	int v, pos;
	bool operator < (const node &b) const {
		if (v != b.v) return v > b.v;
		return pos < b.pos;
	}
} dat[N];


void init(){
	bit.init();
	s[0] = 0;
	memset(a, 0, sizeof(a));
}

int main(){

	while(~scanf("%d%d", &n, &q)){
		if (n == 0 && q == 0)
			break;
		init();

		scanf("%s%s", s1, s2);
		for (int i=0; i<n; ++i){
			if (s1[i] != s2[i]){
				a[i+1] = 1;
			}
		}
		for (int i=1; i<=n; ++i){
			s[i] = s[i-1] + a[i];
			key[i] = 100*s[i] - q*i;
			dat[i] = (node){key[i], i};
		}

		sort(dat+1, dat+n+1);
		int ans = -1;
		// cout << s[n] << endl;
		if (s[n] < n) ans = 1;
		bit.add(dat[1].pos, 1);
		for (int i=2; i<=n; ++i){
			int npos = dat[i].pos;
			bit.add(npos, 1);
			if (npos == 1)
				continue;
			if (bit.sum(1) == 1){
				ans = max(ans, npos);
				// if (ans != -1){
				// 	printf("i = %d\n", i);
				// 	printf("%d\n", dat[i].pos);
				// }
				continue;
			}
			if (bit.sum(npos-1) == 0){
				continue;
			}
			int l = 1, r = npos-1;

			while(l < r-1){
				int mid = (l+r) >> 1;
				if (bit.sum(mid)) r = mid;
				else l = mid;
			}
			ans = max(ans, npos - r);
			// printf("i = %d\n", i);
			// printf("%d\n", dat[i].pos);
		}
		if (ans == -1){
			printf("No solution.\n");

		}else
			printf("%d\n", ans);

	}

	return 0;
}