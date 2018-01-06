#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
ll dt[100000],ed;

ll pow_(ll a,ll k)
{
    ll an=1;
    while(k){if(k&1)an*=a;k>>=1,a*=a;}
    return an;
}

int main()
{
    ll a,b,c,d;
    F(i,0,40)
    {
        a=pow_(2,i);
        if(a>1e9)continue;
        F(j,0,40)
        {
            b=pow_(3,j);
            if(b>1e9||a*b>1e9)continue;
            F(k,0,40)
            {
                c=pow_(5,k);
                if(c>1e9||a*b*c>1e9)continue;
                F(l,0,40)
                {
                    d=pow_(7,l);
                    if(d>1e9||a*b*c*d>1e9)continue;
                    dt[++ed]=a*b*c*d;
                }
            }
        }
    }
    sort(dt+1,dt+1+ed);
    int t,n;
    scanf("%d",&t);
    while(t--)scanf("%d",&n),printf("%lld\n",dt[lower_bound(dt+1,dt+1+ed,n)-dt]);
    return 0;
}