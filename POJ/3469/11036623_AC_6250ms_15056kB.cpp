#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define maxn 23500
#define maxe 1000000
#define inf 1100000000
using namespace std;
 
struct Edge
{
    int u, v, cap;
    int nxt;
}edge[maxe];
 
int head[maxn];
int n, m;
 
struct Dicnic
{
    int level[maxn];
    int iter[maxn];
    int add;
    void init(){
        add = 0; memset(head, -1, sizeof(head));
        memset(iter, -1, sizeof(iter));
    }
    void insert(int u, int v, int c){
        edge[add].u = u; edge[add].v = v; edge[add].cap = c;
        edge[add].nxt = head[u]; head[u] = add++;
        edge[add].u = v; edge[add].v = u; edge[add].cap = 0;
        edge[add].nxt = head[v]; head[v] = add++;
    }
    void bfs(int s){
        memset(level, -1, sizeof(level));
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()){
            int v = que.front(); que.pop();
            for (int i = head[v]; i != -1; i = edge[i].nxt){
                Edge &e = edge[i];
                if (e.cap > 0 && level[e.v] < 0){
                    level[e.v] = level[v] + 1;
                    que.push(e.v);
                }
            }
        }
    }
 
    int dfs(int v, int t, int f){
        if (v == t) return f;
        for (int &i = iter[v]; i != -1; i = edge[i].nxt){
            Edge &e = edge[i]; Edge &reve = edge[i ^ 1];
            if (e.cap > 0 && level[v] < level[e.v]){
                int d = dfs(e.v, t, min(f, e.cap));
                if (d>0){
                    e.cap -= d; reve.cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
 
    int max_flow(int s, int t){
        int flow = 0;
        for (;;){
            bfs(s);
            if (level[t] < 0) return flow;
            memcpy(iter, head, sizeof(iter));
            int f;
            while ((f = dfs(s, t, inf))>0){
                flow += f;
            }
        }
    }
}net;
 
int a[maxn], b[maxn];
 
int main()
{
    while (cin >> n >> m){
        net.init();
        int s = 0, t = n + 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i); scanf("%d", b + i);
            net.insert(i, t, a[i]);
            net.insert(s, i, b[i]);
        }
        int ui, vi, wi;
        for (int i = 0; i < m; i++){
            scanf("%d%d%d", &ui, &vi, &wi);
            net.insert(ui, vi, wi);
            net.insert(vi, ui, wi);
        }
        printf("%d\n", net.max_flow(s,t));
    }
    return 0;
}