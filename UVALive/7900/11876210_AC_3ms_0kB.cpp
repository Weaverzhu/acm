#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
unsigned long long len[70];
int c[70];
int n, m;

int main(){
    len[0] = 1;
    for (int i=1; i<=63; ++i)
        len[i] = len[i-1]*2;
//    cout << len[63] <<endl<< len[62] <<endl<< len[61] << endl;
//    for (int i=0; i<=63; ++i)
//        cout << len[i] <<endl;

    int t;
    scanf("%d", &t);
    for (int kk=1; kk<=t; ++kk){
        memset(c, 0, sizeof(c));
//        printf("Case #%d: ", kk);

        scanf("%d%d", &n, &m);
        for (int i=0; i<n; ++i){
            unsigned long long x;
            cin >> x;
            bool suc = false;
            for (int j=0; j<=63; ++j){
                if (len[j] > x){
                    c[j]++; suc = true;
                    break;
                }
            }
            if (!suc) c[64]++;
        }
        bool suc = true;
        long long ans = 0;
        while(suc){
            int now = 0;
            for (int i=0; i<m; ++i){
                while(now <=64 && c[now] == 0) ++now;
                if (now == 65){
                    suc = false; break;
                }
                --c[now++];
            }
            if (suc) ++ans;
        }
        printf("Case #%d: %lld\n", kk, ans);
    }
    return 0;
}
