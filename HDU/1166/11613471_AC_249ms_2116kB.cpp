#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 50000;
LL dat[maxn+10], n;
LL lowbit(int x){
	return x & (-x);
}

void add(int index, int x){
	for (int i=index; i<=n; i += lowbit(i))
		dat[i] += x;
	return;
}
LL sum(int a){
	LL res = 0;
	if (a == 0)
		return 0;
	for (int i=a; i>0; i -= lowbit(i))
		res += dat[i];
	// printf("sum completed\n");
	return res;
}
bool check(char *com){
	if (com[0] == 'E' && com[1] == 'n' && com[2] == 'd')
		return true;
	return false;
}
int main(){

	int t;
	cin >> t;
	for (int kase = 1; kase <= t; ++kase){
		memset(dat, 0, sizeof(dat));

		printf("Case %d:\n", kase);
		cin >> n;
		char com[10];
		for (int i=1; i<=n; ++i){
			int x;
			scanf("%d", &x);
			add(i, x);
		}
		getchar();
		while(1){
			scanf("%s", com);
			// printf("com = %s\n%c\n", com);
			if (check(com)) break;
			else{
				int a, b;
				scanf("%d%d", &a, &b);
				if (com[0] == 'S'){
					int v = sum(a) - sum(a-1);
					if (b > v) b = v;

					
					// int value = sum(a) - sum(a-1);
					add(a, -b);
					// printf("add completed\n");
				}
				else if (com[0] == 'A'){
					
					add(a, b);
					// printf("add completed\n");
				}
				else if (com[0] == 'Q'){
					printf("%I64d\n", sum(b) - sum(a-1));
					// printf("q completed\n");
				}
			}
		}
	}
	return 0;
}