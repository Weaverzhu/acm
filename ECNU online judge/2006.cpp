#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000000+10;
bool is[maxn];
int ans[maxn], an;
int main(){
	memset(is, 1, sizeof(is));
	for (int i=1; i<=1000000; ++i){
		int sum = 0, tmp = i;
		while(tmp){
			sum += tmp%10;
			tmp /= 10;
		}
		is[sum+i] = false;
	}
	for (int i=1; i<=1000000; ++i)
		if (is[i])
			printf("%d\n", i);
	return 0;
}