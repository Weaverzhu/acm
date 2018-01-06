#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

const int N = 5005;
const double pi = acos(-1.0);

void scanf_(int &num)
{
    char in;
    bool neg=false;
    while(((in=getchar()) > '9' || in<'0') && in!='-') ;
    if(in=='-')
    {
        neg=true;
        while((in=getchar()) >'9' || in<'0');
    }
    num=in-'0';
    while(in=getchar(),in>='0'&&in<='9')
        num*=10,num+=in-'0';
    if(neg)
        num=0-num;
}

int n, k;
struct Point {
	int x, y;
	double r, p;
	int num;
}p[N], save[N];

bool cmpr(Point a, Point b) {
	return a.r < b.r;
}

bool cmpp(Point a, Point b) {
	return a.p < b.p;
}

double cal(Point a, Point b) {
	return a.p - b.p;
}

double solve() {
	if(k == 0) return 0;
	int i, j;
	sort(p, p + n, cmpr);
	for (i = 1; i < n; i++)
		p[i].num += p[i - 1].num;
	double ans = INF;
	sort(p, p + n, cmpp);
	set<double> vis;
	for (i = 0; i < n; i++) {
		if (p[i].num < k) continue;//剪枝1
		int sn = 0; double R = p[i].r, Minp = INF;
		if (vis.find(R) != vis.end()) continue;//剪枝2
		vis.insert(R);
		for (j = 0; j < n; j++) {
			if (p[j].r < R || fabs(p[j].r - R) < 1e-9) {
				save[sn++] = p[j];
				if (sn >= k)
					Minp = min(Minp, cal(save[sn - 1], save[sn - k]));
			}
		}
		if (sn < k) continue;
		for (j = 0; j < k - 1; j++) 
			Minp = min(Minp, cal(save[j], save[(j - k + 1 + sn)]) + 2 * pi);
		ans = min(ans, R * R * Minp / 2);
	}	
	return ans;
}

int main() {
	int cas = 0;
	while (~scanf("%d%d", &n, &k) && n + k) {
		for (int i = 0; i < n; i++) {
			scanf_(p[i].x); scanf_(p[i].y);
			p[i].r = sqrt(p[i].x * p[i].x + p[i].y * p[i].y);
			p[i].p = atan2(p[i].y, p[i].x);
			p[i].num = 1;
		}
		printf("Case #%d: %.2lf\n", ++cas, solve());
	}
	return 0;
}