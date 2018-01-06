#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;
const int MAXN = 5e4 + 8;

int x[MAXN], y[MAXN], z[MAXN], x2[MAXN], y2[MAXN], z2[MAXN];
map<iii, int> mpiii;
map<ii, int> mpii;
vector<int> sons[2*MAXN];
bool f[2*MAXN], vis[2*MAXN], ans1, ans2;

inline bool dfs(int u, int fa, int type){
    int sz = sons[u].size(), v, i;
    sz = unique(sons[u].begin(), sons[u].end()) - sons[u].begin();
    for(i = 0; i < sz; i++){
        v = sons[u][i];
        if(v == fa) continue;
        if(vis[v]){
            if(type == 1) ans1 = true;
            else ans2 = true;
            return true;
        }
        if(f[v]){
            continue;
        }

        vis[v] = true;
        f[v] = true;
        if(dfs(v, u, type)){
            return true;
        }
        else{
            vis[v] = false;
        }
    }
    return false;
}

int main()
{
    #ifdef LOCAL
    freopen("k.txt", "r", stdin);
    //freopen("k.out", "w", stdout);
    int T = 5;
    while(T--){
    #endif // LOCAL
    ios::sync_with_stdio(false); cin.tie(0);

    int n, i, u, v, w, totiii = 1, totii = 1;
    ans1 = false, ans2 = false;
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> x[i] >> y[i] >> z[i] >> x2[i] >> y2[i] >> z2[i];
    }
    for(i = 1; i <= n; i++){
        if(mpiii.find(iii(x[i], ii(y[i], z[i]))) == mpiii.end()){
            mpiii[iii(x[i], ii(y[i], z[i]))] = totiii;
            totiii++;
        }
        if(mpiii.find(iii(x2[i], ii(y2[i], z2[i]))) == mpiii.end()){
            mpiii[iii(x2[i], ii(y2[i], z2[i]))] = totiii;
            totiii++;
        }
        u = mpiii[iii(x[i], ii(y[i], z[i]))];
        v = mpiii[iii(x2[i], ii(y2[i], z2[i]))];
        if(u != v){
            sons[u].push_back(v);
            sons[v].push_back(u);
        }
        //cout << u << " " << v << endl;
    }

    memset(f, false, sizeof f);
    memset(vis, false, sizeof vis);
    for(i = 1; i < totiii; i++){
        if(ans1) break;
        if(f[i]) continue;
        dfs(i, -1, 1);
    }

    for(i = 1; i < totiii; i++){
        sons[i].clear();
    }
    mpiii.clear();


    for(i = 1; i <= n; i++){
        if(mpii.find(ii(x[i], y[i])) == mpii.end()){
            mpii[ii(x[i], y[i])] = totii;
            totii++;
        }
        if(mpii.find(ii(x2[i], y2[i])) == mpii.end()){
            mpii[ii(x2[i], y2[i])] = totii;
            totii++;
        }
        u = mpii[ii(x[i], y[i])];
        v = mpii[ii(x2[i], y2[i])];
        if(u != v){
            sons[u].push_back(v);
            sons[v].push_back(u);
        }
    }

    memset(f, false, sizeof f);
    memset(vis, false, sizeof vis);
    for(i = 1; i < totii; i++){
        if(ans2) break;
        if(f[i]) continue;
        dfs(i, -1, 2);
    }

    if(ans1){
        cout << "True closed chains" << endl;
    }
    else{
        cout << "No true closed chains" << endl;
    }

    if(ans2){
        cout << "Floor closed chains" << endl;
    }
    else{
        cout << "No floor closed chains" << endl;
    }






    #ifdef LOCAL
    for(i = 1; i < totii; i++){
        sons[i].clear();
    }
    mpii.clear();
    cout << endl;
    }
    #endif // LOCAL
    return 0;
}