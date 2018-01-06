#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    if (n == 1 && t == 10)
    {
        cout << -1 << endl;
        return 0;
    }

    if (t == 10)
    {
        printf("1");
        for (int i=1; i<=n-1; ++i) printf("0");

    }
    else
    {
        printf("%d", t);
        for (int i=1; i<=n-1; ++i) printf("0");
    }
    printf("\n");
    return 0;
}
