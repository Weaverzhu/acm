#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
typedef long long LL;
LL a[N];
LL na[N];
struct node{
LL v, cost;
} nb[N];
int cnta, cntb;
int n;
bool cmp(LL a, LL b){
    return a > b;
}
bool cmp1(const node &a, const node &b){
    return a.cost < b.cost;
}
bool issquare(LL x){
    LL i = floor(sqrt(x));
    if (i*i == x) return true;
    else return false;
}
LL calc(LL x){
    LL tmp = floor(sqrt(x));
    return min(x-tmp*tmp, (tmp+1)*(tmp+1)-x);
}
int main(){
//    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        scanf("%lld", &a[i]);
        if (issquare(a[i]))
            na[cnta++] = a[i];
        else {
            nb[cntb].v = a[i];
            nb[cntb++].cost = 0;
        }
    }
    int remain = abs(cnta-cntb)/2;
    sort(na, na+cnta, cmp);
    for (int i=0; i<cntb; ++i)
        nb[i].cost = calc(nb[i].v);
    sort(nb, nb+cntb, cmp1);
    LL ans = 0;
    if (cnta > cntb){
        for (int i=0; i<remain; ++i){
            if (na[i] > 0) ans++;
            else ans+=2;
        }
    }else{
        for (int i=0; i<remain; ++i)
            ans += nb[i].cost;
    }
    cout << ans << endl;
    return 0;
}