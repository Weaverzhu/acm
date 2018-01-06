#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
int a[N], x[N];
int n;
int main(){
    scanf("%d", &n);
    int m1 = 0, m2 = 0, m1i;

    for (int i=1; i<=n; ++i){
        scanf("%d", &x[i]);
        int now = x[i];
        if(now > m1){
            m2 = m1;
            m1 = now; m1i = i;

            --a[i];
        }else if (now <= m1 && now > m2){
            m2 = now;
            ++a[m1i];
        }
    }
    if (n == 1){
        printf("1\n");
        return 0;
    }
    int mx=-100, mi=0;
    x[0] = 1e9;
    for (int i=1; i<=n; ++i){
        if ((a[i] > mx) || (a[i] == mx && x[i] < x[mi])){
            mi = i;
            mx = a[i];
        }
    }
    printf("%d\n", x[mi]);
}