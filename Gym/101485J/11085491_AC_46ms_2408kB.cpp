#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int a[maxn];

int main()
{
    for (int i=0; i<=1000; ++i)
    {
        int e = (i<<1) & 255;
        int m = i^e;
        a[m] = i;

    }
    int n;
    while(cin >> n)
    {
        int x;
        for (int i=0; i<n; ++i)
        {
            cin >> x;
            cout << a[x] << " ";
        }
        cout << endl;

    }
    return 0;
}