#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int v[maxn],x ,r, n;

void solve()
{
    r = n;
    int now = 0;
    printf("1");
    memset(v, 0, sizeof(v));
    for (int i=1; i<=n; ++i)
    {
        now++;
        scanf("%d", &x); v[x] = 1;
        if (x == r) while(v[r] && r>=1) {--r; --now;};
        printf(" %d", now+1);
    }
    printf("\n");


}

int main()
{
//    freopen("in.txt", "r", stdin);
    while(scanf("%d", &n) != -1) solve();
    return 0;
}
