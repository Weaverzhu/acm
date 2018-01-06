#include<stdio.h>

int main(){
	freopen("in.txt", "r", stdin);
	int a, b;
	int t;
	scanf("%d", &t);
	// printf("%d\n", t);
	for (int kase=1; kase<=t; ++kase){
		printf("case #%d:\n", kase);
		scanf("%d\n", &a);
		// printf("%d\n", a);
		int cnt2 = 0, cnt5 = 0;
		for (int i=1; i<=a; ++i){
			int b = i;
			while(b%2 == 0) cnt2++, b/=2;
			while(b%5 == 0) cnt5++, b/=5;
		}
		printf("%d\n", cnt2>cnt5? cnt5:cnt2);
	}


	return 0;
}