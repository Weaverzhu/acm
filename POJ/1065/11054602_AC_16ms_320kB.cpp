#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 5000+10;

struct node
{
    int x, y;
};
node a[maxn];
bool f[maxn];
int tx, ty, tn;

bool cmp(node a, node b)
{
	return a.x < b.x ? true : a.x<=b.x && a.y<=b.y;
//    if (a.x < b.x) return true;
//    if (a.x == b.x) return a.y < b.y;
}


void solve()
{
    memset(f, 0, sizeof(f));

    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
    sort(a+1, a+n+1, cmp);
//    for (int i=1; i<=n; ++i)
//    {
//    	cout << a[i].x << " " << a[i].y << endl;
//	}
    int cnt = 0, ans = 0;
    while(cnt < n)
    {
        ++ans;
        int st = -1;
        for (int i=1; i<=n; ++i)
            if (!f[i])
            {
            	tx = a[i].x; ty = a[i].y;
//            	cout << tx << " " << ty << endl;
				cnt++;
                f[i] = true, st = i; break;
                
                
            }
        if (st == -1) break;
        int tx = a[st].x, ty = a[st].y;
        for (int i=st+1; i<=n; ++i)
            if (!f[i] && a[i].x>=tx && a[i].y >=ty)
            {
                tx = a[i].x; ty = a[i].y;
                f[i] = true; cnt++;
            }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) solve();

    return 0;
}
