#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;
int n, a[N], c[N], sz, ans[N];

int main(){
	// freopen("in.txt", "r", stdin);
	while(cin >> n){
		memset(c, 0, sizeof(c));
		sz = 0;
		int sum = 0;
		for (int i=1; i<=n; ++i)
			scanf("%d", &a[i]);

		bool suc = true;
		for (int i=1; i<=n; ++i){
			if (a[i] >= 0){
				++c[a[i]];
				if (a[i] == 0) ++sum;
			}else if (a[i] < 0){
				int now = -a[i];
				// cout << now << endl;
				// cout << c[0] << endl;
				if (c[now] > 0) --c[now];
				else if (c[0] > 0){
					ans[sz++] = now;
					--c[0];
				}else{
					suc = false;
					break;
				}
			}
		}
		if (suc){
			printf("Yes\n");
			if (sum > sz){
				int tmp = sum-sz;
				for (int i=0; i<tmp; ++i)
					ans[sz++] = 1;
			}
			for (int i=0; i<sz; ++i)
				printf("%d%c",ans[i],  i == sz-1? '\n':' ');


		}else{
			printf("No\n");
		}
	}


	return 0;
}