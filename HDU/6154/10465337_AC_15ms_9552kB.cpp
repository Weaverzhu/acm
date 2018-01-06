// hdu6154.cpp : 定义控制台应用程序的入口点。
//

#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e6 + 10;
double d[maxn];
void init() {
	for (int i = 0; i < 4; ++i) d[i] = 0;
	d[4] = 2; d[5] = 2.5; d[6] = 4; d[7] = 5.5;
	for (int i = 8; i <= maxn; i += 4) {
		d[i] = ((double)i*i) / 8.0;
		d[i + 1] = d[i] + (double)(i - 2) / 4 + 1;
		d[i + 2] = d[i + 1] + (double)(i - 2) / 4 + 1;
		d[i + 3] = d[i + 2] + (double)(i - 2) / 4 + 1;
	}

}
int main()
{
	ios::sync_with_stdio(false);
	init();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << lower_bound(d, d + maxn - 10, n) - d << endl;
	}
	return 0;
}

