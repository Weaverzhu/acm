#include <cstdio>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define mst(a,b) memset((a),(b),sizeof(a))
#define rush() int T;scanf("%d",&T);while(T--)

typedef long long ll;
const int maxn = 1000005;
const ll mod = 1e9+7;
const ll INF = 0x3f3f3f3f;
const double eps = 1e-9;

ll n;

ll a[maxn];

void init()
{
    a[1]=9;
    for(int i=2;i<=12;i++) a[i]=a[i-1]*10+9;
}

ll power(ll x, ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1) ans*=x;
        x*=x;
        n>>=1;
    }
    return ans;
}

ll solve(int x,int pos)
{
   ll cnt=x*power(10,pos)+a[pos];    //枚举结尾有pos个9的数
   ll l=cnt-n,r=min(n,cnt-1);
   if(l<=0) l=1;
   if(l<=r) return(r-l+1)/2;
   return 0;
}

int main()
{
    init();
    while(~scanf("%I64d",&n))
    {
        if(n<=4)
        {
            printf("%I64d\n",(n-1)*n/2);
            continue;
        }
        else
        {
            int pos;
            for(int i=1;i<12;i++)
            {
                if(n*2<a[i])      //举个例子：n为50，最大为49+50，pos=2
                {
                    pos=i-1;
                    break;
                }
            }
            ll ans=0;
            for(int i=0;i<=8;i++)
            {
                ans+=solve(i,pos);
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}