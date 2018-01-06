#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t[10000];
bool suc[10000];
int n, T;
int main(){
//    int t;
    scanf("%d", &T);
    for (int kk=1; kk<=T; ++kk){
        scanf("%d", &n);
        for (int i=1; i<=n; ++i){
            scanf("%d", &t[i]);
        }
        int remain = n, ans = 0;
        sort(t+1, t+n+1);
        while(remain){
            if (remain == 1){
                ans += t[1];
                remain = 0;
            }else if (remain == 2){
                ans += t[2];
                remain = 0;
            }else if (remain == 3){
                ans += t[1] + t[2] + t[3];
                remain = 0;
            }else{
                int t1 = t[1], t2 = t[2], t3 = t[remain-1], t4 = t[remain];
                if (t1+t3 > 2*t2){
                    ans += t2+t1+t4+t2;
                }else ans += 2*t1+t3+t4;
                remain -= 2;
            }


        }
        cout << ans << endl;
    }
    return 0;
}
