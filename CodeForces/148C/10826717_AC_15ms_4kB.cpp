#include<bits/stdc++.h>
using namespace std;
int n, a, b;

int main()
{
    while(scanf("%d%d%d", &n, &a, &b) != -1)
    {
        int Lim =50000;
        bool suc = true;
        if (n == 1 && a == 0 && b == 0)
        {
            cout << 1 << endl; continue;
        }
        else if (n == 1 && a + b > 0)
        {
            cout << -1 << endl;
            continue;
        }
        if (a + b > n-1 )
        {
            cout << -1 << endl;
            continue;
        }
        int ans[100 + 10], top;
        top = 1;
        ans[1] = 1;
        if (b==0) ans[++top] = 1;
        else{
        for (int i=1; i<=b; ++i)
        {
            ans[++top] = ans[top - 1] * 2;
            if (ans[top] > Lim) {suc = false; break;}
        }
        }
        if (!suc)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i=1; i<=a; ++i)
        {
            ans[++top] = ans[top - 1] + 1;
            if (ans[top] > Lim) {suc =false; break;}
        }
        if (top > n) suc = false;
        if (!suc) {cout << -1 << endl; continue;}
        else
        {
            for (int i=1; i<top; ++i) printf("%d ", ans[i]);
            if (top == n) {printf("%d\n", ans[top]);continue;}
            else printf("%d ", ans[top]);
            for (int i=top + 1; i < n; ++i) printf("%d ", 1);
            printf("%d\n", 1);
            continue;
        }
    }

    return 0;
}
