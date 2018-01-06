#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
bool isprime[maxn];


void init()
{
    memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
    for (int i=2; i<=maxn-10; ++i)
    {
        if (isprime[i])
        {
            for (int j=2*i; j<=maxn-10; j+=i)
                isprime[j] = false;

        }

    }

}
int main()
{
    init();
    int n, m;
    while(scanf("%d%d", &n, &m) != -1)
    {
        int ans = 0;
        for (int i=n; i<=m; ++i)
            if (isprime[i]) ++ans;
        cout << ans << endl;
    }
    return 0;
}
