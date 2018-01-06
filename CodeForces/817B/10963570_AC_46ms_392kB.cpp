#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

void solve(int n)
{
	int a[maxn + 10];
	for (int i=0; i<n; ++i) scanf("%d", &a[i]);
	sort(a, a+n);
	
	if (a[0]==a[1] && a[1]==a[2])
	{
		int cnt = 1;
		for (int i=1; i<n; ++i) 
			if (a[i] == a[0]) ++cnt;
		cout << 1LL*cnt*(cnt-1)*(cnt-2)/6 << endl;
	}
	else if (a[1] != a[2])
	{
		int cnt = 1;
		for (int i=3; i<n; ++i)
			if (a[i] == a[2]) ++cnt;
		cout << cnt << endl;
	}
	else if (a[0] != a[1] && a[1]==a[2])
	{
		int cnt = 1;
		for (int i=2; i<n; ++i)
			if (a[i] == a[1]) ++cnt;
		cout << 1LL*cnt*(cnt-1)/2 << endl;
	}
}

int main()
{
	int n;
	while(scanf("%d", &n) != -1) solve(n);
	return 0;

}