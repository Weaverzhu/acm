#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string sa, sb;
LL pmd(LL a, LL b)
{
	LL res = 1;
	while(b)
	{
		if (b%2) res *= a;
		a = a*a; b /= 2; 
	}
	return res;
}

bool check(LL mid, LL bb)
{
	
	LL tmp = mid;
	int len = 0;
	while(mid)
	{
		bb -= (mid%10*pmd(1LL*10, 1LL*len) - (mid%10));
		++len;
		mid /= 10;
	}
	if (bb<= 0) return true;
	else return false;

}

void solve()
{
	LL a = 0, b = 0;
	int la = sa.length(), lb = sb.length();
	for (int i=0; i<la; ++i) a = (a*10) + sa[i]-'0';
	for (int i=0; i<lb; ++i) b = (b*10) + sb[i]-'0';

	LL lef = a+100000, righ = 0, mid;
	while(lef>righ+1)
	{
		mid = (lef+righ)/2;
		if (check(mid, b)) lef = mid;
		else righ = mid;
	}
	if (a>=lef) printf("%I64d\n", a-lef+1);
	else printf("0\n");

}

int main()
{
	LL a,b;
	while(cin >> sa >> sb) solve();
	return 0;
}