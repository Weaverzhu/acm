#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 100+10;
const int maxk = 1e5+10;
const int MOD = 100000007;
typedef long long LL;
LL f[maxk];
LL a[maxn];
int kase = 0;
void solve()
{
    printf("Case %d: ", ++kase);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; ++i) scanf("%lld", &a[i]);
    for (int i=0; i<=k; ++i) f[i] = 0;
    f[0] = 1;
    for (int i=0; i<n; ++i)
        for (int j=1; j<=k; ++j)
            if (j-a[i]>=0) f[j] = (f[j-a[i]]+f[j])%MOD;
    cout << f[k] << endl;

}

int main()
{
    int t;
    cin >> t;
    kase = 0;
    while(t--) solve();
    return 0;
}