#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn = 200000+10;
ll a[maxn];
ll sum[maxn];
int main()
{
	while(scanf("%d", &n) != -1){
		
		long long ans = 0;
		priority_queue<ll, vector<ll>, greater<ll> > pq;
		int tmp;
		for (int i=1; i<=n; ++i){
			scanf("%d", &tmp);
			pq.push(tmp);
		}
		if (n == 1){
			printf("0\n");
			continue;
		}
		while(!pq.empty()){
			if (pq.size()%2){
				long long now;
				now = pq.top();
				pq.pop();
				now+=pq.top();
				pq.pop();
				now+=pq.top();
				pq.pop();
				ans += now;
				if (pq.empty()) break;
				else pq.push(now);
			}else pq.push(0LL);
		}
		cout << ans << endl;
		
	}
	
	return 0;
} 