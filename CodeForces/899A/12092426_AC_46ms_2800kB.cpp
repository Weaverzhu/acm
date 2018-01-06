#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
int n;
int cnt[2];
int main(){
    scanf("%d", &n);

    for (int i=0; i<n; ++i){
        scanf("%d", &a[i]);
        if (a[i] == 1) ++cnt[0];
        else ++cnt[1];
    }
    int ans = min(cnt[0], cnt[1]);
    cnt[0] = cnt[0]>cnt[1]? cnt[0]-cnt[1]:0;
    ans += cnt[0]/3;
    cout << ans << endl;


    return 0;
}