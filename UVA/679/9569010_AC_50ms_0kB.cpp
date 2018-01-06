#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn = pow(2, 20) + 10;
//int tree[maxn];
/*int main(){
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		int d, k;
		memset(tree, 0, sizeof(tree));
		scanf("%d%d", &d, &k);
		for (int j = 1; j <= k; ++j){
			int now = 1, target = pow(2, d - 1);
			while (now < target){
				if (tree[now] == 0) {
					tree[now] = 1;
					now += now;
				}else{
					tree[now] = 0;
					now += now + 1;
				}
			}
			if (j == k ) {
				cout << now;
				if (i != n-1) cout << endl;
			}
		}
	}
	return 0;
}*/
int main(){
	int n;
	scanf("%d", &n);
	int d, k;
	for (int i = 0; i < n; ++i){
		scanf("%d %d", &d, &k);
		int now = 1, target = pow(2, d - 1);
		while (now < target){
			if (k % 2 == 0){
					now = now * 2 + 1;
					k = k / 2;
			}
			else{
				now = now * 2;
				k = (k + 1) / 2;
			}
		}
		cout << now << endl ;
//		if (i < n - 1) cout << endl;
	}
	return 0;
}
					
				