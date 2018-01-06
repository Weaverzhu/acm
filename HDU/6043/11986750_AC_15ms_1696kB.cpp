#include<bits/stdc++.h>
using namespace std;

int main(){
	long long k, n;
	int kk=1;
	while(scanf("%I64d%I64d", &n, &k)!=-1){
		printf("Case #%d: ", kk++);
		if (k <= n) cout << k << endl;
		else{
			k -= n;
			k = k % (2*n-2);
			if (k == 0) k = 2*n-2;
			if (k <= n-1) cout << k << endl;
			else{
				k -= n-1;
				if (k == n-1) cout << n << endl;
				else cout << k << endl;
			}
		}
	}


	return 0;
}