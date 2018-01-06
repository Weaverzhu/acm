#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

const int N = 50001;
typedef long long LL;

int n, m;
int a[N];

struct Graph{
    int m;
    vector<int> g[N];
    void init(int m_){
        m = m_;
        for (int i=0; i<N; ++i)
            g[i].clear();
    }
    void add(int u, int v){
        g[u].push_back(v);
    }
} gra;

struct DecompositionTree{
    int tot, siz[N], son[N], fa[N];
    int deep[N], top[N], pos[N];
    void init(){
        tot = 0;
        memset(siz, 0, sizeof(siz));
        memset(son, -1, sizeof(son));
        memset(fa, -1, sizeof(fa));
    }
    void dfs1(int now, int pre, int d){
        fa[now] = pre;
        deep[now] = d;
        siz[now]++;
         for (int i=0; i<gra.g[now].size(); ++i){
            int v = gra.g[now][i];
            if (v != pre){
                dfs1(v, now, d+1);
                if (son[now] == -1 || siz[v] > siz[son[now]])
                    son[now] = v;
                siz[now] += siz[v];
            }
        }
    }
    void dfs2(int now, int sp){
        top[now] = sp;
        pos[now] = ++tot;
        if (son[now] == -1) return;
        dfs2(son[now], sp);
        for (int i=0; i<gra.g[now].size(); ++i){
            int v = gra.g[now][i];
            if (v != fa[now] && v != son[now]){
                dfs2(v, v);
            }
        }
    }
} d;

struct BinaryIndexTree{
    int dat[N];
    inline int lowbit(int i){return i&-i;};
    void init(){
        memset(dat, 0, sizeof(dat));
    }
    void add(int i, int x){
        for(; i<N; i+=lowbit(i)) dat[i] += x;
    }
    int sum(int i){
        int ret = 0;
        for(; i>0; i-=lowbit(i)) ret += dat[i];
        return ret;
    }
} bit;
void change(int s, int t, int x){
    int f1 = d.top[s], f2 = d.top[t];
    while(f1 != f2){
        if (d.deep[f1] < d.deep[f2])
            swap(f1, f2), swap(s, t);
        bit.add(d.pos[f1], x);
        bit.add(d.pos[s]+1, -x);
        s = d.fa[f1]; f1 = d.top[s];
    }
    if (d.deep[s] > d.deep[t]) swap(s, t);
    bit.add(d.pos[s], x); bit.add(d.pos[t]+1, -x);
}

int p;
int main(){
//    freopen("in.txt", "r", stdin);
//    printf("%d\n", sizeof(int)*N*9/1024);

    while(~scanf("%d%d%d", &n, &m, &p)){
        gra.init(m); bit.init(); d.init();
        for (int i=1; i<=n; ++i)
            scanf("%d", &a[i]);
        for (int i=1; i<=m; ++i){
            int u, v; scanf("%d%d", &u, &v);
            gra.add(u, v); gra.add(v, u);
        }
//        puts("fuck");
        d.dfs1(1, -1, 1); d.dfs2(1, 1);

        for (int i=1; i<=n; ++i)
            bit.add(d.pos[i], a[i]), bit.add(d.pos[i]+1, -a[i]);
//        puts("fuck");

        for (int kk=0; kk<p; ++kk){
            char op[5];
            scanf("%s", op);
            int l, r, x;
            if (op[0] == 'Q'){
                scanf("%d", &l);
                cout << bit.sum(d.pos[l]) << endl;
            }else{
                scanf("%d%d%d", &l, &r, &x);
                if (op[0] == 'D') x = -x;
                change(l, r, x);
            }
        }



    }


    return 0;
}
