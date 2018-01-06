#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int n, a[N], b[N], absGt, absLt, eq, gcd;
int sgn(double x) { 
    if(abs(x) < 1e-8)   return 0;
    return x > 0 ? 1 : -1;
}
struct Node {
    double l, r;    int da, db;
} p;
vector<Node> v;
bool cmp(Node a, Node b) {
    if(a.l == b.l)  return a.r < b.r;
    return a.l < b.l;
}
bool operator<(Node a, Node b) {
    return a.r > b.r;
}
int solveBst() {
    v.clear();
    eq = absGt = absLt = 0;
    for(int i=2;i<=n;i++)
    {
        if(a[i] == a[1] && b[i] == b[1])    eq++;
        else if(a[i] >= a[1] && b[i] >= b[1])   absGt++;
        else if(a[i] <= a[1] && b[i] <= b[1])   absLt++;
        else {
            p.da = a[1] - a[i]; p.db = b[i] - b[1];
            if(a[i] > a[1])
                p.l = 0,    p.r = p.db * 1.0 / p.da;
            else
                p.l = p.db *1.0 / p.da, p.r = 1000;
            v.push_back(p);
        }
    }

    int bst = 0;
    sort(v.begin(), v.end(), cmp);

    priority_queue<Node> que;
    for(int i=0;i<v.size();i++)
    {
        while(!que.empty() && sgn(que.top().r - v[i].l) == -1)  que.pop();
        que.push(v[i]);
        bst = max(bst, (int)que.size());        
    }
    return n - (bst + eq + absLt);
}
int solveWst() {
    v.clear();
    absGt = absLt = eq = 0;
    for(int i=2;i<=n;i++)
    {
        if(a[i] == a[1] && b[i] == b[1])    eq++;
        else if(a[i] >= a[1] && b[i] >= b[1])   absGt++;
        else if(a[i] <= a[1] && b[i] <= b[1])   absLt++;
        else {
            p.da = a[1] - a[i]; p.db = b[i] - b[1];
            if(a[i] < a[1])
                p.l = 0,    p.r = p.db * 1.0 / p.da;
            else
                p.l = p.db * 1.0 / p.da,    p.r = 1000;
            v.push_back(p);
        }
    }

    int wst = 0;
    sort(v.begin(), v.end(), cmp);
    priority_queue<Node> que;
    for(int i=0;i<v.size();i++)
    {
        while(!que.empty() && sgn(que.top().r - v[i].l) == -1)  que.pop();
        que.push(v[i]);
        wst = max(wst, (int) que.size());       
    }
    return wst + eq + absGt + 1;
}
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%d %d", &a[i], &b[i]);

    int gt, lt, bst = n, wst = 1;
    gt = lt = eq = 0;
    for(int i=2;i<=n;i++)
    {
        if(a[i] > a[1]) gt++;
        else if(a[i] == a[1])   eq++;
        else    lt++;
    }
    bst = min(bst, gt+1);   wst = max(wst, gt+eq+1);
    gt = lt = eq = 0;
    for(int i=2;i<=n;i++)
    {
        if(b[i] > b[1]) gt++;
        else if(b[i] == b[1])   eq++;
        else    lt++;
    }
    bst = min(bst, gt+1);   wst = max(wst, gt+eq+1);

    bst = min(bst, solveBst());
    wst = max(wst, solveWst());
    printf("%d %d\n", bst, wst);
}