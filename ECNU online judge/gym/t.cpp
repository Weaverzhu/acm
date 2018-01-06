#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-12

double f(int n,int a[],double x)
{
    int i;
    double f = 0;
    double now = 1;
    for (i=0; i<=n-1; ++i){
        f += a[i]*now;
        now = now * (1+x);
    }
    f -= a[n]*now;
    return f;
}

int a[100+2];
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<=t-1;i++){
        int n;
        scanf("%d",&n);

        scanf("%d",&a[n]);
        int k;
        for(k=n-1;k>=0;k--)scanf("%d",&a[k]);
        double l=-1,r=1,m;
        while(r-l>EPS){
            m=(l+r)/2;
            double check = f(n,a,m);
            if(check < 0)r=m;
            else l=m;
        }
        printf("case #%d:\n%.4f%%\n",i,100*l);

    }
    return 0;
}
