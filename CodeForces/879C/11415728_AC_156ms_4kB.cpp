#include<bits/stdc++.h>
using namespace std;
const int maxn = 500000;
int n;
int ans[20], tp[20], c_tp, res1[20], res2[20], res3[20];
int main(){
	while(~scanf("%d", &n)){
		int now = 1;
		int x = 2;
		memset(ans, -1, sizeof(ans));
		for (int i=0; i<n; ++i){
			char op[5];
			int c;
			scanf("%s%d", op, &c);
			int tmp = c;
			c_tp = 0;
			memset(tp, 0, sizeof(tp));
			while(tmp){
				tp[c_tp++] = tmp % 2;
				tmp /= 2;
			}
			if (op[0] == '|'){
				for (int j=0; j<10; ++j){
					if (tp[j] == 1) ans[j] = 1;
				}
				x = x | c;
			}
			else if (op[0] == '&'){
				for (int j=0; j<10; ++j){
					if (tp[j] == 0) ans[j] = 0;
				}
				x = x & c;
			}
			else if (op[0] == '^'){
				for (int j=0; j<10; ++j){
					if (tp[j] == 1){
						if (ans[j] == -1)
							ans[j] = -2;
						else ans[j] = (ans[j]+1) % 2;
					}
				}
				x = x ^ c;
			}

		}
		// for (int i=0; i<10; ++i)
		// 	printf("%d ", ans[i]);
		// puts("");
		memset(res1, 0, sizeof(res1));
		memset(res2, 0, sizeof(res2));
		memset(res3, 0, sizeof(res3));
		for (int i=0; i<10; ++i){
			if (ans[i] == 0) res1[i] = 0;
			else res1[i] = 1;
			if (ans[i] == 1) res2[i] = 1;
			else res2[i] = 0;
			if (ans[i] == -2) res3[i] = 1;
			else res3[i] = 0;
		}
		int c1=0, c2=0, c3=0;
		for (int i=9; i>=0; --i){
			c1 = 2*c1+res1[i];
			c2 = 2*c2+res2[i];
			c3 = 2*c3+res3[i];
		}
		cout << 3 << endl;
		printf("& %d\n", c1);
		printf("| %d\n", c2);
		printf("^ %d\n", c3);
		int y = x & c1 | c2 ^ c3;
	}
	return 0;
}