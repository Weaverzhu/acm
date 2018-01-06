#include<bits/stdc++.h>
using namespace std;

int k,l,m,n,d;
int main()
{
    while(scanf("%d%d%d%d%d",&k,&l,&m,&n,&d)!=-1)
    {
        int ans=0;
        for (int i=1;i<=d;++i)
            if (i%k==0||i%l==0||i%m==0||i%n==0) ++ans;
        cout<<ans<<endl;
    }
    return 0;
}
