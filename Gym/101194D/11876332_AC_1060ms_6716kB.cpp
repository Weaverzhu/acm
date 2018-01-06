#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=3e5+100;
ll a[maxn],b[maxn];
int n,k;
bool check(int x)
{
    if(!x) return true;
    int j=x+1;
    rep(i,1,x+1)
    {
        b[i]=a[i];
    }
    int i;
    for(i=x+1;i<=n;)
    {
        while(a[i]<b[j-x]*2&&i<=n) i++;
        if(i>n) break;
        b[j++]=a[i];
        if((j-1)/x>=k) return true;
        i++;
    }
    if((j-1)/x>=k) return true;
    else return false;
}
int main()
{
    int cas;
    scanf("%d",&cas);
    rep(kk,1,cas+1)
    {
        scanf("%d%d",&n,&k);
        rep(i,1,n+1) scanf("%lld",&a[i]);
        if(n<k)
        {
            printf("Case #%d: 0\n",kk);
            continue;
        }
        int l=0,r=n/k;
        int ans=0;
        sort(a+1,a+n+1);
        while(l<=r)
        {
            int m=(l+r)/2;
            if(check(m)) ans=m,l=m+1;
            else r=m-1;
        }
        printf("Case #%d: %d\n",kk,ans);
    }
    return 0;
}