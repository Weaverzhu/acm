#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int  maxv = 1e5+10, maxm = 3e5+10;
const int inf = 100000000;
int head[maxv], tot;
struct node
{
    int next, c, to;
} E[maxm];
struct Max_flow
{
    int S, T, n;
    int lev[maxv], q[maxv], cur[maxv], f;
    void init(int _S, int _T)
    {
        tot = 0;
        S = _S; T = _T;
        n = T+1;
        for (int i=0; i<=n; ++i) head[i] = -1;

    }
    void add(int a, int b, int c)
    {
        E[tot].next = head[a];
        E[tot].to = b;
        E[tot].c = c;
        head[a] = tot++;
    }
    void Add(int a, int b, int c)
    {
        add(a, b, c);
        add(b, a, 0);
    }
    int bfs()
    {
        for (int i=0; i<=n; ++i) lev[i] = 0;
        lev[S] = 1;
        f = 0;
        q[f++] = S;
        for (int i=0; i<f; ++i)
        {
            int u = q[i];
            for (int i=head[u]; i!=-1; i=E[i].next)
                if (lev[E[i].to]==0 && E[i].c>0)
            {
                int to = E[i].to;
                lev[to] = lev[u]+1;
                q[f++] = to;
                if (to == T) return 1;
            }
        }
        return 0;
    }
    int dfs(int u, int f)
    {
        if (u == T) return f;
        int tag = 0, c;
        for (int &i=cur[u]; i!=-1; i=E[i].next)
        {
            int to = E[i].to;
            if (E[i].c>0 && lev[to]==lev[u]+1)
            {
                c = dfs(to, min(f-tag, E[i].c));
                E[i].c -= c;
                E[i^1].c += c;
                tag +=c;
                if (tag == f) return tag;

            }
        }
        return tag;
    }
    int solve()
    {
        int ans = 0;
        while(bfs())
        {
            for (int i=0; i<=n; ++i) cur[i] = head[i];
            ans += dfs(S, inf);
        }
        return ans;
    }
}Flow;
int n, m;
int main()
{

    while(~scanf("%d%d", &n, &m))
    {
        Flow.init(1, n);
        while(m--)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            Flow.Add(a, b, c);
        }
        printf("%d\n", Flow.solve());

    }
}
