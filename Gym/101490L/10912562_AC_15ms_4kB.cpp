#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long c[n];
    for (int i=0; i<n; i++) scanf("%I64d", &c[i]);
    sort(c, c+n);
    int i;
    for (i=2; i<n; i++) {
        if (c[i-2]+c[i-1] > c[i])  break;
    }
    if (i==n) puts("impossible");
        else puts("possible");

    return 0;
}
