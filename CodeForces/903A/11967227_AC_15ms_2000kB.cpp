#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d", &n);
    for (int kk=1; kk<=n; ++kk){
        int x;
        scanf("%d", &x);
        bool suc = false;
        for (int i=0; i<=34; ++i){
            for (int j=0; j<=15; ++j){
                if (i*3+j*7 == x){
                    suc = true;
                    break;
                }
            }
            if (suc) break;
        }
        if (suc) puts("YES");
        else puts("NO");
    }
return 0;
}
