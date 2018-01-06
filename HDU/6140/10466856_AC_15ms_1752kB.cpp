
#include<iostream>
#include<sstream>
#include<string>
#include<cstdio>
using namespace std;
const int maxn = 1e6 + 10;
int main()
{
	int aa;
	aa = 1;
	//int a[maxn];
	//ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		
		string line;
		getline(cin, line);
		getline(cin, line);
		istringstream istr1, istr2;
		istr1.str(line); 
		getline(cin, line);
		istr2.str(line); 
		int maxi = 0, mini = 0;
		string tmp; int a; bool flag = false;
		for (int i = 1; i <= n; ++i) {
			istr1 >> a; istr2 >> tmp;
			if (tmp[0] == 'N') {
				mini -= a; maxi += a;
			}
			else if (tmp[0] == 'L') maxi += a;
			else if (tmp[0] == 'D') mini -= a;
			if (maxi >= k && mini <= k) {
				flag = true; break;
			}

		}
		if (flag) cout << "yes\n";
		else cout << "no\n";
	}

    return 0;
}

