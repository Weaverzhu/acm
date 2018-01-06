#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
typedef long long LL;
const LL M = 998244353;
LL f1[N], f2[N], f3[N];
int n, x, k;
int main(){
    cin >> n >> x >> k;
    f1[0] = 1;
//    k = 1;
    for (int i=x; i<=n; ++i){
        for (int j=n; j>=i*k; --j){
            f1[j] = (f1[j]+M-f1[j-i*k])%M;
        }
    }
    f2[0] = 1;
    for (int i=x; i<=n; ++i)
    for (int j=i; j<=n; ++j){
        f2[j] = (f2[j] + f2[j-i])%M;
    }
    for (int i=0; i<=n; ++i)
        for (int j=0; j<=n; ++j)
        if (i+j <= n)
        f3[i+j] = (f3[i+j] + f1[i]*f2[j]%M) % M;
    LL ans = 0;
    for (int i=1; i<=n; ++i)
        ans = (ans + f3[i]) % M;
    cout << ans%M << endl;


    return 0;
}
