#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000+10;
int a[maxn];
int nim[2*maxn], ni;
void solve()
{
    ni = 0;
    int st;
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    if (n%2)
    {
        nim[ni++] = a[1]-1; st = 2;
    }
    else st = 1;
    for (int i=st; i<n; ++i)
        nim[ni++] = a[i+1]-a[i]-1;
    int check = nim[0];
    for (int i=1; i<ni; ++i) check ^= nim[i];
    if (check) puts("Georgia will win");
    else puts("Bob will win");
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
