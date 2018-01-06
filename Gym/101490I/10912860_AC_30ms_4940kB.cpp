#include <bits/stdc++.h>

using namespace std;

int prime[1234567];

void init (int n) {
    memset(prime, 0, sizeof(prime));
    for (int i=2; i<=n; i++) {
        if (prime[i]) continue;
        for (int j=2*i; j<=n; j+=i) {
            prime[j] = 1;
        }
    }
}

int main()
{
    init(1000000);
//    for (int i=1; i<=20; i++) cout <<i<<' ' <<prime[i] <<endl;
    long long n;
    cin >> n;
    int flag= 0;
    for (int i=2; i<=1000000; i++) {
        if (i >n) break;
        if (flag) break;
        long long k = i, num = k;
        if (!prime[i]) {
            while (num < n) {
                num *= k;
            }
            if (num == n) flag = 1;
            if(flag) break;
        }
    }
    if (flag) puts("yes");
        else puts("no");
    return 0;
}
