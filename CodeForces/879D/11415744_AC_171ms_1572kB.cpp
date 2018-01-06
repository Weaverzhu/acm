#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
using namespace std;
const int M = 1e5 + 10;
typedef long long ll;
ll Stack[M][2];
int main() {
    int n , k , m , x , top = 0;
    ll ans = 0;
    cin >> n >> k >> m;
    for(int i = 0 ; i < n ; i++) {
        cin >> x;
        if(!top || Stack[top][0] != x) {
            Stack[++top][0] = x;
            Stack[top][1] = 1;
        }
        else {
            Stack[top][1]++;
        }
        if(Stack[top][1] == k) {
            Stack[top--][1] -= k;
        }
    }
    ll sum = 0;
    for(int i = 1 ; i <= top ; i++) {
        sum += Stack[i][1];
    }
    int sta = 1 , ed = top;
    while(sta < ed && Stack[sta][0] == Stack[ed][0]) {
        if((Stack[sta][1] + Stack[ed][1]) % k == 0) {
            sta++ , ed--;
        }
        else {
            Stack[sta][1] = (Stack[sta][1] + Stack[ed][1]) % k;
            Stack[ed][1] = 0;
            break;
        }
    }
    if(sta < ed) {
        for(int i = sta ; i <= ed ; i++) ans += Stack[i][1];
        ans *= (m - 1);
        ans += sum;
    }
    else if(sta == ed) {
        if(Stack[sta][1] * m % k == 0) ans = 0;
        else {
            ans = sum + Stack[sta][1] * (m - 1);
            ans -= Stack[sta][1] * m - Stack[sta][1] * m % k;
        }
    }
    cout << ans << endl;
    return 0;
}