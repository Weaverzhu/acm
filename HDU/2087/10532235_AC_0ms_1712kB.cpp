
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
string a, b;
const int maxn = 1000 + 10;
int pre[maxn];
int la, lb;
void kmp() {
	int ans = 0;
	//memset(pre, 0, sizeof(pre));
	pre[0] = 0;
	for (int i = 1; i < lb; ++i) {
		if (b[i] == b[pre[i - 1]]) pre[i] = pre[i - 1] + 1;
		else pre[i] = 0;
	}
	//arr:pre
	int now = 0, j = 0;
	while (now + j < la) {
		if (a[now + j] == b[j]) {
			j++;
			if (j == lb) {
				++ans; now = now + j; j = 0;
			}
			if (now + j >= la) break;
		}
		else {
			if (pre[j - 1] == 0) ++now;
			else now += j - pre[j - 1];
			j = pre[j - 1];
		}
		if (now + j >= la) break;

	}
	cout << ans << endl;
	return;
}
int main()
{
	cin >> a;
	while (a != "#") {
		cin >> b;
		la = a.length(); lb = b.length();
		kmp();
		cin >> a;
	}

    return 0;
}

