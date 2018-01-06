#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL x, delta, a;
LL d, r, t;
void solve()
{
    LL a1 = 4, a2 = -3, b1 = 3 - d, b2 = (-d - 3 + 1);
    LL ax = 2, bx = a1+a2+b1+b2, cx = a1*a2+b1*b2-2*r-2*t;
    delta = bx*bx-4*ax*cx;
    delta = round( sqrt(delta) - 0.5);
    LL ans1 = (-bx+delta)/(2*ax), ans2 = (-bx-delta)/(2*ax), ans;
    ans = max(ans1, ans2);
    LL num = r-(ans+4)*(ans-3)/2;
    cout << num << endl;

}


int main()
{
    while(cin >> d >> r >> t) solve();
    return 0;
}
