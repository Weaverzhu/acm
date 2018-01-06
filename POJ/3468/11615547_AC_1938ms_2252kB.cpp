#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100000;
typedef long long LL;


class BIT{
public:
	LL dat[maxn+5], n;
	void init(int n_){
		memset(dat, 0, sizeof(dat));
		n = n_;
	}
	int lowbit(int x){
		return x & (-x);
	}
	void add(int i, int x){
		for (int j=i; j<=n; j += lowbit(j)){
			dat[j] += x;
		}
	}
	LL sum(int a){
		if (a == 0)
			return 0;
		LL res = 0;
		for (int j=a; j>0; j -= lowbit(j)){
			res += dat[j];
		}
		return res;
	}
} bit0, bit1;

int main(){
	int n, q;
	while(scanf("%d%d", &n, &q) != -1){
		bit1.init(n); bit0.init(n);
		for (int i=1; i<=n; ++i){
			int x;
			scanf("%d", &x);
			bit0.add(i, x);
		}
		char com[10];
		
		for (int _q = 0; _q < q; ++_q){
			// segt.showsegt();
			scanf("%s", com);
			if (com[0] == 'Q'){
				int a, b;
				scanf("%d%d", &a, &b);
				LL res = bit0.sum(b)+bit1.sum(b)*b - bit1.sum(a-1)*(a-1)-bit0.sum(a-1);
				printf("%lld\n", res);
				
			}
			else if (com[0] == 'C'){
				int a, b, x;
				scanf("%d%d%d", &a, &b, &x);
				bit0.add(a, -x*(a-1));
				bit0.add(b+1, x*b);
				bit1.add(a, x);
				bit1.add(b+1, -x);
			}
		}
	}
	return 0;
}