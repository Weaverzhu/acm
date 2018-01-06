#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int x, y, n;
LL f[10000];
int main(){
	while(1){
		scanf("%d%d", &x, &y);
		memset(f, 0, sizeof(0));
		if (scanf("%d", &n) == EOF) break;
		if (x == 2 && y == 1){
			cout << 2 << endl;
			continue;
		}
		if (x == 0 && y == 0){
			cout << 0 << endl;
			continue;
		}
		if (x == 1 && y == 0){
			cout << 1 << endl;
			continue;
		}
		if (x == 0 && y == 1){
			if (n % 4 == 0) cout << 2 << endl;
			else if (n % 4 == 2) cout << -2 << endl;
			else cout << 0 << endl;
			continue;
		}
		f[1] = x;
		f[0] = 2;
		for (int i=2; i<=n; ++i){
			f[i] = x*f[i-1]-y*f[i-2];
		}
		cout << f[n] << endl;
		
	}
	return 0;
}