#include<bits/stdc++.h>
using namespace std;

const int N0 = 2e5+5, N1 = 1e6+5;
int n, m, k;
int tim[N1];
int a[N0];

int main(){
//    freopen("in.txt", "r", stdin);
    cin >> n >> m >> k;
    int maxt = 0;
    for (int i=0; i<n; ++i){
        scanf("%d", &a[i]);
        if (a[i] > maxt) maxt = a[i];
        ++tim[a[i]];
    }
    int now = 0, ans = 0;
    m = min(m, maxt);
    for (int i=1; i<=m; ++i)
        now += tim[i];
    if (now >= k){
        int ed = m;
        for(int i=1; i<=now-k+1; ++i){
            while(!tim[ed]) --ed;
            --tim[ed];++ans;
        }
        now = k-1;
    }
    for (int i=2; i<=maxt-m+1; ++i){
        now += tim[i+m-1]-tim[i-1];
        if (now >= k){
            int ed = i+m-1;
            for (int j=1; j<=now-k+1; ++j){
                while(!tim[ed]) --ed;
                --tim[ed];++ans;
            }
            now = k-1;
        }

    }
    cout << ans << endl;
    return 0;
}