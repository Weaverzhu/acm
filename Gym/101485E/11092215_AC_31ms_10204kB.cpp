#include<bits/stdc++.h>
#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define sf scanf
#define pf printf
#define mem(a,b) memset(a,b,sizeof(a));
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
#define ULL unsigned long long
#define LL   long long
#define inf 0x3f3f3f3f
#define md ((ll+rr)>>1)
#define ls (i<<1)
#define rs (ls|1)
#define eps 1e-5
#define ree freopen("in.txt","r",stdin);
#define bug pf("----------------");
#define N 10030
#define M 1000020
#define INF 1e9
int n;

int a[N],b[N];
LL c[N];
LL san[N];
int fst[N],nxt[M],e,vv[M];
int match[N];
int cnt;
int vis[N];
void add(int u,int v){
    vv[e]=v;nxt[e]=fst[u];fst[u]=e++;
}
void init(){
    mem(fst,-1);e=0;
}
bool dfs(int x){
    for(int i=fst[x];~i;i=nxt[i]){
        int v=vv[i];
        if(vis[v])continue;
        vis[v]=1;
        if(match[v]==-1||dfs(match[v])){
            match[v]=x;return 1;
        }
    }
    return 0;
}
int haxi(LL x){
    return lower_bound(san+1,san+1+cnt,x)-san;
}
int main(){
//    ree
    init();
    sf("%d",&n);
    cnt=0;
    rep(i,1,n){
        sf("%d%d",&a[i],&b[i]);
        san[++cnt]=a[i]-b[i];
        san[++cnt]=a[i]+b[i];
        san[++cnt]=1LL*a[i]*b[i];
    }
    sort(san+1,san+1+cnt);
    cnt=unique(san+1,san+1+cnt)-san-1;
    for(int i=1;i<=n;++i){
        add(i,haxi(a[i]+b[i]));
        add(i,haxi(a[i]-b[i]));
        add(i,haxi(1LL*a[i]*b[i]));
    }
    int ans=0;
    mem(match,-1);
    for(int i=1;i<=n;++i){
        mem(vis,0);
        if(dfs(i)){
            ++ans;
        }
    }
    if(ans==n){
        for(int i=1;i<=cnt;++i){
            if(match[i]==-1)continue;
            c[match[i]]=i;
        }
        for(int i=1;i<=n;++i){
            LL u=san[c[i]];
            if(a[i]+b[i]==u)
                pf("%d + %d = %lld\n",a[i],b[i],u);
            else if(a[i]-b[i]==u)
                pf("%d - %d = %lld\n",a[i],b[i],u);
            else if(1LL*a[i]*b[i]==u)
                pf("%d * %d = %lld\n",a[i],b[i],u);
        }
    }
    else puts("impossible");
}