#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000+10;
int a[maxn];
int n, k, r;

void solve()
{
    int ans = 0;
    memset(a, 0, sizeof(a));
    int st = 1, ed = r, now = 0;
    for (int i=1; i<=k; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        ++a[tmp];
    }
    for (int i=1; i<=r; ++i) now += a[i];
    if (now < 2)
    {
        int remain = 2-now;
        for (int i=ed; i >= st; --i)
        {

            if (!a[i])
            {
                remain--; ++a[i]; ++ans; ++now;
            }
            if (!remain) break;
        }
    }
    while (ed < n)
    {
        ++ed; now += a[ed];
        now -= a[st]; ++st;
        if (now < 2)
        {
            int remain = 2-now;
            for (int i=ed; i >= st; --i)
            {

                if (!a[i])
                {
                    remain--; ++a[i]; ++ans; ++now;
                }
                if (!remain) break;
            }
        }
    }
    cout << ans << endl;

}

int main()
{
    while(scanf("%d%d%d", &n, &k, &r) != -1) solve();

    return 0;
}
