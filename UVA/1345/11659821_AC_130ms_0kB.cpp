#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 2005;
const int INF = 0x3f3f3f3f;
struct account{
	char Name[20];
	int id;
	vector<int> group;
} dat[maxn];

struct edge{
	int to, cap, rev;
};
class Dinic{
public:
	int n, m, S, T;
	vector<edge> G[maxn];
	int level[maxn], iter[maxn];

	void add(int from, int to, int cap){
		edge newe = {to, cap, G[to].size()};
		G[from].pb(newe);
		newe = {from, 0, G[from].size()-1};
		G[to].pb(newe);
	}
	void init(int n_, int m_, int CapToT){
		
		n = n_; m = m_;

		S = 0, T = n+m+1;
		for (int i=0; i<=n+m+1; ++i){
			G[i].clear();
		}
		for (int i=1; i<=n; ++i){
			add(S, i, 1);
			for (int j=0; j<dat[i].group.size(); ++j){
				add(i, dat[i].group[j]+n+1, 1);
			}
		}
		for (int i=n+1; i<=n+m; ++i)
			add(i, T, CapToT);
	}
	void bfs(int s){
		memset(level, -1, sizeof(level));
		level[s] = 0;
		queue<int> Q; Q.push(s);
		while(!Q.empty()){
			int now = Q.front(); Q.pop();
			// printf("now=%d\n", now);
			for (int i=0; i<G[now].size(); ++i){
				edge &e = G[now][i];
				if (e.cap>0 && level[e.to]<0){
					level[e.to] = level[now]+1;
					Q.push(e.to);
				}
			}
		}
	}
	int dfs(int v, int t, int f){
		if (v == t) return f;
		for (int &i = iter[v]; i < G[v].size(); ++i){
			edge &e = G[v][i];
			if (e.cap > 0 && level[v] < level[e.to]){
				int d = dfs(e.to, t, min(f, e.cap));
				if (d){
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	int maxflow(int s, int t){

		int Flow = 0;
		while(1){
			bfs(s);
			if (level[t] < 0) return Flow;
			// printf("hello1\n");
			memset(iter, 0, sizeof(iter));
			int f;
			while(f = dfs(S, T, INF) > 0) Flow += f;
		}
	}


} dinic;
class Debug{
public:
	void show_input(int n){
		for (int i=1; i<=n; ++i){
			printf("%s ", dat[i].Name);
			for (int j=0; j<dat[i].group.size(); ++j)
				printf("%d ", dat[i].group[j]);
			printf("\n");

		}
	}
} debug;
int main(){
	// freopen("in.txt", "r", stdin);
	int n, m;
	while(scanf("%d%d", &n, &m)!=-1){
		if (n == 0 && m == 0) break;
		getchar();
		for (int i=1; i<=n; ++i){
			dat[i].group.clear();
			scanf("%s", dat[i].Name);
			dat[i].id = i;
			istringstream istr;
			string line;
			getline(cin, line);
			istr.str(line);
			int x;
			while(istr >> x) dat[i].group.pb(x);
		}

		// debug.show_input(n);

		int l = n+1, r = 0, mid;
		while(l > r+1){
			mid = (l+r)/2;
			dinic.init(n, m, mid);
			int check = dinic.maxflow(0, n+m+1);
			if (check < n) r = mid;

			else l = mid;
			// printf("mid=%d check=%d\n", mid, check);
		}
		cout << l << endl;
	}
	return 0;
}