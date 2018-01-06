#include <bits/stdc++.h>
    using namespace std;

    typedef struct {int in, out, rat;} file;
    bool cmp (const file &a, const file &b) {
        return a.rat > b.rat;
    }
    int main() {
        //freopen("testin.txt", "r", stdin);
        //freopen("testout.txt", "w", stdout);
        typedef long long LL;
        int n, day;
        file r[100010];
        scanf("%d%d", &n, &day);
        for (int i=0; i<n; ++i) {
            scanf("%lld%lld", &r[i].in, &r[i].out);
            if (r[i].in && r[i].out)
                r[i].rat = min(r[i].out, 2*r[i].in) - min(r[i].in, r[i].out);
            else r[i].rat = 0.0;
        }
        sort(r, r+n, cmp);
        LL ans = 0;
        for (int i=0; i<day; ++i)
            ans += min(2*r[i].in, r[i].out);
        for (int i=day; i<n; ++i)
            ans += min(r[i].in, r[i].out);
        printf("%lld\n", ans);
        return 0;
    }
