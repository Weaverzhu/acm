#include<bits/stdc++.h>
using namespace std;

int f[100][100];
int main()
{
    memset(f, 0 ,sizeof(f));
    string a,b;
    b = "abcdefghijklmnopqrstuvwxyz";
    cin >> a;
    int la = a.length(), lb = b.length();
    for (int i=0; i<la; ++i)
        for (int j=0; j<lb; ++j)
    {
        if (a[i] == b[j])
        {
            if (i==0 || j==0) f[i][j] = 1;
            else
            {
                int tmp = f[i-1][j-1]+1;
                tmp = max(tmp, f[i][j-1]);
                tmp = max(tmp, f[i-1][j]);
                f[i][j] = tmp;
            }
        }
        else
        {
            f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    cout << 26-f[la-1][lb-1] << endl;
    return 0;
}
