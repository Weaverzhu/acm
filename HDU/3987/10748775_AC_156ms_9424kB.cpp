#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <queue>  
#define MAXN 1010  
#define MAXM 400000+10  
#define INF 0x3f3f3f3f  
using namespace std;  
struct Edge  
{  
    int from, to, cap, flow, next;  
};  
Edge edge[MAXM];  
int head[MAXN], cur[MAXN], edgenum;  
int dist[MAXN];  
bool vis[MAXN];  
int N, M;  
void init()  
{  
    edgenum = 0;  
    memset(head, -1, sizeof(head));  
}  
void addEdge(int u, int v, int w)  
{  
    Edge E1 = {u, v, w, 0, head[u]};  
    edge[edgenum] = E1;  
    head[u] = edgenum++;  
    Edge E2 = {v, u, 0, 0, head[v]};  
    edge[edgenum] = E2;  
    head[v] = edgenum++;  
}  
void getMap()  
{  
    int a, b, c, d;  
    while(M--)  
    {  
        scanf("%d%d%d%d", &a, &b, &c, &d);  
        a++, b++;  
        addEdge(a, b, c);  
        if(d)  
            addEdge(b, a, c);  
    }  
}  
bool BFS(int s, int t)  
{  
    queue<int> Q;  
    memset(dist, -1, sizeof(dist));  
    memset(vis, false, sizeof(vis));  
    dist[s] = 0;  
    vis[s] = true;  
    Q.push(s);  
    while(!Q.empty())  
    {  
        int u = Q.front();  
        Q.pop();  
        for(int i = head[u]; i != -1; i = edge[i].next)  
        {  
            Edge E = edge[i];  
            if(!vis[E.to] && E.cap > E.flow)  
            {  
                dist[E.to] = dist[u] + 1;  
                if(E.to == t) return true;  
                vis[E.to] = true;  
                Q.push(E.to);  
            }  
        }  
    }  
    return false;  
}  
int DFS(int x, int a, int t)  
{  
    if(x == t || a == 0) return a;  
    int flow = 0, f;  
    for(int &i = cur[x]; i != -1; i = edge[i].next)  
    {  
        Edge &E = edge[i];  
        if(dist[E.to] == dist[x] + 1 && (f = DFS(E.to, min(a, E.cap - E.flow), t)) > 0)  
        {  
            edge[i].flow += f;  
            edge[i^1].flow -= f;  
            flow += f;  
            a -= f;  
            if(a == 0) break;  
        }  
    }  
    return flow;  
}  
int Maxflow(int s, int t)  
{  
    int flow = 0;  
    while(BFS(s, t))  
    {  
        memcpy(cur, head, sizeof(head));  
        flow += DFS(s, INF, t);  
    }  
    return flow;  
}  
int k = 1;  
void solve()  
{  
    Maxflow(1, N);  
    //对残量网络 进行处理  
    for(int i = 0; i < edgenum; i+=2)  
    {  
        Edge E = edge[i];  
        if(E.cap == E.flow)//满流的边 改变边权->1  
        {  
            edge[i].cap = 1;  
            edge[i].flow = 0;  
        }  
        else  
        {  
            edge[i].cap = INF;  
            edge[i].flow = 0;  
        }  
        edge[i^1].cap = edge[i^1].flow = 0;//处理反向边  
    }  
    printf("Case %d: %d\n", k++, Maxflow(1, N));//再求一次最小割就是答案  
}  
int main()  
{  
    int t;  
    scanf("%d", &t);  
    while(t--)  
    {  
        scanf("%d%d", &N, &M);  
        init();  
        getMap();  
        solve();  
    }  
    return 0;  
}  
