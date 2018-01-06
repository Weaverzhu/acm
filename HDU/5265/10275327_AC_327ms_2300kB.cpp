#include <cstdio>  
#include <algorithm>  
const int maxn=1e5+10; 
using namespace std;  
typedef long long ll;  
ll a[maxn];  

int main()  
{  
    ll n,p;  
    while(scanf("%lld %lld",&n,&p)!=EOF)  
    {  
        for(int i=0;i<n;i++)  
        {  
            scanf("%lld",&a[i]); 
            a[i]%=p;  
        }  
        sort(a,a+n);  
        ll ans=(a[n-1]+a[n-2])%p;  
        int l=0,r=n-1;  
        while(l<r)  
        {  
            ans=max(ans,(a[l]+a[r])%p);  
            if(a[l]+a[r]<p)l++;  
            else r--;  
        }  
        printf("%lld\n",ans);  
    }  
    return 0;  
}