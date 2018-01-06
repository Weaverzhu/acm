#include<bits/stdc++.h>
using namespace std;
int n, x;
int main(){

	while(scanf("%d%d", &n, &x) != -1){
		long long sum = 0, tmp;
		for (int i=0; i<n; ++i)
			scanf("%I64d", &tmp), sum += tmp;
		if (n == 1)
		{
			if (sum == x)
				printf("YES\n");
			else
				printf("NO\n");
			continue;
		}
		
		
		if (x-sum == n-1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}