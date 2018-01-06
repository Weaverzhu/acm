#include <bits/stdc++.h>

#define LL long long

using namespace std;

int n, k;
LL x[1005], m[1005];

void solve()
{
    for (int i=0; i<n; i++) {
        scanf("%I64d %I64d", &x[i], &m[i]);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (x[j] > x[i]) {
                swap(x[i], x[j]);
                swap(m[i], m[j]);
            }
        }
    }
//    for (int i=0; i<n; i++) {
//        cout << x[i] << ' '<< m[i] << endl;
//    }
    int cnt;
    for (cnt=0; cnt<n; cnt++) {
        if (x[cnt] >= 0) break;
    }
    LL ans = 0, num = 0;
    for (int i=0; i<cnt; i++) {
        if (num >= m[i]) {
            num -= m[i];
            continue;
        }
            else {
                m[i] -= num;
                num = 0;
                if (m[i] % k == 0) {
                    ans = ans + (m[i]/k) * (-x[i]);
                }
                    else {
                        ans = ans + (m[i]/k + 1) * (-x[i]);
                        num += (k-m[i] % k);
                    }
            }
    }
    num = 0;
    for (int i=n-1; i>=cnt; i--) {
        if (num >= m[i]) {
            num -= m[i];
            continue;
        }
            else {
                m[i] -= num;
                num = 0;
                if (m[i] % k == 0) {
                    ans = ans + (m[i]/k) * x[i];
                }
                    else {
                        ans = ans + (m[i]/k + 1) * x[i];
                        num += (k-m[i] % k);
                    }
            }
    }
    cout << ans * 2 << endl;
}

int main()
{
//    freopen("in.txt", "r", stdin);
    while(scanf("%d%d", &n, &k) != -1) solve();

    return 0;
}
