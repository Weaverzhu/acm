#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 50;
long long a[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    long long K;
    scanf("%d %lld", &n, &K);
    long long b = 0, s = 0, m = 0, pos = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        if (a[i] >= m) m = a[i], pos = i;
        s += a[i];
    }
    s -= m;
    for (int i = 1; i < pos; ++i)
    {
        b += a[i];
    }
    bool flag = false;
    if (K == 0 && pos == 1) flag = true;
    for (long long i = 1; K > 0; ++i)
    {
        long long down = (pos - 1) + ((long long)n - 1LL) * (i - 1LL);
        long long up = b + s * (i - 1LL);
        if (K < down)
        {
            break;
        }
        else if (K > up)
        {
            K -= m;
            continue;
        }
        else flag = true;
    }
    puts(flag ? "YES" : "KEK");
    return 0;
}