#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000+10;
int s[maxn], d[maxn];
int n, k;

void solve(){
	for (int i=0; i<n; ++i)
		scanf("%d%d", &s[i], &d[i]);
	int now = s[0]+1;
	// printf("%d\n", now);
	for (int i=1; i<n; ++i){
		if (now < s[i]) now = s[i];
		else{
			int tmp = now-s[i];
			// printf("tmp=%d\n", tmp);
			if (tmp % d[i]){
				now = (tmp/d[i]+1)*d[i]+s[i];
			} 

		}
		// printf("%d\n", now);
		++now;
	}
	cout << now-1 << endl;

}

int main(){
	while(~scanf("%d", &n))
		solve();

	return 0;
}