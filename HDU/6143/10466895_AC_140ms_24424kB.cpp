#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
long long c[2010][2010], f[2010];
long long p(long long a,long long b)
{
    long long f = a, res = 1;
    while (b>0) {
        if (b%2) {
            res = res * f % M;
        }
        f = f * f % M;
        b/= 2;
    }
    return res;
}
int main()
{
    int t,n,m;
    c[1][0]=1;c[1][1]=1;
    for (int i=2;i<=2000;++i){
        c[i][0]=1;
        for (int j=1;j<=i;++j){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
        }
    }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            f[i] = p(i, n);
            for(int j = 1; j < i; j++)
                f[i] = (f[i] - c[i][j] * f[j] + M * M) % M;
        }
        long long ans = 0, ss = 1;
        for(int i = 1; i <= m && i <= n; i++)
        {
            long long s = p(m - i, n) * c[m][i] % M * f[i] % M;
            ans = (ans + s)% M;
        }
        cout<<ans<<endl;
    }
    return 0;
}
