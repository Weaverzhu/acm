#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#define inf 1000000000
#define MOD 1000000007
 
using namespace std;
typedef long long ll;
 
string s, s2;
ll cnt[26];
ll fact[1001000];
ll _fact[1001000];
 
ll bin_pow(ll x, ll n)
{
	if (!n)
		return 1;
	if (n % 2)
		return (x*bin_pow(x, n - 1)) % MOD;
	ll y = bin_pow(x, n / 2);
	return (y*y) % MOD;
}
 
void init()
{
	fact[0] = 1;
	for (int i = 1; i < 1001000; i++)
		fact[i] = (fact[i - 1] * i) % MOD;
	_fact[1000999] = bin_pow(fact[1000999], MOD - 2);
	for (int i = 1000998; i >= 0; i--)
		_fact[i] = (_fact[i + 1] * (i + 1)) % MOD;
}
 
ll f(string str)
{
	ll res = 0;
	ll perm = fact[s.size()];
	for (int i = 0; i < 26; i++)
		cnt[i] = 0;
	for (int i = 0; i < s.size(); i++)
		cnt[s[i] - 'a']++;
	for (int i = 0; i < 26; i++)
		perm = (perm * _fact[cnt[i]]) % MOD;
	for (int i = 0; i < s.size(); i++)
	{
		perm = (perm * _fact[s.size() - i]) % MOD;
		perm = (perm * fact[s.size() - i - 1]) % MOD;
		for (int j = 0; j < str[i] - 'a'; j++)
		{
			if (!cnt[j])
				continue;
			perm = (perm * fact[cnt[j]]) % MOD;
			cnt[j]--;
			perm = (perm * _fact[cnt[j]]) % MOD;
			ll add = fact[s.size() - i - 1];
			res = (res + perm) % MOD;
			perm = (perm * fact[cnt[j]]) % MOD;
			cnt[j]++;
			perm = (perm * _fact[cnt[j]]) % MOD;
		}
		if (!cnt[str[i] - 'a'])
			break;
		perm = (perm * fact[cnt[str[i] - 'a']]) % MOD;
		cnt[str[i] - 'a']--;
		perm = (perm * _fact[cnt[str[i] - 'a']]) % MOD;
	}
	return res;
}
 
int main()
{
	init();
	cin >> s >> s2;
	cout << (f(s2) - f(s) - 1 + MOD) % MOD << endl;
}