#include<stdio.h>  
#include<vector>  
#include<string.h>  
#include<algorithm>  
using namespace std;  
#define LL long long  
vector<LL> G[100005];  
typedef struct  
{  
    LL id;  
    LL x, y;  
    LL l, r;  
}Quer;  
Quer s[100005], cnt[100005];  
LL tre[445005];  
LL n, val[100005], son[100005], fa[100005], siz[100005], dep[100005];  
LL k, top[100005], rak[100005], id[100005], anl[100005], anr[100005];  
bool comp1(Quer a, Quer b)  
{  
    if(a.l<b.l)  
        return 1;  
    return 0;  
}  
bool compr(Quer a, Quer b)  
{  
    if(a.r<b.r)  
        return 1;  
    return 0;  
}  
void Sechs(LL u, LL p)  
{  
    LL v, i;  
    fa[u] = p;  
    dep[u] = dep[p]+1;  
    for(i=0;i<G[u].size();i++)  
    {  
        v = G[u][i];  
        if(v==p)  
            continue;  
        Sechs(v, u);  
        siz[u] += siz[v]+1;  
        if(son[u]==0 || siz[v]>siz[son[u]])  
            son[u] = v;  
    }  
}  
void Sechr(LL u, LL p)  
{  
    LL v, i;  
    top[u] = p;  
    rak[u] = ++k, id[k] = u;  
    if(son[u]==0)  
        return;  
    Sechr(son[u], p);  
    for(i=0;i<G[u].size();i++)  
    {  
        v = G[u][i];  
        if(v==son[u] || v==fa[u])  
            continue;  
        Sechr(v, v);  
    }  
}  
  
void Update(LL l, LL r, LL x, LL a, LL b)  
{  
    LL m;  
    if(l==r)  
    {  
        tre[x] += b;  
        return;  
    }  
    m = (l+r)/2;  
    if(a<=m)  
        Update(l, m, x*2, a, b);  
    else  
        Update(m+1, r, x*2+1, a, b);  
    tre[x] = tre[x*2]+tre[x*2+1];  
}  
LL Query(LL l, LL r, LL x, LL a, LL b)  
{  
    LL m, sum = 0;  
    if(l>=a && r<=b)  
        return tre[x];  
    m = (l+r)/2;  
    if(a<=m)  
        sum += Query(l, m, x*2, a, b);  
    if(b>=m+1)  
        sum += Query(m+1, r, x*2+1, a, b);  
    return sum;  
}  
LL TreQuery(LL x, LL y)  
{  
    LL sum, p1, p2;  
    p1 = top[x], p2 = top[y], sum = 0;  
    while(p1!=p2)  
    {  
        if(dep[p1]<dep[p2])  
            swap(p1, p2), swap(x, y);  
        sum += Query(1, n, 1, rak[p1], rak[x]);  
        x = fa[p1], p1 = top[x];  
    }  
    if(dep[x]>dep[y])  
        swap(x, y);  
    sum += Query(1, n, 1, rak[x], rak[y]);  
    return sum;  
}  
  
int main(void)  
{  
    LL i, j, x, y, q;  
    while(scanf("%lld%lld", &n, &q)!=EOF)  
    {  
        for(i=1;i<=n;i++)  
            G[i].clear();  
        for(i=1;i<=n;i++)  
        {  
            scanf("%lld", &val[i]);  
            cnt[i].id = i;  
            cnt[i].r = val[i];  
        }  
        sort(cnt+1, cnt+n+1, compr);  
        for(i=1;i<=n-1;i++)  
        {  
            scanf("%lld%lld", &x, &y);  
            G[x].push_back(y);  
            G[y].push_back(x);  
        }  
        memset(siz, 0, sizeof(siz));  
        memset(son, 0, sizeof(son));  
        k = 0;  
        Sechs(1, 0);  
        Sechr(1, 1);  
        for(i=1;i<=q;i++)  
        {  
            scanf("%lld%lld%lld%lld", &s[i].x, &s[i].y, &s[i].l, &s[i].r);  
            s[i].id = i;  
        }  
          
        sort(s+1, s+q+1, comp1);  
        memset(tre, 0, sizeof(tre));  
        j = 1;  
        for(i=1;i<=q;i++)  
        {  
            while(cnt[j].r<s[i].l && j<=n)  
            {  
                Update(1, n, 1, rak[cnt[j].id], cnt[j].r);  
                j += 1;  
            }  
            anl[s[i].id] = TreQuery(s[i].x, s[i].y);  
        }  
  
        sort(s+1, s+q+1, compr);  
        memset(tre, 0, sizeof(tre));  
        j = 1;  
        for(i=1;i<=q;i++)  
        {  
            while(cnt[j].r<=s[i].r && j<=n)  
            {  
                Update(1, n, 1, rak[cnt[j].id], cnt[j].r);  
                j += 1;  
            }  
            anr[s[i].id] = TreQuery(s[i].x, s[i].y);  
        }  
  
        printf("%lld", anr[1]-anl[1]);  
        for(i=2;i<=q;i++)  
            printf(" %lld", anr[i]-anl[i]);  
        printf("\n");  
    }  
    return 0;  
}  