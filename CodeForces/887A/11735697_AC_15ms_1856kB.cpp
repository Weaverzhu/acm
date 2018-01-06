#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    auto p = s.find('1');
    cout << (p != string::npos && count(s.begin() + p, s.end(), '0') >= 6 ? "yes" : "no");
    return 0;
}