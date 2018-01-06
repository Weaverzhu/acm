#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100000+5;
LL a[maxn], sum, n;
LL ans[maxn], cnt, tmp[maxn], cnt1;
LL prime[maxn*10], pcnt;
bool isprime[maxn*10];



void solve(){
	sum = 0; cnt = 0;
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		scanf("%d", &a[i]);
		sum += a[i];
	}

	for (int i=0; i < pcnt; ++i){
		if (sum % prime[i] == 0){
			// cout << i << endl;
			ans[cnt++] = prime[i];
			while(sum % prime[i] == 0) sum /= prime[i];

		}
		// cout << sum << endl;
	}
	if (sum > 1) ans[cnt++] = sum;
	sort(ans, ans+cnt);
	LL res = 1e10+10;

	for (int i=0; i<cnt; ++i){

		LL nowp = ans[i], sum1 = 0, sum2 = 0;
		cnt1 = 0;
		for (int j=0; j<n; ++j){
			if (a[j] % nowp != 0){
				tmp[cnt1++] = a[j] % nowp;
				sum2 += a[j] % nowp;
			}
		}
		sort(tmp, tmp+cnt1);
		// cout << sum2 << endl;
		for (int j=cnt1-1; j>=0; --j){
			sum2 -= nowp;
			sum1 += nowp-tmp[j];
			if (sum2 <= 0) break;
		}
		res = min(res, sum1);
	}
	cout << res << endl;




}

int main(){
	int m1 = 1e6;
	memset(isprime, true, sizeof(isprime));
	for (int i=2; i<=m1; ++i)
		if (isprime[i])
		{
			prime[pcnt++] = i;
			for (int j=2*i; j<= m1; j+=i)
				isprime[j] = false;
		}
	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}