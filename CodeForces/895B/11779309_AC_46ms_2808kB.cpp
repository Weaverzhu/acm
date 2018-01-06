#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;
LL n, x, k;
LL a[maxn];
const LL INF = 1e18;
int main(){


    cin >> n >> x >> k;
    for (int i=0; i<n; ++i)
        scanf("%d", &a[i]);

    sort(a, a+n);
    a[n] = INF;
    LL ans = 0;
    for (int i=0; i<n; ++i){
        LL st, ed;
        if (k == 0 && a[i] % x == 0) continue;
        if (a[i] % x == 0){
            st = a[i] + (k-1)*x;
        }else{
            st = (a[i]/x+1)*x + (k-1)*x;
        }
        ed = st + x-1;
        st = max(a[i], st);

        LL *p1 = upper_bound(a, a+n+1, ed),
        *p2 = lower_bound(a, a+n+1, st);
//        printf("%lld %lld\n", st, ed);
//        printf("%lld %lld\n", *p2, *p1);
        if (*p2 < INF)
            ans += p1-p2;

    }
    cout << ans << endl;

    return 0;
}
