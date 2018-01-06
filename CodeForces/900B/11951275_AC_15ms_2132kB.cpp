#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
set<LL> S;
int main(){
    LL a, b, c, k;
    cin >> a >> b >> c;
    int pos = 0;
    while(1){
        ++pos;
        a = a*10;
        if (S.count(a)){
            printf("-1\n");
            break;
        }
        S.insert(a);
        LL now = a/b;
        if (now == c){
            printf("%d\n", pos);
            break;
        }

        a = a%b;
    }
    return 0;
}