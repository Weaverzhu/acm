#include <bits/stdc++.h>

using namespace std;

char c[1234567];
map <char, int> mp;

int main()
{
    scanf("%s", c);
    int len = strlen(c);
    for (int i=0; i<len; i++) {
        mp.clear();
        mp[c[i]]++;
        mp[c[i+1]]++;
        mp[c[i+2]]++;
        if (mp['R'] != 0 && mp['B'] != 0 && mp['L'] != 0) {
            printf("C");
            i+=2;
        }
            else {
                if (c[i] == 'R') printf("S");
                if (c[i] == 'B') printf("K");
                if (c[i] == 'L') printf("H");
            }
    }
    return 0;
}
