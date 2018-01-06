#include<bits/stdc++.h>
using namespace std;
const int maxn = 400+10;
int a[maxn][maxn];

void solve()
{
    int n, m;
    int ans = 0;
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; ++i)
    {
        string line;
        cin >> line;
        for (int j=0; j<m; ++j)
        {
            a[i][j] = line[j]-'0';
        }
    }
    for (int i=0; i<n; ++i)
    {
        for (int j=m-1; j>=0; --j)
        {
            if (!a[i][j])
            {
                for (int k=0; k<=j; ++k)
                    a[i][k] = (a[i][k]+1) % 2;
                for (int k=i+1; k<n; ++k)
                    a[k][j] = (a[k][j]+1) % 2;
                ++ans;
            }

        }

    }
    cout << ans << endl;


}

int main()
{

    int t;
    scanf("%d", &t);
    while(t--) solve();

    return 0;
}
