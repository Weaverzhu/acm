#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
typedef long long LL;
LL l, r, k;
const int maxn = 1e6;
LL sum[maxn+10], a[maxn+10];
bool isprime[maxn+10];
int prime[maxn+10],cnt;

void PRIME()
{
    cnt = 0;
    memset(isprime, true, sizeof(isprime));
    for (int i=2; i<=maxn; ++i)
        if (isprime[i])
        {
            prime[cnt++] = i;
            for (int j=2*i; j<=maxn; j+=i) isprime[j] = false;
        }

}

void solve()
{
    scanf("%I64d%I64d%I64d", &l, &r, &k);
    for (int i=0; i<=r-l; ++i) {sum[i] = 1; a[i] = i+l;}

    for (int i=0; i<cnt; ++i)
    {
        int nowp = prime[i];
//        if (nowp > a[r-l]) break;
        LL st, res = 0;
        if (l%nowp == 0) st = 0;
        else st = (l/nowp+1) * nowp - l;
        for (int i=st; i<=r-l; i+=nowp)
        {
            res = 0;
            while(a[i]%nowp == 0) {a[i] /= nowp; ++res;}
            sum[i] = (sum[i] * (k*res+1)) % MOD;
        }
    }
    for (int i=0; i<=r-l; ++i)
    {
        if (a[i] > 1) sum[i] = (sum[i]*(k+1)) % MOD;
        a[i] = 1;
    }
    LL ans = 0;
    for (int i=0; i<=r-l; ++i) ans = (ans + sum[i]) % MOD;
    cout << ans << endl;
}


int main()
{
    PRIME();
//    for (int i=0; i<20; ++i) cout << prime[i] << endl;
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
