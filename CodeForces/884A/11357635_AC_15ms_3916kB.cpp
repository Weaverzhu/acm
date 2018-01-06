#include<bits/stdc++.h>
using namespace std;
int n, t;
const int maxn = 1e6+10;
int a[maxn];
int main(){
	while(scanf("%d%d", &n, &t) != -1){
		for (int i=0; i<n; ++i){
			scanf("%d", &a[i]);
			a[i] = 86400 - a[i];
		}
		int sum = 0, ans = 0;
		while(sum < t){
			sum += a[ans++];
		}
		cout << ans << endl;
	}

	return 0;
}