#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int mod = 1000000000 + 7;
const int INF = 1000000000;
const int maxn = 100000 + 10;
int T,n,m,maxv[maxn<<2],setv[maxn<<2],ans;
struct node {
    int l, r, h;
}a[maxn];
void PushUp(int o) {
    maxv[o] = max(maxv[o<<1], maxv[o<<1|1]);
}
void build(int l, int r, int o) {
    int m = (l + r) >> 1;
    maxv[o] = 0;
    setv[o] = 0;
    if(l == r) return ;
    build(l, m, o<<1);
    build(m+1, r, o<<1|1);
}
void pushdown(int l, int r, int o) {
    if(setv[o]) {
        setv[o<<1] = setv[o<<1|1] = setv[o];
        maxv[o<<1] = maxv[o<<1|1] = setv[o];
        setv[o] = 0;
    }
}
void update(int L, int R, int h, int l, int r, int o) {
    int m = (l + r) >> 1;
    if(setv[o] && maxv[o] > h) return ;
    if(L <= l && r <= R) {
        if(maxv[o] <= h) {
            maxv[o] = h;
            setv[o] = h;
            ans += r - l + 1;
            return ;
        }
    }
    if(l == r) return ;
    pushdown(l, r, o);
    if(L <= m) update(L, R, h, l, m, o<<1);
    if(m < R) update(L, R, h, m+1, r, o<<1|1);
    PushUp(o);
}
int main() {
    while(~scanf("%d",&T) && T) {
        while(T--) {
            scanf("%d",&n);
            int m = 0;
            for(int i=0;i<n;i++) {
                scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].h);
                m = max(m, a[i].r);
            }
            build(1, m, 1);
            ans = 0;
            for(int i=0;i<n;i++) {
                update(a[i].l, a[i].r-1, a[i].h, 1, m, 1);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}



