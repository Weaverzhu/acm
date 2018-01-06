#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
using namespace std;  
struct node  
{  
    char s[15];  
    int x;  
}a[3500];  
int cmp(node a,node b)  
{  
    return a.x<b.x;  
}  
int ans[3500];  
int main()  
{  
    int n;  
    while(~scanf("%d",&n))  
    {  
        for(int i=1;i<=n;i++)  
        {  
            scanf("%s%d",a[i].s,&a[i].x);  
        }  
        sort(a+1,a+n+1,cmp);  
        int flag=0;  
        for(int i=1;i<=n;i++)  
        {  
            if(a[i].x>=i)flag=1;  
            ans[i]=i-a[i].x;  
            for(int j=1;j<i;j++)  
            {  
                if(ans[j]>=ans[i])  
                {  
                    ans[j]++;  
                }  
            }  
        }  
        if(flag==1)  
        {  
            printf("-1\n");  
            continue;  
        }  
        for(int i=1;i<=n;i++)  
        {  
            printf("%s %d\n",a[i].s,ans[i]);  
        }  
    }  
}  
