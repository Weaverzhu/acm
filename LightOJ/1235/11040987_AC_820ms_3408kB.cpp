#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, k;
const int maxn = 20;
const LL maxk = 1e9+10;
const int maxs = 1e7+10;
int a[maxn];
int kase = 0;
LL tmp;
set<LL> S,S2;
void dfs1(int now)
{
    if (now == n/2+1)
    {
        if (!S.count(tmp))
        {
            S.insert(tmp);
        }
        return;
    }
    for (int r=0; r<=2; ++r)
    {
        tmp += r*a[now];
        dfs1(now + 1);
        tmp -= r*a[now];
    }
}
void dfs2(int now)
{
    if (now+n/2 == n+1)
    {
        if (!S2.count(tmp))
        {
            S2.insert(tmp);
        }
        return;
    }
    for (int r=0; r<=2; ++r)
    {
        tmp += r*a[now+n/2];
        dfs2(now + 1);
        tmp -= r*a[now+n/2];
    }
}



void solve()
{
    printf("Case %d: ", ++kase);
    S.clear(); S2.clear();
    scanf("%lld%lld", &n, &k);
    for (int i=1; i<=n; ++i) scanf("%d", &a[i]);

    tmp = 0; dfs1(1);
    tmp = 0; dfs2(1);
    set<LL>::iterator it;
    for (it=S.begin(); it!=S.end(); it++)
    {
        int w = *it;
        if (S2.count(k-w))
        {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");

}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) solve();

    return 0;
}