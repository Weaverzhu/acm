#include <cstdio>  
#include <iostream>  
#include <cmath>  
#include <set>  
  
using namespace std;  
  
typedef long long ll;  
const int max_n = 200005;  
ll b,a,dp1[max_n],dp2[max_n];  
int n;  
  
int main() {  
    cin >> n;  
    cin >> a;  
    int f = 1;  
    for(int i = 1; i < n; ++i) {  
        cin >> b;  
        dp1[i-1] = abs(a-b)*f;  
        dp2[i-1] = abs(a-b)*(-f);  
        f = -f;  
        a = b;  
    }  
    ll mx = dp1[0];  
    ll tol = 0;  
    for(int i = 0; i < n-1; ++i) {  
        tol += dp1[i];  
        if(tol > mx) {  
            mx = tol;  
        }  
        if(tol < 0) {  
            tol = 0;  
        }  
    }  
    ll mx2 = dp2[0];  
    tol = 0;  
    for(int i = 0; i < n-1; ++i) {  
        tol += dp2[i];  
        if(tol > mx2) {  
            mx2 = tol;  
        }  
        if(tol < 0) {  
            tol = 0;  
        }  
    }  
    cout << max(mx,mx2);  
    return 0;  
}  