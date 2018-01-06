#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        for(int i = 0;i<k;i++){
            scanf("%d",&a[i]);
        }
        int sum1 = n;
        int sum2 = 2*n;
        for(int i = 0;i<k;i++){
            int d = min(sum1,a[i]/4);
            sum1 -= d;
            a[i] -= d*4;
        }
        sum2+=sum1;
        for(int i = 0;i<k;i++){
            int d = min(sum2,a[i]/2);
            sum2 -= d;
            a[i] -= d*2;
        }
        int tmp  = sum2+sum1;
        for(int i = 0;i<k;i++){
            tmp -= a[i];
        }
        if(tmp>=0) puts("YES");
        else puts("NO");
    }
}
