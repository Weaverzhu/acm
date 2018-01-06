#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
char s[maxn];
int a[maxn];
int main(){

	while(~scanf("%s", s)){
		int len = strlen(s);
		for (int i=0; i<len; ++i)
			a[i] = s[i]-'a';

		int l = len, r = 0;
		while(l > r+1){
			int mid = l+r >> 1;
			bool suc = false;
			for (int k = 0; k < 26; ++k){
				int cnt = 0;
				for (int i=0; i<mid; ++i){
					if (a[i] == k) ++cnt;
				}
				 // cout << "cnt = " << cnt << endl;
				if (cnt == 0) continue;
				suc = true;
				for (int i=mid; i<len; ++i){
					if (a[i] == k) ++cnt;
					if (a[i-mid] == k) --cnt;
					if (cnt <= 0){
						// printf("i=%d\n", i);
						suc = false;
						break;					
					}
				}
				if (suc) break;
			}
			if (suc) l = mid;
			else r = mid;
		}
		cout << l << endl;
	}

	return 0;
}