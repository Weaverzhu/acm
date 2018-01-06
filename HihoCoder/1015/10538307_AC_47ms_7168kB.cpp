
#include<iostream>
#include<string>
#include<cstring>
const int maxn = 1e4 + 10;
using namespace std;
string a, b;
int la, lb;
int nex[maxn];


int kmp() {
	int ans = 0;
	memset(nex, 0, sizeof(nex));
	for (int i = 1; i < lb; ++i) {
		if (b[nex[i - 1]] == b[i]) nex[i] = nex[i - 1] + 1;
		else nex[i] = 0;
	}
	int now = 0, j = 0;
	while (now + j < la) {
		if (a[now + j] == b[j]) {
			++j;

			if (j == lb) {
				++ans;
				now += j - nex[j - 1];
				j = nex[j - 1];
			}
			if (now + j >= la) break;
		}else {
			if (nex[j - 1] == 0 || j == 0) {
				++now;
				j = 0;
			}
			else {
				now += j - nex[j - 1];
				j = nex[j - 1];
			}
		}
		
	}
	return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> b;
		cin >> a;
		la = a.length(); lb = b.length();
		cout<<kmp()<<endl;



	}

    return 0;
}

