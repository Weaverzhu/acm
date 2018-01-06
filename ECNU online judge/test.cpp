
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double pow(double a, double b){
    double res = 1;
    for (int i=0; i<b; ++i)
        res *= a;
    return a;
}
int main()
{
    double l,r,p,m,m1,a[50];
    int t,i,n,j;
    scanf("%d",&t);
    printf("t=%d\n", t);
    for (i=1;i<=t;i++)
    {
        printf("i=%d\n", i);
        r=1;
        p=0;
        scanf("%lf",&n);
        for (j=0;j<=n;j++)
            scanf("%lf",&a[j]);
        a[0]=-a[0];
        l=-1;r=1;
        while (fabs(r-l)>1e-8)
        {
            m=(l+r)/2;
            p=0;
            for (k=0;k<=n;k++) p=p+a[k]*pow((1+k),(n-j));

                if (p>0) l=m;
                else r=m;

        }
         m=m*100;
         printf("%.4f",m);
         printf("a\n");
    }
    return 0;
}
