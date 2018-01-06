#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a, b;

int main()
{
	scanf("%I64d%I64d", &a, &b);
	if (a == b) cout << 1 << endl;
	else if (b <= 4)
	{
		int ans = 1;
		for (int i=a+1; i<=b; ++i) ans *= i;
		cout << ans%10 << endl;
	}
	else if (b-a<=8)
	{
		int ans = 1;
		for (LL i=a+1; i<=b; ++i)
		{
			LL tmp = i%10;
			ans *= tmp;
			ans = ans % 10;
		}
		cout << ans%10 << endl;
	}
	else cout << 0 << endl; 
	return 0;
}