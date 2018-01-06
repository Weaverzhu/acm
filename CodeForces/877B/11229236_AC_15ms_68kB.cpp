#include<bits/stdc++.h>
using namespace std;
const int maxn = 5000+5;
char s[maxn];
int n, m, len;
int na[maxn], nb[maxn], ib[maxn], cnt;


int main()
{
	while(scanf("%s", s) != -1)
	{
		int ans = 0;
		cnt = 0; len = strlen(s);
		na[0] = nb[0] = 0;
		if (s[0] == 'a') na[0]++;
		else nb[0] ++, ib[cnt++] = 0;
		for (int i=1; i<len; ++i)
			if (s[i] == 'a') na[i] = na[i-1]+1, nb[i] = nb[i-1];
			else if (s[i] == 'b') na[i] = na[i-1], nb[i] = nb[i-1]+1, ib[cnt++] = i;
		if (cnt <= 1) {cout << len << endl; continue;}
		for (int i=0; i<cnt-1; ++i)
			for (int j=i+1; j<cnt; ++j)
			{
				if ((j-i+1+na[ib[i]] + na[len-1]-na[ib[j]]) > ans)
					ans = j-i+na[ib[i]]+na[len-1]-na[ib[j]]+1;
			}
		// for (int i=0; i<len; ++i) printf("%d ", na[i]); cout << endl;
		// for (int i=0; i<len; ++i) printf("%d ", ib[i]); cout << endl;
		cout << ans << endl;

	}


	return 0;
}