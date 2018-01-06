#include<bits/stdc++.h> 

using namespace std;

int n;
int num1, num2;
long long w;
long long a[1000000];

set <long long>s1;
set <long long>s2;


void dfs1(long long sum, int x, int num)
{
    if (x == num1)
    {
        s1.insert(sum);
        return;
    }
    for (int i = 0; i <= 2; i++)
        dfs1(sum + a[x] * i,x + 1, num + 1);
}

void dfs2(long long sum,int x, int num)
{
    if (x == n)
    {
        s2.insert(sum);
        return;
    }
    for (int i = 0; i <= 2; i++)
        dfs2(sum + a[x] * i, x + 1, num + 1);
}



int main()
{
    int t;
    scanf("%d", &t);
    int cases = 1;
    while (t--)
    {
        s1.clear();
        s2.clear();
        memset(a, 0, sizeof(a));

        scanf("%d %lld", &n, &w);

        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);

        num1 = n >> 1;
        num2 = n - num1;

        dfs1(0, 0, num1);
        dfs2(0, num1, n);

        int ok = 0;

        set <long long> ::iterator it;
        for (it = s1.begin(); it != s1.end(); it++)
        {
            int tmp = *it;
            //cout << tmp << endl;
            if (s2.count(w-tmp) != 0)
            {
                ok = 1;
                break;
            }
        }

        if (ok) printf("Case %d: Yes\n", cases++);
        else printf("Case %d: No\n", cases++);
    }
    return 0;
}
