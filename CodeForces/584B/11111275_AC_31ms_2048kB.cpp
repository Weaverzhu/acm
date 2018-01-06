#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+7;
LL pmd(LL a, LL b)
{
    LL res = 1;
    while(b)
    {
        if (b % 2) res = (res * a) % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;

}

int main()
{
    LL n;
    while(scanf("%I64d", &n) != -1)
    {
        cout << (pmd(3, 3*n) + MOD - pmd(7, n)) % MOD << endl;
    }

    return 0;
}
