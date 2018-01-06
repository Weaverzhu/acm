#include<bits/stdc++.h>
using namespace std;
const int maxn=500+10;
const int maxm=250000;
int m1[maxn][maxn],m2[maxn][maxn];
bool vis[maxn][maxn];
int qx[maxm],qy[maxm];
const int dx[4]={0,-1,1,0};
const int dy[4]={1,0,0,-1};
int n,m;
bool dfs(int nx,int ny)
{
    vis[nx][ny]=1;
    for (int r=0;r<4;++r)
    {
        int tx=nx+dx[r],ty=ny+dy[r];
        if (tx>n&&ty>0&&ty<=m) return true;
        if (tx>0&&ty>0&&ty<=m&&!vis[tx][ty]&&m2[tx][ty]==0)
        {
            if (dfs(tx,ty)) return true;
        }
    }
    return false;
}
void solve()
{

    scanf("%d%d",&n,&m);
    string line;
    for (int i=1;i<=n;++i)
    {
        cin>>line;
        for (int j=1;j<=m;++j) m1[i][j]=line[j-1]-'0';
    }
    int q;
    scanf("%d",&q);
    for (int i=1;i<=q;++i) scanf("%d%d",&qx[i],&qy[i]);
    //init
    int left=0,right=q,mid;
    while(left<right-1)
    {
        mid=(left+right)/2;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
            {
                m2[i][j]=m1[i][j];
            }
        for (int i=1;i<=mid;++i) m2[qx[i]+1][qy[i]+1]=1;
        int sx,sy;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                if (m2[i][j]==0)
                {
                    sx=i;sy=j;
                    break;
                }

        bool suc=false;
        for (int i=1;i<=m;++i)
        {
            if (m2[1][i]==0&&suc==false)
            {
                memset(vis,0,sizeof(vis));
                suc=dfs(1,i);
            }
            if (suc) break;
        }

        if (suc) left=mid;
        else right=mid;
    }
    cout<<left+1<<endl;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}
