
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
void solve() {
	long long n, m;
	long long ans = 0;
	scanf("%lld%lld", &n, &m);
	if (m <= n - 1) {
		long long t1 = m, t2 = n - m - 1;
//		ans+=2*t1+2*t1*(t1-1)
		ans = 2 * m*m+t2*(n-1)*n+(m+1)*t2*n;
		cout << ans << endl;
		return;
	}
	else if((m>n-1) && (m<(n*(n-1)))){
		ans = 2 * n*(n - 1) - 2*m;
		cout << ans << endl;
		return;
	}
	else if (m >= (n*(n - 1))) {
		ans = n*(n - 1);
		cout << ans << endl;
		return;

	}
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) solve();
//	system("pause");
    return 0;
}

