#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n, k, l, c, d, p, nl, np;
    while(scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np)!=-1)
    {
        nl=n*nl;
        np=n*np;
        d=c*d;
        l=k*l;
        int ans=min(l/nl,p/np);
        ans=min(d/n,ans);
        cout<<ans<<endl;
    }
    return 0;
}
