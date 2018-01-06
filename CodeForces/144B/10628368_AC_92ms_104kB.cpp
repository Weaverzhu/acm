#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<math.h>

using namespace std;
const int maxn=1e4;
const int maxm=1e3+10;
double x[maxm],y[maxm],r[maxm];
int xa[maxn],ya[maxn],op;
int x1,y1,x2,y2;
int m;


void solve()
{
    scanf("%d",&m);
    for (int i=1;i<=m;++i) scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
    int t1=min(x1,x2),t2=max(x1,x2),t3=min(y1,y2),t4=max(y1,y2);
    op=0;
    for (int i=t1;i<=t2;++i)
    {
        xa[++op]=i;ya[op]=t3;
        xa[++op]=i;ya[op]=t4;
    }
    for(int i=t3+1;i<=t4-1;++i)
    {
        xa[++op]=t1;ya[op]=i;
        xa[++op]=t2;ya[op]=i;
    }
    int ans=0;
    for (int i=1;i<=op;++i)
    {
        bool flag=true;
        for (int j=1;j<=m;++j)
        {
            double d=sqrt( abs(xa[i]-x[j])*abs(xa[i]-x[j]) + abs(ya[i]-y[j])*abs(ya[i]-y[j]) );
            if (d<=r[j])
            {
                flag=false;
                break;
            }

        }
        if (flag) ++ans;
    }
    cout<<ans<<endl;
}




int main()
{
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=-1) solve();
    return 0;
}