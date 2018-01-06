#include<bits/stdc++.h>
using namespace std;
int t;
int n;
const int N = 20005;
int a[N];
int main(){
	cin >> t;
	while(t--){
		scanf("%d", &n);
		int c1 = 0, c2 = 0;
		for (int i=1; i<=n; ++i){
			scanf("%d", &a[i]);
			if (a[i] > 1) c2++;
			else c1++;
		}
		if (c2 > 0 || (c2 == 0 && c1 % 2 == 1)){
			cout << "poopi" << endl;
		}else cout << "piloop\n"; 

	}

	return 0;
}