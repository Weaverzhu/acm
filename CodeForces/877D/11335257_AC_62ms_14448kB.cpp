#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 1000+10;
int n, m, k;
int x1, y1, x2, y2;
char mp[maxn][maxn];
bool vis[maxn][maxn];
int dist[maxn][maxn];
const int INF = 0x3f3f3f3f;

struct node
{
    int x, y;
};
queue<node> Q;

void bfs()
{
    Q.push((node){x1, y1});
    dist[x1][y1] = 0;
    while(!Q.empty())
    {
        int nx = Q.front().x, ny = Q.front().y;
        Q.pop();
        for (int kk=1; kk<=k; ++kk)
        {
            int tx = nx+kk, ty = ny;
            if (tx>=n || ty>=m || tx<0 || ty<0 || mp[tx][ty]=='#'||dist[nx][ny]+1>dist[tx][ty]) break;
            if (!vis[tx][ty])
            {
                Q.push((node){tx, ty});
                dist[tx][ty] = dist[nx][ny]+1;
                vis[tx][ty] = 1;
            }
            if (tx == n-1) break;
        }
        for (int kk=1; kk<=k; ++kk)
        {
            int tx = nx, ty = ny+kk;
            if (tx>=n || ty>=m || tx<0 || ty<0 || mp[tx][ty]=='#'||dist[nx][ny]+1>dist[tx][ty]) break;
            if (!vis[tx][ty])
            {
                Q.push((node){tx, ty});
                dist[tx][ty] = dist[nx][ny]+1;
                vis[tx][ty] = 1;
            }
            if (ty == m-1) break;
        }
        for (int kk=1; kk<=k; ++kk)
        {

            int tx = nx-kk, ty = ny;
            if (tx>=n || ty>=m || tx<0 || ty<0 || mp[tx][ty]=='#'||dist[nx][ny]+1>dist[tx][ty]) break;
            if (!vis[tx][ty])
            {
                Q.push((node){tx, ty});
                dist[tx][ty] = dist[nx][ny]+1;
                vis[tx][ty] = 1;
            }
            if (tx == 0) break;
        }
        for (int kk=1; kk<=k; ++kk)
        {
            int tx = nx, ty = ny-kk;
            if (tx>=n || ty>=m || tx<0 || ty<0 || mp[tx][ty]=='#'||dist[nx][ny]+1>dist[tx][ty]) break;
            if (!vis[tx][ty])
            {
                Q.push((node){tx, ty});
                dist[tx][ty] = dist[nx][ny]+1;
                vis[tx][ty] = 1;
            }
            if (ty == 0) break;
        }
    }

//    for (int i=0; i<n; ++i)
//    {
//        for (int j=0; j<m; ++j)
//            printf("%d ", dist[i][j]);
//        printf("\n");
//    }
}

void solve()
{
    memset(vis, 0, sizeof(vis));
    memset(dist ,INF, sizeof(dist));
    for (int i=0; i<n; ++i)
        scanf("%s", mp[i]);
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    --x1, --x2, --y1, --y2;
    bfs();
    if (dist[x2][y2] == INF)
        printf("-1\n");
    else
        printf("%d\n", dist[x2][y2]);
}

int main()
{
    while(scanf("%d%d%d", &n, &m, &k) != -1)
        solve();
    return 0;
}
