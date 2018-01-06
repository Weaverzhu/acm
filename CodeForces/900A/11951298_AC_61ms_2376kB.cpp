#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int x[N];
int main(){
    int s1 = 0, s2 = 0;
    int n;
    scanf("%d", &n);
    int t1, t2;
    int cnt0=0, cnt1=0;
    for (int i=1; i<=n; ++i){
        scanf("%d%d", &t1, &t2);
        if (t1>0) ++cnt1;
        else ++cnt0;
    }
    if (cnt1<=1 || cnt0 <=1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}