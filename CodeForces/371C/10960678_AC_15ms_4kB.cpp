#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string recipe;
int need[10], n[10], p[10];
const int INF = 2147483647;
int ans;

void solve()
{
	memset(need, 0, sizeof(need));
	memset(n, 0, sizeof(n));
	memset(p, 0, sizeof(p));
	int len = recipe.length();
	for (int i=0; i<len; ++i)
		if (recipe[i] == 'B') ++need[0];
	else if (recipe[i] == 'S') ++need[1];
	else if (recipe[i] == 'C') ++need[2];
	long long rub;
	scanf("%d%d%d%d%d%d%I64d", &n[0], &n[1], &n[2], &p[0], &p[1], &p[2], &rub);
	
	ll lef=0, righ=1e12+1000;
	ll k[3];
	ll rrub = rub;
	while(lef < righ-1)
	{
		ll mid = (lef+righ)/2;rub = rrub;
		for (int i=0; i<3; ++i) {k[i] = 1LL*-1*min(n[i]-mid*need[i], 1LL*0)*p[i]; rub -= k[i];}
		if (rub < 0) righ = mid;
		else lef = mid;
	}
	cout << lef << endl;
}

int main()
{
	while(cin >> recipe) solve();
	return 0;
}