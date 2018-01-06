
#include<bits/stdc++.h> 
typedef __int64 LL;  
typedef unsigned __int64 LLU;  
const int nn=11000000;  
const int inf=0x3fffffff;  
const LL inf64=(LL)inf*inf;  
using namespace std;  
LL x;  
LL solve()  
{  
    LL i;  
    LL p=x;  
    int num=0;  
    LL tem=1;  
    for(i=2;i*i<=x;i++)  
    {  
        while(p%i==0)  
        {  
            p/=i;  
            num++;  
            if(num<=2)  
                tem*=i;  
            if(num>2)  
                return tem;  
        }  
    }  
    if(p>1)  
    {  
        num++;  
    }  
    if(num==2)  
        return -1;  
    return num==1?0:tem;  
  
}  
int main()  
{  
    while(scanf("%I64d",&x)!=EOF)  
    {  
        if(x==1)  
        {  
            puts("1");  
            puts("0");  
            continue;  
        }  
        LL ix=solve();  
        if(ix==-1)  
        {  
            puts("2");  
        }  
        else  
        {  
            puts("1");  
            printf("%I64d\n",ix);  
        }  
    }  
    return 0;  
}