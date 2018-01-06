#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
char s[N];
int main(){
    scanf("%s", s);
    long long n = 0;

    int len = strlen(s);
    for (int i=0; i<len; ++i){
        int now = s[i]-'0';
        n = n*10 + now;
    }
    if (s[len-1] >= '0' && s[len-1] <= '5')
        n -= s[len-1] - '0';
    else n += 10+'0'-s[len-1];
    cout << n << endl;

    return 0;
}