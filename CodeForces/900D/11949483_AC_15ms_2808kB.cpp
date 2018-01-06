#include<bits/stdc++.h>
#define clr(x) memset(x,0,sizeof(x))
#define clr_1(x) memset(x,-1,sizeof(x))
#define mod 1000000007
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e5+10;
int prime[N],inf[N],pcnt;
void primer(int n)
{
    pcnt=0;
    for(int i=2;i<=n;i++)
    {
        if(!inf[i])
        {
            prime[++pcnt]=i;
        }
        for(int j=1;j<=pcnt;j++)
        {
            if(prime[j]>n/i) break;
            inf[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
    return ;
}
LL quick_pow(LL x,LL n)
{
    LL res=1;
    while(n)
    {
        if(n&1)
            res=(res*x)%mod;
        n>>=1;
        x=(x*x)%mod;
    }
    return res;
}
LL  x,y,d,n,k;
int all;
LL num[20];
int cnt;
LL ans,p;
int main()
{
    primer(100000);
    scanf("%lld%lld",&x,&y);
    if(y%x!=0)
    {
        printf("0\n");
        return 0;
    }
    y/=x;
    d=y;
    cnt=0;
    for(int i=1;(LL)prime[i]*prime[i]<=d;i++)
    {
        n=(LL)prime[i];
        if(d%n==0)
        {
            num[++cnt]=n;
            while(d%n==0) d/=n;
        }
    }
    if(d!=1) num[++cnt]=d;
    ans=0;
    all=(1<<cnt)-1;
    for(int i=0,j,k,ok;i<=all;i++)
    {
        j=i;
        k=0;
        p=1;
        ok=1;
        while(j)
        {
            k++;
            if(j&1) p*=num[k],ok=-ok;
            j>>=1;
        }
        ans=(ans+quick_pow(2,y/p-1)*ok)%mod;
    }
    printf("%lld\n",(ans%mod+mod)%mod);
    return 0;
}