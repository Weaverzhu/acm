#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5e5+10;
char s[maxn];
int r[maxn],sum[maxn],n;
struct cmp
{
    bool operator()(int x,int y)
    {
        return x+r[x]>y+r[y];
    }
};
priority_queue<int,vector<int>,cmp>q;
int lowbit(int x){return x&(-x);}
void update(int x,int num)
{
    while(x<=n)
    {
        sum[x]+=num;
        x+=lowbit(x);
    }
    return ;
}
inline int query(int x)
{
    int ans=0;
    while(x)
    {
        ans+=sum[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        scanf("%s", s);
        n=strlen(s);
        for(int i=n;i>0;i--)s[i]=s[i-1],sum[i]=0;
        s[0]='#';s[n+1]='\n';
        int mx=0,id=0;
        for(int i=1;i<=n;i++)
        {
            if(mx>i)r[i]=(r[2*id-i]<(mx-i)?r[2*id-i]:(mx-i));
            else r[i]=1;
            while(s[i-r[i]]==s[i+r[i]])r[i]++;
            if(i+r[i]>mx)mx=i+r[i],id=i;
        }
        for(int i=1;i<=n;i++)r[i]--;
        LL ans=0;int num=0;
        while(!q.empty())q.pop();
        q.push(1);
        update(1,1);num++;
        for(int i=2;i<=n;i++)
        {
            while(!q.empty())
            {
                int fr=q.top();
                if(fr+r[fr]<i)
                {
                    q.pop();
                    num--;
                    update(fr,-1);
                }
                else break;
            }
            ans=ans+num-query(i-r[i]-1);
            q.push(i);update(i,1);num++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}