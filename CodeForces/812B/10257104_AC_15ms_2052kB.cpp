#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

char maps[20][105];
int l[20],r[20];
int d[20][2];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=n;i>=1;i--) {
        scanf("%s",maps[i]);
        l[i] = m+1;
        r[i] = 0;
        for(int j=0;j<m+2;j++) {
            if(maps[i][j]=='1') {
                r[i] = max(j,r[i]);
                l[i] = min(j,l[i]);
            }
        }
    }

    for(int i=n;i>=1;i--) {
        if(r[i]==0)
            n--;
        else break;
    }

    for(int i=n;i>=1;i--) {
        l[i] = m - l[i] + 1;
    }

    if(n==0) {
        puts("0");
        return 0;
    }

    if(n==1) {
        printf("%d\n",r[1]);
        return 0;
    }

    memset(d,inf,sizeof(d));
    d[1][0] = 2*r[1]+1;
    d[1][1] = m+2;

    for(int i=2;i<n;i++) {
        d[i][0] = min(d[i-1][0]+2*r[i],d[i-1][1]+m+1) + 1;
        d[i][1] = min(d[i-1][0]+m+1,d[i-1][1]+2*l[i]) + 1;

    }

    int ans = min(d[n-1][0]+r[n],d[n-1][1]+l[n]);

    printf("%d\n",ans);

    return 0;
}