#include<bits/stdc++.h>
using namespace std;
const int maxl = 30+2;
int s[maxl];
typedef long long LL;


int main()
{
    int tmp, s_sz = 0;
    char str[maxl];
    scanf("%s", str); s_sz = strlen(str);
    for (int i=0; i<s_sz; ++i) s[i] = str[i] - '0';

    int x = 0, y = 0, dt = 1 << s_sz;
    for (int i=0; i<s_sz; ++i)
    {
        dt /= 2;
        int now = s[i];
        if (now == 1) x += dt;
        else if (now == 2) y += dt;
        else if (now ==3)
        {
            x += dt; y += dt;
        }
    }
    cout << s_sz << " " << x << " " <<  y << endl;

    return 0;
}
