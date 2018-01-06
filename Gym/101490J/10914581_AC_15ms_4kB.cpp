#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 5;

int n;
int ans;
int sx[MAXN], sy[MAXN], tx[MAXN], ty[MAXN];

bool can (int i, int j, int midnum) {
    if (abs(sx[i]-tx[j]) + abs(sy[i]-ty[j]) <= midnum) return true;
    return false;
}

int V;
const int MAX_V = 300;
vector<int> G[MAX_V];
int _match[MAX_V];
bool used[MAX_V];

void add_edge (int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v) {
    used[v] = true;
//    cout<<v<<endl;
    for (int i=0; i<G[v].size(); i++) {
        int u = G[v][i], w = _match[u];
        if (w<0 || !used[w] &&dfs(w)) {
            _match[v] = u;
            _match[u] = v;
            return true;
        }
    }
    return false;
}

int bipartite_matching () {
    int res = 0;
    memset(_match, -1, sizeof(_match));
    for (int v=0; v<V; v++) {
        if (_match[v] < 0) {
            memset(used, 0, sizeof(used));
            if (dfs(v)) {
                res++;
            }
        }
    }
    return res;
}


bool solve (int midnum) {
    V = n;
    int N = n, K = n;
    for (int i=0; i<N; i++) {
        for (int j=0; j<K; j++) {
            if (can(i, j, midnum)) {
                add_edge(i, N+j );
            }
        }
    }
    if (bipartite_matching() == n) return true;
    return false;
}


int main()
{
//    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++) {
        scanf("%d %d", &sx[i], &sy[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%d %d", &tx[i], &ty[i]);
    }
    int minnum =0, maxnum = 1e8 * 4;
    ans = maxnum;
    while (minnum < maxnum-1) {
        for (int i=0; i<2*n; i++)G[i].clear();
        int midnum = (minnum + maxnum) / 2;
        if (solve(midnum)) {
            maxnum = midnum;
            ans = min(ans, midnum);
        }
            else {
                minnum = midnum+1;
            }
    }
    cout << ans << endl;


    return 0;
}
