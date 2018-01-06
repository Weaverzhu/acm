#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
const int sz = 2;
const int _minus = 48;
int cnt, n, ans;
struct Trie{
	int id, v;
	int n[sz];
	Trie(){
		v = 0, id = cnt;
		memset(n, -1, sizeof(n));
	}
};

Trie dat[maxn];
Trie root;
void insert(char s[]);
void init();

char str[maxn];
int main(){
	cerr << "err\n";
	int t; cin >> t;
	while(t--){
		init();
		scanf("%d", &n);
		for (int i=0; i<n; ++i){
			scanf("%s", str);
			insert(str);
			cerr << "err\n";
		}
		cout << ans << endl;
	}
	return 0;
}
void insert(char s[]){
	int len = strlen(s);
	cerr << s << endl;
	int now = 0;
	for (int i=0; i<len; ++i){
		int j = s[i]-_minus;
		if (dat[now].n[j] == -1){
			dat[cnt] = Trie();
			dat[now].n[j] = cnt;
			now = cnt;
			cnt++;
		}else now = dat[now].n[j];
		dat[now].v++;
		int res = 0;
		res = dat[now].v*(i+1);
		if (res > ans) ans = res;
		
		if (i == 2) cerr << "now.v:" << dat[now].v << endl;
	}
	return;
}
void init(){
	cnt = 0;
	dat[0] = Trie();
	// cout << dat[0].id << endl;
	cerr << "root:" << dat[0].n[0] << endl;
	root = dat[0];
	cnt++;
	ans = -1;

}