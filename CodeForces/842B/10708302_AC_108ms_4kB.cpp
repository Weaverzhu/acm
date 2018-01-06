#include<bits/stdc++.h>
using namespace std;
const double eps=1e-7;
double r,d;
int n;

void solve()
{
    scanf("%d",&n);
    double r1=r-d,r2=r;
    int ans=0;
    for (int i=1;i<=n;++i)
    {
        double xi,yi,ri;
       scanf("%lf%lf%lf",&xi,&yi,&ri);
        double dis=sqrt(xi*xi+yi*yi);
        if((dis-(r1+ri)>=0)&&(dis-(r-ri))<=0) ++ans;


    }
    cout<<ans<<endl;
}
int main()
{
    while(scanf("%lf%lf",&r,&d)!=-1) solve();
    return 0;
}
