#include<bits/stdc++.h>
using namespace std;
int h1, a1, c1, h2, a2;
int ans[100000], asz = 0;
int main(){
    while(cin >> h1 >> a1 >> c1 >> h2 >> a2){
        asz = 0;
        while(1){
            if (a1 >= h2){
                ans[asz++] = 0;
                break;
            }
            if (h1 <= a2){
                ans[asz++] = 1;
                h1 += c1;
            }else{
                ans[asz++] = 0;
                h2 -= a1;
            }
            if (h2 <= 0){
                break;
            }else{
                h1 -= a2;
            }
//            puts("fuck");
        }
        printf("%d\n", asz);
        for (int i=0; i<asz; ++i){
            if (ans[i] == 0){
                printf("STRIKE\n");
            }else if (ans[i] == 1){
                printf("HEAL\n");
            }
        }
    }

    return 0;
}
