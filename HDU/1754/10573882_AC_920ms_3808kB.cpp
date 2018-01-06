// hdu1754.cpp : ¶¨Òå¿ØÖÆÌ¨Ó¦ÓÃ³ÌÐòµÄÈë¿Úµã¡£
//
#include<bits/stdc++.h>
using namespace std;

const int maxn = 3 * 1e6;
int a[maxn + 10];
int n, m, N;
void init() {
	N = 1;
	while (N < n) {
		N <<= 1;
	}
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		a[i + N] = tmp;
	}
	for (int i = N - 1; i >= 1; --i) {
		a[i] = max(a[2 * i], a[2 * i + 1]);
	}

}
void change(int index, int key) {
	a[index + N] = key;
	int now = index + N;
	while (now != 1) {
		now /= 2;
		a[now] = max(a[2 * now], a[2 * now + 1]);
	}
}

int q(int aa, int bb, int l, int r, int now){
	if (bb<l || aa>r) return 0;
	else if (aa <= l&&bb >= r) return (a[now]);
	else {
		int ans = 0;
		if (now * 2 <= n + N - 1) ans = max(ans, q(aa, bb, l, (l + r) / 2, 2 * now));
		if (now * 2 + 1 <= n + N - 1) ans = max(ans, q(aa, bb, (l + r) / 2 + 1, r, 2 * now + 1));
		return ans;
	}
}
int main()
{
	//ios::sync_with_stdio = false;
	ios::sync_with_stdio(false);
	//cin >> n;
	//system("pause");
	while(cin>>n>>m)
	{
		init();
		int li, ri;
		for (int i = 1; i <= m; ++i) {
			char ch=' ';
			while(ch<'A'||ch>'Z') cin>>ch;
			cin >> li >> ri;
	
			if (ch == 'U') change(li-1, ri);
			if (ch == 'Q') {
				int ans = q(li, ri, 1, N, 1);
				cout << ans << endl;
			}
		}
	}
    return 0;
}
