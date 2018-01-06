#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
char s[maxn];
int main(){

	scanf("%s", s);
	int len = strlen(s);
	int res = 0;
	for (int i=0; i<len; ++i)
		for (int j=i+1; j<len; ++j)
			for (int k=j+1; k<len; ++k){
				if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q')
					++res;
			}
	cout << res << endl;

	return 0;
}