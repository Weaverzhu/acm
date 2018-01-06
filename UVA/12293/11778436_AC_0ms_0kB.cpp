#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n) != -1){
		if (n == 0) break;
		++n;
		while(n%2 == 0) n/=2;
		if (n == 1){
			printf("Bob\n");
		}else printf("Alice\n");
	}
	return 0;
}