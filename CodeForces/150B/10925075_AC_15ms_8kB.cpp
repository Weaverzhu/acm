#include<iostream>   
#include<stack>  
#include<queue>  
#include<stdio.h>  
#include<algorithm>   
#include<string.h>  
#include<cmath>  
#define ll long long  
#define oo 1000000007  
#define MAXN 100005  
using namespace std;     
int n,m,k;   
int POW(ll m,ll n)  
{  
      int i;  
      ll ans=1;  
      for (i=1;i<=n;i++) ans=(ans*m)%oo;    
      return (int)ans;  
}   
int main()  
{    
      while (~scanf("%d%d%d",&n,&m,&k))  
      {     
             if (k>n || k==1) printf("%d\n",POW(m,n));  
             else   
             if (k==n) printf("%d\n",POW(m,(k+1)/2));  
             else  
             if (k%2) printf("%d\n",m*m);  
             else  
             printf("%d\n",m);  
      }  
      return 0;  
} 