#include<bits/stdc++.h>
using namespace std;

const int N = 105;
struct node{
    int a[3];
} dat[N];
struct node2{
    int v, p;
    bool operator < (const node2 &b) const {
        return v < b.v;
    }
} x[3];
struct P{
    int x, y;
    bool operator < (const P &b) const {
        if (x != b.x) return x < b.x;
        return y < b.y;
    }
};

P np(int a, int b){
    P newp = (P){a, b};
    return newp;
}

int mp[100];
int a, b, c, sz;

int main(){
    // freopen("in.txt", "r", stdin);

    mp[1] = 0;
    mp[2] = 1;
    mp[10] = 0;
    mp[12] = 2;
    mp[21] = 2;
    mp[20] = 1;

    for (int i=0; i<3; ++i){
        scanf("%d", &x[i].v);
        x[i].p = i;
    }

    sort(x, x+3);
    // puts("fuck");

    if (x[0].v*x[1].v < x[2].v){
        printf("-1\n");
        return 0;
    }
    // puts("fuck");

    int now = -100;
    while(x[0].v+x[1].v-1 > x[2].v){
        dat[sz++] = (node){{now, now, now}};

        now++; 
        --x[0].v; --x[1].v; --x[2].v;
    }

    dat[sz++] = (node){{0, 0, 0}};
    // puts("fuck");

    for (int i=1; i<x[0].v; ++i){
        int key = x[0].p*10+x[2].p;
        int dim = mp[key];
        dat[sz] = (node){{0, 0, 0}};
        dat[sz].a[dim] = i;
        sz++;
    }
    // puts("fuck");
    for (int i=1; i<x[1].v; ++i){
        int key = x[1].p*10 + x[2].p;
        int dim = mp[key];
        dat[sz] = (node){{0, 0, 0}};
        dat[sz].a[dim] = i;
        sz++;
    }
    int cnt = x[0].v+x[1].v-1;
    for (int i=1; i<x[0].v && cnt < x[2].v; ++i)
        for (int j=1; j<x[1].v && cnt < x[2].v; ++j){
            dat[sz] = (node){{0, 0, 0}};
            
            int nx = mp[x[0].p*10 + x[2].p], ny = mp[x[1].p*10 + x[2].p];
            dat[sz].a[nx] = i; dat[sz].a[ny] = j;
            sz++;

            ++cnt;
        }
    printf("%d\n", sz);
    for (int i=0; i<sz; ++i)
        printf("%d %d %d\n", dat[i].a[0], dat[i].a[1], dat[i].a[2]);
    return 0;
}