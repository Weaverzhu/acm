#include<bits/stdc++.h>
using namespace std;
const int M1 = 400005;
const int M2 = 45;
char d1[M1][M2], d2[M1][M2];
int v[26];
void init(){
	memset(d1, 0, sizeof(d1));
	memset(d2, 0, sizeof(d2));
	memset(v, 0, sizeof(v));

}
class Trie{
// const int sz = 26;
public:
	int a[M1][26], cnt = 0;
	int b[26];
	void init(){
		memset(a, 0, sizeof(0));
		for (int j=0; j<26; ++j) a[0][j] = -1;
		memset(b, 0, sizeof(b));
		cnt = 1;
	}
	void ins(char s[]){
		int len = strlen(s), now = 0;
		for (int i=0; i<len; ++i){
			// cout << now << endl;
			int x = s[i] - 'a';
			
			if (a[now][x] == -1){
				for (int j=0; j<26; ++j) a[cnt][j] = -1;
				a[now][x] = cnt;
				if (i>0 ) ++b[x];
				now = cnt;
				cnt++;
			}else now = a[now][x];
		}
	}
	long long getCnt(){return cnt;}
} t1, t2;
typedef unsigned long long ull;

int main(){

	int n;
	while(scanf("%d", &n) != -1){
		init();
		set<ull> S;
		t1.init(); t2.init();
		for (int i=0; i<n; ++i){
			
			scanf("%s", d1[i]);
			t1.ins(d1[i]);
			int len = strlen(d1[i]);
			if (len == 1) v[d1[i][0]-'a'] = 1;
			for (int j=0; j<len; ++j)
				d2[i][j] = d1[i][len-1-j];
			t2.ins(d2[i]);
		}
		ull ans = (t1.getCnt()-1) * (t2.getCnt()-1);
		// cout << (t1.getCnt()-1) << endl << (t2.getCnt()-1) << endl;
		for (int i=0; i<26; ++i)
			ans -= 1LL*t1.b[i]*t2.b[i]-v[i];
		cout << ans << endl;
		// for (int i=0; i<26; ++i)
		// 	cout <<t1.b[i] << " " << t2.b[i] << endl;

	}

	return 0;
}