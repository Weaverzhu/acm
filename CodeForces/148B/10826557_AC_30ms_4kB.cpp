#include<bits/stdc++.h>
using namespace std;
int main()
{
    double vp,vd,t,f,c;
    cin >> vp >> vd >> t >> f >> c;
    if (vp >= vd)
    {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    double begin = vp * t;   
    while(1)
    {
        double T = begin * 1.0 / (vd - vp);
        begin += vp * T;
        if (begin - c >= 0) break;
        else
        {
            begin += (T + f) * vp;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}