#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 5005;
int a[N];
bool vis[N];
int main(){
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
        scanf("%d", &a[i]);
    sort(a, a+n);
    int remain = n, ans = 0;
    while(remain){
        int now = 0; ++ans;int tmp = -2147483648;
        while(1){
            while(now<n && vis[now]) ++now;
            if (now == n) break;
            if (a[now] > tmp){
                tmp = a[now];
                vis[now] = true; --remain;
            }else ++now;
        }
    }
    cout << ans << endl;

    return 0;
}
