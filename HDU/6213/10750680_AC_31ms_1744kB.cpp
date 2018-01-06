#include <bits/stdc++.h>

using namespace std;

map <string, int> s;

void init () {
    s["rat"] = 1;
    s["ox"] = 2;
    s["tiger"] = 3;
    s["rabbit"] =4;
    s["dragon"] = 5;
    s["snake"] = 6;
    s["horse"] = 7;
    s["sheep"] =8;
    s["monkey"] = 9;
    s["rooster"] = 10;
    s["dog"] = 11;
    s["pig"] = 12;
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s[s1] < s[s2])  cout << s[s2] - s[s1] << endl;
            else cout << s[s2] + 12 - s[s1] << endl;
    }
    return 0;
}
