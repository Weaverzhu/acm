#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=30;
int map1[30][30];
int n,m;
int sx,sy;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
void init()
{
    string line;
    for (int i=1;i<=m;++i){
        cin>>line;
        for (int j=0;j<n;++j)
            if (line[j]=='.') map1[i][j+1]=0;
            else if (line[j]=='#') map1[i][j+1]=1;
            else if (line[j]=='@')
            {
                map1[i][j+1]=0;
                sx=i;sy=j+1;
            }
    }

    return;
}
int dfs(int nx,int ny)
{
    map1[nx][ny]=2;
    int ans=1;
    for (int r=0;r<4;++r)
    {
        int tx=nx+dx[r],ty=ny+dy[r];
        if (tx>=1&&tx<=m&&ty>=1&&ty<=n&&!map1[tx][ty]) ans+=dfs(tx,ty);
    }
    return ans;
}
int main()
{
    while(cin>>n>>m)
    {
        if (n==0&&m==0)break;
        if (n==0||m==0)
        {
            cout<<0<<endl;
            continue;
        }
        init();
        cout<<dfs(sx,sy)<<endl;
    }

    return 0;
}
