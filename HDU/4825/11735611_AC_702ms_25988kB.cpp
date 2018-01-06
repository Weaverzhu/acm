#include<bits/stdc++.h>
using namespace std;

const int SZ = 2, maxn = 1000005;
typedef long long LL;

class Trie{
public:
	LL dat[3*maxn][SZ], cnt;
	void init(){
		memset(dat[0], -1, sizeof(dat[0]));
		cnt = 1;
	}
	void insert(int a[], int len){
		// for (int i=0; i<len; ++i)
		// 	printf("%d", a[i]);
		// printf("\n");
		int now = 0;
		for (int i=0; i<len; ++i){
			int x = a[i];
			if (dat[now][x] == -1){
				dat[now][x] = cnt;
				memset(dat[cnt], -1, sizeof(dat[cnt]));
				now = cnt++;
			}else now = dat[now][x];
		}
	}
	LL query(int a[], int len){
		// for (int i=0; i<len; ++i)
		// 	printf("%d", a[i]);
		// printf("\n");
		long long res = 0;
		int now=0, x;
		for (int i=0; i<len; ++i){
			x = (a[i]+1)%2;
			if (dat[now][x] != -1){
				res = res * 2 + x;
				
				now = dat[now][x];
			}else if (dat[now][a[i]] != -1){
				res = res * 2 + a[i];
				now = dat[now][a[i]];
			}
		}
		return res;
	}
} xorTrie;
LL p[100];
void i2a(int x, int a[]){
	for (int i=0; i<=32; ++i)
		a[i] = 0;
	for(int i=32; i>=0; --i){
		if (x/p[i]%2) a[32-i] = 1;
	}
	return;
}

int main(){

	// cout << (4^1) << endl;
	p[0] = 1;
	for (int i=1; i<=32; ++i)
		p[i] = p[i-1]*2;
	int t, n, m;
	cin >> t;
	for (int kase=1; kase<=t; ++kase){
		xorTrie.init();
		printf("Case #%d:\n", kase);
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i){
			int tmp[100];
			LL x;
			scanf("%I64d", &x);
			i2a(x, tmp);
			xorTrie.insert(tmp, 33);
		}
		// cout << xorTrie.dat[0][0] << endl;
		for (int i=0; i<m; ++i){
			LL x;
			scanf("%I64d", &x);
			int tmp[100];
			i2a(x, tmp);
			printf("%I64d\n", xorTrie.query(tmp, 33));
		}
	}
	return 0;
}