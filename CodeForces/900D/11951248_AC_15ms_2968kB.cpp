#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M = 1e9+7;
LL a, b;
bool isp[200005];
int cnt, p[200005];
void getp(){
    for (int i=2; i<=2e5; ++i){
        if (!isp[i]){
            p[cnt++] = i;
            for (int j=2*i; j<=2e5; j+=i)
                isp[j] = true;
        }
    }
}
LL pmd(LL a, LL b){
    LL res = 1;
    while(b){
        if (b%2) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
int main(){

    getp();
    cin >> a >> b;
    if (b%a != 0){
        printf("0\n");
        return 0;
    }
    LL t = b/a;
    b /= a; a = 1;
    LL res = 1;
    vector<LL> f;
//    if (b == 2){
//        printf("2\n");
//        return 0;
//    }
    for (int i=0; i<cnt; ++i){
//        if (p[i]*p[i] > b) break;
        if (b%p[i] == 0){
            f.push_back(p[i]);
            while(b%p[i] == 0) b /= p[i];
        }
    }
    if (b > 1) f.push_back(b);
    int sz = f.size();
   // for (int i=0; i<sz; ++i){
   //     printf("%lld ", f[i]);
   // }
   // cout << endl;
    LL ans = 0;
    LL sz2 = (1<<sz)-1;
    for (int i=0; i<=sz2; ++i){
        LL now = 1;
        int j = i, k = 0, sgn = 1;
        while(j){

            if (j%2) now *= f[k], sgn = -sgn;
            k++;
            j >>= 1;
        }
        // cout << now << endl;
        // cout << t/now-1 << endl;
        ans = (ans+M + sgn*pmd(2, t/now-1)) % M;
    }
    cout << (ans+M) % M << endl;
    return 0;
}