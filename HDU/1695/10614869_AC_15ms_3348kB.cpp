#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int vis[maxn],prime[maxn],mo[maxn];
int cnt;

void mobieus(int N)
{
    memset(vis,0,sizeof(vis));
    mo[1]=1;
    cnt=0;
    for (int i=2;i<N;++i)
    {
        if (!vis[i])
        {
            prime[cnt++]=i;
            mo[i]=-1;
        }
        for (int j=0;j<cnt&&i*prime[j]<N;++j)
        {
            vis[i*prime[j]]=1;
            if (i%prime[j]) mo[i*prime[j]]=-mo[i];
            else
            {
                mo[i*prime[j]]=0;
                break;
            }
        }
    }
}
void solve()
{
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    if (e==0) 
    {
        cout<<"0"<<endl;
        return;
    }
    b/=e;d/=e;
    long long ans1=0,ans2=0,ans;
    int x=min(b,d);
    for (int i=1;i<=x;++i)
    {
        ans2+=(long long)(1LL*mo[i]*(x/i)*(x/i));
    }
    for (int i=1;i<=x;++i)
    {
        ans1+=(long long)(1LL*mo[i]*(b/i)*(d/i));
    }
    ans=ans1-ans2/2;
    cout<<ans<<endl;
}
int main()
{
    mobieus(maxn-10);
    int t;
    scanf("%d",&t);
    int kase=0;
    while(t--)
    {
        printf("Case %d: ",++kase);
        solve();
    }

    return 0;
}
