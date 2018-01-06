#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<fstream>
#include<string>

using namespace std;
string a;
int n, m, tot,la;
const int maxn = 1e7 + 10;
struct node {
	int b[26];
	int key;
};
const int A = 'a';
node dat[maxn];
	
void dfs(int now,int k) {
	if (k == la)return;
	int target = dat[now].b[a[k] - A];
	if (target) {
		++dat[target].key;
		dfs(target, k + 1);
	}
	else {
		++tot;
		dat[now].b[a[k] - A] = tot;
		++dat[tot].key;
		dfs(tot,k+1);
	}



}
void init() {
	tot = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a; la = a.length();
		dfs(0, 0);
	}
}
int dfs2(int now, int k) {
	if (k == la) {
		return dat[now].key;
	}
	int target = dat[now].b[a[k] - A];
	if (target == 0) return 0;
	else return dfs2(target, k + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n) {
		init();
		cin >> m;
		for (int i = 1; i <= m; ++i) {
			cin >> a;
			la = a.length();
			cout << dfs2(0, 0) << endl;
		}
	}


    return 0;
}