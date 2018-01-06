#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long LL;
int k, p;
LL now;
int cnt;
LL a[10], s[10], c[10];
int main(){
    cnt = 0;
    scanf("%d%d", &k, &p);
    for (int i=0; i<=5; ++i){
        int st=1, nc = 0;
        for (int j=0; j<i; ++j)
            st *= 10;
        for (int j=st; j<=10*st-1; ++j){
            int t = j;
            now = j;
            while(t){
                int x = t%10;
                now = (now*10 + x) % p;
                t /= 10;
            }
            a[i] += (now % p);
            a[i] = a[i] % p;
        }
        c[i] = 9*st;
        if (i > 0) c[i] += c[i-1];
    }
    s[0] = a[0];
    for (int i=1; i<=5; ++i)
        s[i] = (a[i]+s[i-1]) % p;
    int x = 0;
    for (int i=0; i<=5; ++i){
        if (k-c[i] < 0) {x = i-1; break;}
    }
    LL ans = 0;
    if (x == -1) ans = 0;
    else ans = s[x];
    k -= c[x];
    ++x;

    int st = 1;
    for (int i=0; i<x; ++i) st *= 10;
    for (int j=st; j<st+k; ++j){
        LL now = j, t = j;
        while(t){
            int x = t % 10;
            now = (now * 10 + x) % p;
            t /= 10;
        }
        ans = (ans + (now%p)) % p;
    }
    cout << ans << endl;


    return 0;
}