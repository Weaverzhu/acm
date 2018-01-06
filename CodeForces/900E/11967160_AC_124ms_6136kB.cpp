#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
char s[N], t[N];
int num[N];
int mx[N];
int n, m;
struct node{
    int x, c;
    void init(){
        x = c = 0;
    }
    node add(int a, int b){
        node now;
        now.x = x+a;
        now.c = c+b;
        return now;
    }
    void print(){
        cout << "print" << x << ' ' << c << endl;
    }
    bool operator < (const node &p)const{
        if (x == p.x) return c > p.c;
        return x < p.x;
    }
};
node sum[N << 2];
void update(int x, node &tmp, int l, int r, int rt){
    if (l == r){
        sum[rt] = tmp;
        return;
    }
    int mid = l+r >> 1;
    if (mid >= x) update(x, tmp, l, mid, rt << 1);
    else update(x, tmp, mid+1, r, rt<<1|1);
    sum[rt] = max(sum[rt<<1], sum[rt<<1|1]);
}
node query(int L, int R, int l, int r, int rt){
    if (L <= l && R >= r){
        return sum[rt];
    }
    int mid = l+r >> 1;
    node tmp;
    tmp.init();
    if (mid >= L) tmp = query(L, R, l, mid, rt<<1);
    if (mid < R) tmp = max(tmp, query(L, R, mid+1, r, rt<<1|1));
    return tmp;
}
int main(){
    scanf("%d", &n);
    scanf("%s", s+1);
    scanf("%d", &m);
    for (int i=1; i<=n; ++i){
        if (s[i] == '?') num[i] = 1;
        if (i) num[i] += num[i-1];
    }
    for (int i=n; i>=1; --i){
        if (s[i] == '?' || s[i] == 'a'){
            if (i<n && (s[i+1] == '?' || s[i+1] == 'b')){
                mx[i] = mx[i+2] + 2;
            }
            else mx[i] = 1;
        }
        else mx[i] = 0;
        node now = query(i, n, 1, n, 1);

        if (mx[i] >= m){
            node ret;
            ret.init();
            if (i+m <= n) ret = query(i+m, n, 1, n, 1);
            ret = ret.add(1, num[i+m-1]-num[i-1]);
            now = max(now, ret);
        }
        update(i, now, 1, n, 1);
    }
    node ans = query(1, n, 1, n, 1);
    cout << ans.c << endl;
    return 0;
}
