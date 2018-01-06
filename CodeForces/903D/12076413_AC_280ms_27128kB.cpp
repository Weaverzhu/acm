#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5+5;

LL a[N];
map<LL, LL> s;
int n;

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
        scanf("%lld", &a[i]);
    long double ans = 0;
    for (int i=1; i<=n; ++i){
        s[a[i]]++;
        ans += (i-1-n+i)*a[i] + s[a[i]+1]-s[a[i]-1];
    }
    cout << fixed <<setprecision(0) << ans <<endl;


    return 0;
}
