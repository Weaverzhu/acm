#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 400;
int a[N], s[N];
int main(){
	int n;
	cin >> n;
	for (int i=1; i<=n; ++i){
		cin >> a[i];
		s[i] = s[i-1]+a[i];
	}
	set<int> S;
	for (int i=1; i<=n; ++i){
		for (int j=i; j<=n; ++j)
			S.insert(s[j]-s[i]);
	}
	set<int>::iterator it;
	int now, ans = 0x3f3f3f3f;
	for (it = S.begin(); it != S.end(); ++it){
		int x = *it;
		int now = abs(x-(360-x));
		if (now < ans) ans = now;
	}
	cout << ans << endl;

	return 0;
}