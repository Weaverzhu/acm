#include<bits/stdc++.h>
using namespace std;
const int maxn=4000+10;
int dp[maxn];
int tim[maxn];
int n;


void solve()
{
    for (int i=1;i<=n;++i) scanf("%d",&tim[i]);
    dp[0]=0;
    for (int i=1;i<=n;++i)
    {
        int tmp = dp[i-1]+140;
        for (int j=1; j<i; ++j)
        {
            tmp=min(tmp,dp[j-1]+max(tim[i]-tim[j]-1780,(i-j+1)*20)+120);
        }
        dp[i]=tmp;
    }
    printf("%d\n",dp[n]);
    return;
}

int main()
{
    while(scanf("%d",&n)!=-1) solve();
    return 0;
}
