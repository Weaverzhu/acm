#include<cstring>  
#include<string>  
#include<iostream>  
#include<queue>  
#include<cstdio>  
#include<algorithm>  
#include<map>  
#include<cstdlib>  
#include<cmath>  
#include<vector>  
//#pragma comment(linker, "/STACK:1024000000,1024000000");  
  
using namespace std;  
  
#define INF 0x3f3f3f3f  
  
char x[200005];  
  
int getsum(int len)  
{  
    int sum=0;  
    for(int i=0;i<len;i++)  
    {  
        sum+=(x[i]-'0');  
    }  
    return sum;  
}  
  
int getdis(int k)  
{  
    int sum=0;  
    while(k%10) k++,sum++;  
    if(sum==0) sum=10;  
    return sum;  
}  
  
void add(int d,int &len)  
{  
    int index=0;  
    while(index<len&&d)  
    {  
        int temp=(x[index]-'0');  
        x[index]=((temp+d)%10)+'0';  
        d=(temp+d)/10;  
        index++;  
    }  
    if(d) x[len++]=d+'0';  
}  
  
int main()  
{  
    int T;  
    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%s",x);  
        int len=strlen(x);  
        for(int i=0;i<len/2;i++)  
        {  
            swap(x[i],x[len-i-1]);  
        }  
        int sum=getsum(len);  
        int d=getdis(sum);  
        if((x[0]-'0')+d<=9) add(d,len);  
        else  
        {  
            add(10-(x[0]-'0'),len);  
            int d=getsum(len);  
            if(d%10!=0) add(getdis(d),len);  
        }  
        for(int i=len-1;i>=0;i--)  
        {  
            printf("%c",x[i]);  
        }  
        puts("");  
    }  
    return 0;  
}  