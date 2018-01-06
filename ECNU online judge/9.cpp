#include<bits/stdc++.h>
using namespace std;

int main(){
	int now = 1;
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; ++i){
		printf("%d", now++);
		for (int j=2; j<=m; ++j)
			printf(" %d", now++);
		printf("\n");
	}
	return 0;
}