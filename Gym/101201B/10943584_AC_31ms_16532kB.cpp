#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
using namespace std;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
int f[60][60][60],v[60][60],a[60][60],bx,by,ex,ey,n,m,l;
pi q[2000010];
char s[60];

void bfs(int k)
{
    int h=1,r=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i][j])
            {
                q[++r]=mp(i,j);
                v[i][j]=1;
            }

    while (h<=r)
    {
        int i=q[h].first,j=q[h].second;
        v[i][j]=0; h++;
        for (int w=0; w<4; w++)
        {
            int x=i+dx[w],y=j+dy[w];
            if (!a[x][y]) continue;
            if (f[x][y][k]>f[i][j][k]+1)
            {
                f[x][y][k]=f[i][j][k]+1;
                if (!v[x][y])
                {
                    q[++r]=mp(x,y);
                    v[x][y]=1;
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++)
    {
        scanf("%s",s+1);
        for (int j=1; j<=m; j++)
        {
            if (s[j]!='#') a[i][j]=1;
            if (s[j]=='R')
            {
                bx=i;
                by=j;
            }
            if (s[j]=='E')
            {
                ex=i;
                ey=j;
            }
        }
    }
    scanf("%s",s+1);
    l=strlen(s+1);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            for (int k=0; k<=l+1; k++) f[i][j][k]=1e9;
    int ans=1e9;
    f[bx][by][0]=0;
    for (int k=1; k<=l+1; k++)
    {
        bfs(k-1);
        ans=min(ans,f[ex][ey][k-1]);
        if (k==l+1) break;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                if (a[i][j])
                {
                    int pw;
                    if (s[k]=='L') pw=2;
                    if (s[k]=='R') pw=3;
                    if (s[k]=='U') pw=0;
                    if (s[k]=='D') pw=1;
                    int x=i+dx[pw],y=j+dy[pw];
                    if (a[x][y]) f[x][y][k]=min(f[i][j][k-1],f[x][y][k]);
                    else f[i][j][k]=min(f[i][j][k-1],f[i][j][k]);
                    f[i][j][k]=min(f[i][j][k-1]+1,f[i][j][k]);
                }
    }
    printf("%d\n",ans);
}