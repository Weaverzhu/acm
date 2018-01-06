#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a, b, n;
int main(){
    int t;
    cin >> t;
    for (int kk=1; kk<=t; ++kk){
        scanf("%I64d", &n);
        printf("Case #%d: %lld\n", kk, n/3);
    }
    return 0;
}