#include<bits/stdc++.h>
using namespace std;
const int N = 2e6;
int a[N], s[N], n, p, key[N];
char s1[N], s2[N];

struct Bit{
	int dat[N*2];
	void init(){memset(dat, 0, sizeof(dat));}
	int lowbit(int x) {return x & -x;}
	void add(int i, int x){
//	    printf("add(%d, %d)\n", i, x);
		for(; i<=N; i+=lowbit(i))
			dat[i] += x;
	}
    int sum(int i){
		int res = 0;
		for (; i>0; i-=lowbit(i))
			res += dat[i];
		return res;
	}
} bit;



struct node{
	int v, pos;
	bool operator < (const node &b) const {
		if (v != b.v)
			return v > b.v;
		return pos < b.pos;
	}
} dat[N];

void init(){
	bit.init();
	memset(a, 0, sizeof(a));
	memset(s, 0, sizeof(s));
	memset(key, 0 ,sizeof(key));
	memset(dat, 0, sizeof(dat));
//	puts("fuck");
}

int main(){

	while(~scanf("%d%d", &n, &p)){
		init();
		scanf("%s", s1);
		scanf("%s", s2);
		s1[n] = s2[n] = 0;

		for (int i=0; i<n; ++i){
			if (s1[i] != s2[i]) a[i+1] = 1;
		}

		if (n == 0 && p == 0) break;

		for (int i=1; i<=n; ++i){
			s[i] = s[i-1] + a[i];
			key[i] = 100*s[i] - p*i;
		}
		for (int i=1; i<=n; ++i){
			dat[i] = (node){key[i], i};
		}
		sort(dat+1, dat+n+1);

		bit.add(dat[1].pos, 1);
		int ans = -1;

		for (int i=2; i<=n; ++i){
            if (i == 6){
                i = 6;
            }
			int nposs = dat[i].pos;
			if (bit.sum(1) == 1) {
				ans = max(ans, nposs);
				bit.add(nposs, 1);
				continue;
			}
			if (bit.sum(nposs-1) == 0){
                bit.add(nposs, 1);
				continue;
			}
			if (i == 7){
                i = 7;
			}
			int l = 1, r = nposs-1;
			while(l < r-1){
				int mid = (l+r) >> 1, res = bit.sum(mid);
				if (res > 0) r = mid;
				else l = mid;
			}
			ans = max(ans, nposs-r);
			bit.add(nposs, 1);

		}
        if (ans == -1){
            printf("No solution.\n");
        }else
            printf("%d\n", ans);
	}



	return 0;
}
