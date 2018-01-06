#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a)) 

const int N=50;
int a[N];
set<int>s; 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i],a[i]=a[i]%m;
    sort(a,a+n);
    int hf=n/2;
    int _hf=n-hf;
    for(int i=0;i<(1<<hf);i++)
    {
        int t=0;
        for(int j=0;j<hf;j++)if((1<<j)&i)t=(t+a[j])%m;
        s.insert(t);
    }
    set<int>::iterator it;
    int ans=0;
    for(int i=0;i<(1<<_hf);i++)
    {
        int t=0;
        for(int j=0;j<_hf;j++)if((1<<j)&i)t=(t+a[j+hf])%m;
        it=s.upper_bound(m-1-t);
        if(it==s.begin())
        {
            ans=max(ans,t);
            continue;
        }
        it--;
        ans=max(ans,t+*it);
    }
    cout<<ans<<endl;
    return 0;
}