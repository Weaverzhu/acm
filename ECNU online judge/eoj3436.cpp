#include<bits/stdc++.h>
using namespace std;
const int maxn = 1500000, M = 1e6;
int prime[maxn], p_cnt;
bool isprime[maxn];
void getPrime(){
	p_cnt = 0;
	// memset(isprime, 1, sizeof(isprime));
	for (int i=2; i<=M; ++i){
		if (!isprime[i]){
			prime[p_cnt++] = i;
			for (int j=i; j<=M; j+=i)
				isprime[j] = true;
		}
	}
}
typedef long long LL;
LL b[maxn], x, y;

LL pmd(int a, int b){
	LL res = 1;
	while(b){
		if (b%2) res*=a;
		a = a*a;
		b >>= 1;
	}
	// cout << "pmd\n" << endl;
	return res;
}
LL a[maxn];
int main(){
	freopen("in.txt", "r", stdin);
	getPrime();
	cin >> x >> y;
	LL ans = 0;
	if (x == 1 && y == 1)
	{
		cout << 1 << endl;
		return 0;
	}else if (x == 1){
		ans = 1; ++x;
	}
	LL len = y-x+1;
	for (int i=0; i<len; ++i)
		b[i] = 1;
	for (LL i=0; i<len; ++i)
		a[i] = i+x;
	for (int i=0; i<p_cnt; ++i){
		int now = prime[i];
		LL st;
		if (x%now==0) st = 0;
		else st = (x/now+1)*now-x;

		// cerr << st << endl;
		for (int j=st; j<len; ++j){
			if (a[j]%now == 0){
				// cout << a[j] << endl;
				int cnt = 0;
				while(a[j]%now==0) a[j]/=now, ++cnt;
				// cout << pmd(now, cnt+1) << endl;

				b[j] *= (pmd(now, cnt+1)-1)/(now-1);
				// cout << b[j-x] << endl;
			}
		}
	}
	for (int i=0; i<len; ++i)
		if (a[i]>1) b[i] *= (a[i]+1);

	for (int i=0; i<len; ++i)
		ans += b[i];
	cout << ans << endl;

	return 0;
}