#include<bits/stdc++.h>
using namespace std;
const int maxn = 2010;
set<int> s;
int a[maxn], b[maxn], n;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", &a[i]), s.insert(a[i]); 
	for (int i=1; i<=n; ++i) scanf("%d", &b[i]), s.insert(b[i]);
	
	int cnt = 0;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
		{
			int tmp = a[i]^b[j];
			if (s.count(tmp)) ++cnt;
		}
	if (cnt%2) cout << "Koyomi" << endl;
	else cout << "Karen" << endl;
//	cout << cnt << endl;
	return 0;
}