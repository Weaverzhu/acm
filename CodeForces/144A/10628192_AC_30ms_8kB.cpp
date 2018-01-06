#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=100+10;
int a[maxn],b[maxn];



void solve()
{
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(a+1,a+n+1);
    int maxa=a[n],mina=a[1];
    for (int i=1;i<=n;++i)
    {
        if (b[i]==maxa)
        {
            maxa=i;
            break;
        }
    }
    for (int i=n;i>=1;--i)
    {
        if (b[i]==mina)
        {
            mina=i;
            break;
        }
    }
    int ans=maxa-1+n-mina;
    if (maxa>mina) ans--;
    printf("%d\n",ans);
}

int main()
{
    while(scanf("%d",&n)!=-1)
    {
        solve();
    }
    return 0;
}