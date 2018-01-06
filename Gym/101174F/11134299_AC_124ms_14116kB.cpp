#include<bits/stdc++.h>
using namespace std;
const int E = 100000 + 10;
int e;
long long tree[E], pre[E], ans[E];
struct Node {
    int to, r, t;
} p;
vector<Node> g[E];
int lowbit(int x)   {   return x & -x;  }
void add(int r, int t) {
    for(int i=r;i<E;i+=lowbit(i))
        tree[i] += t;
}
long long get(int r) {
    long long ret = 0;
    for(int i=r;i;i-=lowbit(i))
        ret += tree[i];
    return ret;
}
void dfs(int rt, int rnk) {
    pre[rt] = get(rnk-1);
    for(int i=0;i<g[rt].size();i++)
    {
        dfs(g[rt][i].to, g[rt][i].r);
        add(g[rt][i].r, g[rt][i].t);
    }
    ans[rt] = get(rnk-1) - pre[rt];
}
int main()
{
    scanf("%d", &e);
    int rt, rnk;
    for(int i=1, fa;i<=e;i++)
    {
        scanf("%d %d %d", &fa, &p.r, &p.t);
        if(fa == -1)    {   rt = i; rnk = p.r;  continue;   }
        p.to = i;
        g[fa].push_back(p);
    }

    dfs(rt, rnk);

    for(int i=1;i<=e;i++)
        printf("%lld\n", ans[i]);
}