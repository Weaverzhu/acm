#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6+1000;
int m[maxn+10], phi[maxn+10], p[maxn+10], pt;
int summ[maxn + 10];
const int MOD = 998244353;
const int mod = 2333333;
int head[mod+5], num = 0;
typedef long long LL;
LL n;int k;
struct my_map{
    LL x,ans;int next;
}e[mod+5];
int make()
{
    phi[1]=1;
    int N=maxn;
    int k;
    for(int i=2;i<N;i++)
    {
        if(!m[i])
            p[pt++]=m[i]=i,phi[i]=i-1;
        for(int j=0;j<pt&&(k=p[j]*i)<N;j++)
        {
            m[k]=p[j];
            if(m[i]==p[j])
            {
                phi[k]=phi[i]*p[j];
                break;    
            }
            else
                phi[k]=phi[i]*(p[j]-1);
        }
    }
}
void ins(LL x,LL sum)
{
    int j=x%mod;
    e[++num]=(my_map){x,sum,head[j]};
    head[j]=num;
}

LL SUM(LL n)
{
	if(n<=maxn) return summ[n];
	for(int i=head[n%mod];i;i=e[i].next)
        if(e[i].x==n)return e[i].ans;
    LL sum=(n%MOD)*((n+1)%MOD)%MOD*500000004%MOD;
    int q=sqrt(n);
    for(int i=2;i<=q;i++)
        sum=(sum-SUM(n/i))%MOD;
    q=n/(q+1);
    for(int i=1;i<=q;i++)
        sum=(sum-((n/i-(n/(i+1)))%MOD*SUM(i))+MOD)%MOD;
    ins(n,sum);
    return sum;
}
void solve1()
{
	LL ans = (n%MOD)*(n+1)/2%MOD;
	for (int i=1; i<=k-1; ++i)
	{
		ans = ans + MOD - (phi[i]*(n/i))%MOD;
		ans = ans % MOD;
	}
	for (int i=n-k+1; i<=n; ++i)
	{
		ans = ans + MOD - (phi[i]*(n/i))%MOD;
		ans = ans % MOD;
	}
	cout << ans << endl;
}
void solve2()
{
	LL ans = (n%MOD)*(n+1)/2%MOD;
	for (int i=1; i<=k-1; ++i)
	{
		ans = ans + MOD - (phi[i]*(n/i))%MOD;
		ans = ans % MOD;
	}
	ans = ans + MOD - (SUM(n)-SUM(n-k+1))%MOD;
	ans = ans % MOD;
	cout << ans << endl;

}
int main()
{
	make();
	for (int i=1; i<=maxn; ++i)
		summ[i]=summ[i-1] + phi[i];
	cout<<SUM((LL)1e10)<<endl;
	while(scanf("%lld%d",&n,&k)!=-1)
	{
		if (n<=2e6+1000) solve1();
		else solve2();
	}

	return 0;
}