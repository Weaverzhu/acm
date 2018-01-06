#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10;
vector<int> G[maxn];
int ru[maxn],q[maxn],ru2[maxn];
bool lef[maxn],sign[maxn];
int c,p,x,l;
void solve()
{
    memset(ru,0,sizeof(ru));
    memset(ru2,0,sizeof(ru2));
    memset(lef,false,sizeof(lef));
    memset(sign,false,sizeof(sign));
    for (int i=1;i<=p;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        ++ru[u];++ru[v];
        ++ru2[u];++ru2[v];
        G[u].push_back(v);G[v].push_back(u);
    }
    int op=0,cl=-1;
    q[0]=x;
    do
    {
        ++cl;lef[q[cl]]=true;
        if (lef[l])
        {
            puts("leave");return;
        }
        int now=q[cl],sz=G[now].size();
        if (sign[now]) continue;
            else sign[now] =true;
        for (int i=0;i<sz;++i)
        {
            --ru[G[now][i]];
            if (ru[G[now][i]]*2<=ru2[G[now][i]]) q[++op]=G[now][i];
        }
    }while(cl<=op);
    puts("stay");
}

int main()
{
//    freopen("in.txt","r",stdin);
    while(scanf("%d%d%d%d",&c,&p,&l,&x)!=-1) solve();
    return 0;
}
