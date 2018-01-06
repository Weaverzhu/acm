#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;


void solve()
{
    scanf("%lld",&n);
    ll n1=12*n-3;
    double n2=sqrt(n1);
    ll n3=round(n2-0.1);
    if (n3*n3==n1)
    {
        if (n3%3==0&&n3%6!=0)
        {
            printf("YES\n");return;
        }
        else
        {
            printf("NO\n");return;
        }
    }
    else
    {
        printf("NO\n");
        return;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}