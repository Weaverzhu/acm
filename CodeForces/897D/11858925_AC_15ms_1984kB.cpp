#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int ans[N];
int n, m, c, cnt;
void insert1(int x){
    for (int i=1; i<=n; ++i){
        if (!ans[i] || ans[i] > x){
            cout << i << endl;
            if (ans[i] == 0) ++cnt;
            ans[i] = x;
            return;
        }
    }
}
void insert2(int x){
    for (int i=n; i>=1; --i){
        if (!ans[i] || ans[i] < x) {
            cout << i << endl;
            if (ans[i] == 0) ++cnt;
            ans[i] = x;
            return;
        }
    }
}
int main(){
    scanf("%d%d%d", &n, &m, &c);
    int mid = c+1 >> 1;
    int x; cnt = 0;
    while(scanf("%d", &x) != -1){
        if (x > mid) insert2(x);
        else insert1(x);
        if (cnt == n) break;
    }
    return 0;
}
