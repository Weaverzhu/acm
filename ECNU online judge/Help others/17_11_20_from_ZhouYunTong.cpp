#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c,m,n,t;
    scanf("%d%d",&a,&b);
    if(a<0||b<0)return 0;
    if(a>b)m=a,n=b;
    else m=b,n=a;
    while(m%n!=0)
    {
        t=n;
        n=m%n;
        m=t;
    };
    c=n;
    printf("%d\n",c);
    return 0;
}
