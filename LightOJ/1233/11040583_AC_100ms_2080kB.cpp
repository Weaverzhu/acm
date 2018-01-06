#include<bits/stdc++.h>
using namespace std;
const int maxn = 100+10;
const int maxk = 1e5+10;
const int MOD = 100000007;
typedef long long LL;
int f[maxk];
int a[maxn];
int t[maxn];
int kase = 0;
void solve()
{
    printf("Case %d: ", ++kase);
    int n, k;
    scanf("%d%d", &n, &k);
    memset(f, -1, sizeof(f));
    for (int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for (int i=1; i<=n; ++i) scanf("%d", &t[i]);
    f[0] = 0;
    for (int i=1; i<=n; ++i)
    {
        f[0] = t[i];

        for (int j=1; j<=k; ++j)
        {
            if (f[j]>=0) f[j] = t[i];
            else if (j>=a[i] && f[j-a[i]]>0) f[j] = f[j-a[i]]-1;
            else f[j] = -1;
        }
    }
    int ans = 0;
    for (int i=1; i<=k; ++i)
        if (f[i]>=0) ++ans;
    cout << ans << endl;

}

int main()
{
    int t;
    cin >> t;
    kase = 0;
    while(t--) solve();
    return 0;
}
