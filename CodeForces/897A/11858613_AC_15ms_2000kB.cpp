#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m;
char s[N];

int main(){
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    for (int i=0; i<m; ++i){
        int l, r;
        char c1[5], c2[5];
        scanf("%d%d%s%s", &l, &r, c1, c2);
        for (int j=l-1; j<=r-1; ++j){
            if (s[j] == c1[0]) s[j] = c2[0];
        }
    }
    cout << s << endl;

    return 0;
}