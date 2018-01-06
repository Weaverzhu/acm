#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200000+10;

ll n;
int k;
ll st[maxn], ed[maxn];
ll ans[maxn];
struct NODE {
    ll _end;
    int n;
}node[maxn];

bool cmp (NODE a, NODE b) {
    return a._end < b._end;
}

int main()
{
    while (cin >> n >> k) {
        memset(ans, 0, sizeof(ans));
        for (int i=1; i<=k; i++) {
            scanf("%I64d %I64d", &st[i], &ed[i]);
            node[i].n = i;
            node[i]._end = ed[i];
        }
        ans[0] = 0;
        node[0]._end = 0;
        node[0].n = 0;
        sort(node+1, node+k+1, cmp);
        for (int i=1; i<=k; i++) {
            ll cnt = st[node[i].n];
            int lef = 0, righ = i;
            while (lef <= righ) {
                int mid = (lef+righ) / 2;
                if (node[mid]._end < cnt) {
                    lef = mid+1;
                }
                    else righ = mid-1;
            }
            int mid = min(lef + 2, k);
            for (; ; mid--) {
                if (node[mid]._end < cnt) break;
            }
//            cout << mid<< ' ' ;
            ans[i] = max(ans[i-1], ans[mid] + node[i]._end - st[node[i].n]+1);
//            cout << ans[i] <<endl;
        }
//    for (int i=0; i<=k; i++) cout << ans[k] <<endl ;
//    puts("");
        cout << n - ans[k] << endl;
    }
    return 0;
}
