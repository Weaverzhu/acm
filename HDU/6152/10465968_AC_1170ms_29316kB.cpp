#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000 + 5;

int c[MAXN][MAXN];
int n, flag;

void dfs (int i, int num, int sign) {
    for (int j = i+1; j<=n; j++) {
        if (c[i][j] == sign && c[num][j] == sign) flag = 1;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i=1; i<n; i++) {
            for (int j=i+1; j<=n; j++) {
                scanf("%d", &c[i][j]);
            }
        }
        flag = 0;
        for (int i=1; i<n; i++) {
            if (flag) break;
            for (int j=i+1; j<=n; j++) {
                if (flag) break;
                if (c[i][j]) dfs(j, i, 1);
                    else if (!c[i][j]) dfs(j, i, 0);
            }
        }
        if (flag) puts("Bad Team!");
            else puts("Great Team!");
    }
    return 0;
}
