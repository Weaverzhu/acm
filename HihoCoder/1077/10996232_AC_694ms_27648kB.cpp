#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<cstdlib>
#include<vector>
using namespace std;
#define cl(a,b) memset(a,b,sizeof(a))
#define LL long long
#define pb push_back
#define gcd __gcd

#define For(i,j,k) for(int i=(j);i<k;i++)
#define lowbit(i) (i&(-i))
#define _(x) printf("%d\n",x)

const int maxn = 1e6+10;
const int inf  = 1 << 28;

int a[maxn<<2];

void push_up(int rt){
    a[rt]=min(a[rt<<1],a[rt<<1|1]);
}
void build(int rt,int l,int r){
    if(l==r){
        scanf("%d",&a[rt]);
        return ;
    }
    int mid = l+r>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    push_up(rt);
}

void updata(int rt,int l,int r,int i,int v){
    if(l==r){
        a[rt] = v;return ;
    }
    int mid = l+r>>1;
    if(i<=mid)updata(rt<<1,l,mid,i,v);
    else updata(rt<<1|1,mid+1,r,i,v);
    push_up(rt);
}

int query(int rt,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        return a[rt];
    }
    int mid = l+r>>1;
    int ans = inf;
    if(x<=mid)ans=min(ans,query(rt<<1,l,mid,x,y));
    if(y>mid) ans=min(ans,query(rt<<1|1,mid+1,r,x,y));
    return ans;
}



int main(){
    int n;scanf("%d",&n);
    build(1,1,n);
    int m;scanf("%d",&m);
    while(m--){
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if(t==0){
            printf("%d\n",query(1,1,n,x,y));
        }
        else
            updata(1,1,n,x,y);
    }
    return 0;
}
