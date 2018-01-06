#include<bits/stdc++.h>
using namespace std;

const int maxl=1e5+10;
char s[maxl],p[maxl];
int a[26],b[26];
int num;

bool com()
{
    int tmp=num;
    for (int i=0;i<26;++i)
    {
        if (a[i]<b[i])
        {
            tmp-=b[i]-a[i];
            if (tmp<0) return false;
        }
        else if (a[i]>b[i]) return false;
    }
    if (tmp>=0) return true;
    else return false;
}

void solve()
{
    scanf("%s",p);
    int ls=strlen(s),lp=strlen(p);
    if (ls<lp)
    {
        cout<<"0\n";
        return;
    }
    for (int i=0;i<lp;++i) ++b[p[i]-'a'];
    num=0;
    for (int i=0;i<lp;++i)
    {
        if (s[i]=='?') ++num;
        else ++a[s[i]-'a'];
    }
    int op=0;
    int ans=0;
    while(lp-1+op<ls)
    {
        if (com()) ++ans;
        if (s[op]=='?') --num;
        else --a[s[op]-'a'];
        ++op;
        if (lp-1+op>=ls) break;
        if (s[op+lp-1]=='?') ++num;
        else ++a[s[op+lp-1]-'a'];
    }
    cout<<ans<<endl;
    return;
}


int main()
{
    while(scanf("%s",s)!=-1) solve();
    return 0;
}
