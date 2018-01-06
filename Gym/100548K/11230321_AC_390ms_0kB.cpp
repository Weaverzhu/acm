#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i=1; i<=t; ++i)
	{
		printf("Case #%d: ", i);
		// set<long long> s;
		long long a, b, ans=0;
		scanf("%I64d%I64d", &a, &b);
		if (a==0 && b==0){cout << 1 << endl; continue;}
		if (a==0 || b==0) {cout << 2 << endl; continue;}
		if (a==b) {cout << 2 << endl; continue;}
		while(b)
		{
			ans += a/b;
			a = a % b;
			if (a<b)
			{
				long long k=a; a=b; b=k;
			}

		}		
		cout << ans+1 << endl;
	}
	return 0;
}