#include<bits/stdc++.h>
using namespace std;
int l[50];
int d[10];
int main()
{
    int t,n,i,j,ll;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll = 0;
        memset(l, 0, sizeof(l));
        for(i = 1; i <= n; i++)
        {
            int k = 6;
            while(k--)
            {
            int a;
            cin>>a;
            l[a]++;
            }
        }
        for(i = 1; i <= 6; i++)
        {
            int maxn = 0, maxi;
            for(j = 1; j <= 49; j++)
                if(l[j] > maxn) maxn = l[j], maxi = j;
            if(l[7] == maxn)
            {
                l[7] = 0;
                d[++ll] = 7;
            }
            else
            {
                l[maxi] = 0;
                d[++ll] = maxi;
            }
        }
        sort(d + 1, d + 7);
        printf("%d %d %d %d %d %d\n", d[1], d[2], d[3], d[4], d[5], d[6]);

    }
    return 0;
}
