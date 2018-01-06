#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5, mod = 1e9+7;

int n, m;
int a[maxn], b[maxn];
int vis[maxn];

vector<int> A, B;

int main(){
	int kase = 0;
	while(~scanf("%d%d", &n, &m)){
		int i;
		for(i=0; i<n; ++i)
			scanf("%d", &a[i]);
		for(i=0; i<m; ++i)
			scanf("%d", &b[i]);

		A.clear();
		memset(vis, 0, sizeof(vis));
		for(i=0; i<n; ++i){
			int cur=i, cnt=1;
			if (!vis[i]){
				vis[i]=1;
				while(a[cur]!=i){
					cur=a[cur];
					vis[cur]=1;
					cnt++;
				}
				A.push_back(cnt);
			}
		}

		B.clear();
		memset(vis, 0, sizeof(vis));
		for(i=0; i<m; ++i){
			int cur=i, cnt=1;
			if (!vis[i]){
				vis[i]=1;
				while(b[cur]!=i){
					cur=b[cur];
					vis[cur]=1;
					cnt++;
				}
				B.push_back(cnt);
			}
		}
		ll ans=1;
		for(i=0; i<A.size(); ++i){
			ll tmp=0;
			int j;
			for(j=0; j<B.size(); ++j){
				if (A[i]%B[j]==0) tmp=(tmp+B[j])%mod;

			}
			ans = ans*tmp%mod;
		}
		printf("Case #%d: %d\n", ++kase, ans);
	}
	return 0;
}