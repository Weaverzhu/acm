#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int r=1e9+7;

long long pow_mod(int a,int n,int m)
{
    if(n==0) return 1;
    long long x=pow_mod(a,n/2,m);
    x=x*x%m;
    if(n%2==1) x=x*a%m;
    return x;
}

long x[300005];

int main()
{
    int n=0;
    long long sum=0LL;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        long long temp=0LL,temp1,temp2;
        for(int i=0; i<n; ++i) scanf("%ld",&x[i]);
        sort(x,x+n);

        for(int i=0;i<n/2;++i)
        {
           temp1=(pow_mod(2,n-1-i,r)-pow_mod(2,i,r)+r)%r;
           temp2=(x[n-1-i]-x[i])%r;
           temp=(temp1*temp2)%r;
           sum=(sum+temp)%r;
        }

        printf("%lld\n",sum);
    }
    return 0;
}
 