#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100000+10;
int a[maxn], b[maxn], f[maxn];
int n, k, m;
int main()
{
    while(scanf("%d%d%d", &n, &k, &m) != -1)
    {
        memset(f, 0, sizeof(f));
        int ans = -1;
        for (int i=1; i<=n; ++i)
        {scanf("%d", &a[i]);
            b[i] = a[i]%m;
            ++f[b[i]];
            if (f[b[i]] >= k) ans = b[i];
        }
        if(ans == -1)
        {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
        int i1, j1;
        for (i1=1, j1=1; i1<=n&&j1<k;)
        {
            if(b[i1] == ans) {printf("%d ", a[i1]); ++j1;};
            i1++;
        }
        for (; i1<=n; ++i1)
            if (b[i1] == ans)
        {
            printf("%d\n", a[i1]);
            break;
        }
    }
    return 0;
}