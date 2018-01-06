#include <bits/stdc++.h>
using namespace std;
int a[200005], val[200005];
vector<int> tree[200005];
int vis[200005];
int divisors[1005];

void dfs(int cur, int div)
{
    vis[cur] = 1;
    for (int i = 0; i < tree[cur].size(); i++)
    {
        int tmp = tree[cur][i];
        if (vis[tmp]) continue;
        val[tmp] = __gcd(div, a[tmp]);
        dfs(tmp, val[tmp]);
    }
}

void dfs2(int cur, int d, vector<int>& v)
{
    vis[cur] = 1;
    for (int i = 0; i < tree[cur].size(); i++)
    {
        int tmp = tree[cur][i];
        if (vis[tmp]) continue;
         for (int j = 0; j < v.size(); j++)
        {
            if (a[tmp] % v[j] == 0) divisors[j]++;
            if (divisors[j] >= d) val[tmp] = max(val[tmp], v[j]);
        }
        dfs2(tmp, d + 1, v);
        for (int j = 0; j < v.size(); j++)
            if (a[tmp] % v[j] == 0) divisors[j]--;
    }
}

int main()
{
    int n, x, y;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            tree[i].clear();
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x >> y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        int tmp = a[1];
        a[1] = 0;
        memset(vis, 0, sizeof vis);
        dfs(1, 0);
        a[1] = val[1] = tmp;
        vector<int> v;
        for (int i = 1; i * i <= a[1]; i++)
        {
            if (a[1] % i == 0)
            {
                v.push_back(i);
                if (a[1] / i != i) v.push_back(a[1] / i);
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) divisors[i] = 1;
        memset(vis, 0, sizeof vis);
        dfs2(1, 1, v);
        for (int i = 1; i <= n; i++)
            cout << val[i] << " ";
        cout << endl;
    }
    return 0;
}