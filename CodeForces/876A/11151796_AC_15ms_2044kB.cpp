#include <iostream>
#include<cstdio>
using namespace std;
int min3(int a, int b, int c)
{
    return min(a, min(b, c));
}

int main()
{
    int a, b, c, n;
    while(scanf("%d%d%d%d", &n, &a, &b, &c) != -1)
    {
        if (n == 1) cout << 0 << endl;
        else if (n == 2) cout << min(a, b) << endl;
        else
        {
            if (min3(a, b, c) == a || min3(a, b, c) == b) cout << (n-1) * min3(a, b, c) << endl;
            else cout << min(a, b) + c*(n-2) << endl;
        }

    }
}