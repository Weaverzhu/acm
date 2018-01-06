#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 205;
const int M = 1e9+7;
LL pmd(LL a, LL b){
    LL res = 1;
    while(b){
        if (b%2) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res % M;
}
int n, m, k, t;
int main(){
    scanf("%d", &t);
    for(int kk=1; kk<=t; ++kk){

        scanf("%d%d%d", &n, &m, &k);
        LL ans = 0;
        if (n == 1 && m == 1){
            ans = k*2;
        }
        else{
            for (int i=1; i<=k-1; ++i){
                ans = (ans + pmd(i, n+m-2) * pmd(k, (n-1)*(m-1)) % M) % M;
            }
            ans = ans * n % M * m % M;
            ans = (ans + pmd(k, n * m)) % M;
        }
        printf("Case #%d: %lld\n", kk, ans);
    }
    return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//
//int n, m, k;
//int main(){
//    int t;
//    scanf("%d", &t);
//    for (int kk=1; kk<=t; ++kk){
//        printf("Case #%d: ");
//        scanf("%d", &n);
//        printf("%d\n", )
//    }
//}