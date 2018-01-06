#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
bool vis[maxn];
int p[maxn];
int n;
vector<int> lint;
int cnt;
void dfs(int now){
	vis[now] = true; cnt++;
	if (!vis[p[now]]) dfs(p[now]);
	else return;
}


int main(){
	while(scanf("%d", &n) != -1){
		lint.clear();
		memset(vis, 0, sizeof(vis));
		for (int i=1; i<=n; ++i) scanf("%d", &p[i]);
		for (int i=1; i<=n; ++i){
			if (!vis[i]) cnt = 0, dfs(i), lint.push_back(cnt);
			
		}
		sort(lint.begin(), lint.end());
		int sz = lint.size();
		if (sz == 1) printf("%I64d\n", 1LL*lint[0]*lint[0]);
		else if (sz == 2) printf("%I64d\n", 1LL*(lint[0]+lint[1])*(lint[0]+lint[1]));
		else{
			long long ans = 0;
			for (int i=0; i<sz-2; ++i)
				ans += lint[i]*lint[i];
			ans += 1LL * (lint[sz-1]+lint[sz-2]) * (lint[sz-1]+lint[sz-2]);
			printf("%I64d\n", ans);
		}
	}
	
	
	return 0;
} 