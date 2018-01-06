#include<bits/stdc++.h>
using namespace std;
long long l,r,a,b,k;

void solve()
{
    for (int i=a;i<=b;++i)
    {
        long long tmp=i*k;
        if (tmp>=l&&tmp<=r)
        {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
    return;
}
int main()
{
    while(scanf("%d%d%d%d%d",&l,&r,&a,&b,&k)!=-1)
     solve();
    return 0;
}
