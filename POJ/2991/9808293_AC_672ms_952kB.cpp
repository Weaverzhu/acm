#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXD 10010
const double PI = acos(-1.0);
int N, M, a[MAXD], A[MAXD], degree[MAXD], rd[4 * MAXD];
struct point
{
    double x, y;
}dp[4 * MAXD];
double getrad(int x)
{
    return x * PI / 180;
}
void build(int cur, int x, int y)
{
    int mid = (x + y) >> 1, ls = cur << 1, rs = (cur << 1) | 1;
    rd[cur] = 0;
    dp[cur].x = 0, dp[cur].y = A[y] - A[x - 1];
    if(x == y)
        return ;
    build(ls, x, mid);
    build(rs, mid + 1, y);
}
void init()
{
    int i;
    A[0] = 0;
    for(i = 1; i <= N; i ++)
    {
        scanf("%d", &a[i]);
        A[i] = A[i - 1] + a[i];
        degree[i] = 0;
    }
    build(1, 1, N);
}
void update(int cur)
{
    int ls = cur << 1, rs = (cur << 1) | 1;
    dp[cur].x = dp[ls].x + dp[rs].x, dp[cur].y = dp[ls].y + dp[rs].y;
}
void Rotate(double &dx, double &dy, double rad)
{
    double x = dx, y = dy;
    dx = x * cos(rad) - y * sin(rad);
    dy = x * sin(rad) + y * cos(rad);
}
void pushdown(int cur)
{
    int ls = cur << 1, rs = (cur << 1) | 1;
    if(rd[cur])
    {
        double rad = getrad(rd[cur]);
        rd[ls] += rd[cur], rd[rs] += rd[cur];
        Rotate(dp[ls].x, dp[ls].y, rad);
        Rotate(dp[rs].x, dp[rs].y, rad);
        rd[cur] = 0;
    }
}
void refresh(int cur, int x, int y, int k, int delta)
{
    int mid = (x + y) >> 1, ls = cur << 1, rs = (cur << 1) | 1;
    if(x == y)
    {
        double rad = getrad(delta);
        Rotate(dp[cur].x, dp[cur].y, rad);
        return ;
    }
    pushdown(cur);
    if(mid + 1 < k)
        refresh(rs, mid + 1, y, k, delta);
    else
    {
        double rad = getrad(delta);
        if(k <= mid)
            refresh(ls, x, mid, k, delta);
        Rotate(dp[rs].x, dp[rs].y, rad);
        rd[rs] += delta;
    }
    update(cur);
}
void solve()
{
    int i, j, k, d, delta;
    for(i = 0; i < M; i ++)
    {
        scanf("%d%d", &k, &d);
        ++ k, d = d - 180;
        delta = d - degree[k];
        degree[k] = d;
        refresh(1, 1, N, k, delta);
        printf("%.2f %.2f\n", dp[1].x, dp[1].y);
    }
}
int main()
{
    int t = 0;
    while(scanf("%d%d", &N, &M) == 2)
    {
        init();
        if(t ++)
            printf("\n");
        solve();
    }
    return 0;
}
