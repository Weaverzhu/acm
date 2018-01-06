#include<bits/stdc++.h>
using namespace std;
const int maxn = 100+10;
int n, k, x;
int a[maxn];
int main()
{
    while(scanf("%d%d%d", &n, &k, &x) != -1)
    {
        for (int i=1; i<=n; ++i)
            scanf("%d", &a[i]);
        long long ans = 0;
        for (int i=1; i<=n-k; ++i)
            ans += a[i];
        ans += k*x;
        cout << ans << endl;
    }

    return 0;
}