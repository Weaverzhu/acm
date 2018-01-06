#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    int c;
    while(b){
        c=a%b;a=b;b=c;

    }
    return a;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,k;
    cin>>t;
    int kase=1,ans;
    while(t--)
    {
        ans=1;
        int x,y;
        cin>>x>>y;
        if (x>y) swap(x,y);
        k=gcd(x,y);
        while(y%(x+k)==0)
        {
            ++ans;
            y=y/(x/k+1);
            if (x>y) swap(x,y);
            k=gcd(x,y);
        }
        cout<<"Case #"<<kase++<<": "<<ans<<endl;
    }
    return 0;
}
