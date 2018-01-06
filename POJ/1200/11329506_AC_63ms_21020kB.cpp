#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
// set<string> S;
char str[20000000];
bool hsh[20000000];
int n, nc;
int id[500];
int len, cnt, ans;
void debug1()
{
	printf("len = %d n = %d\n", len, n);
	for (int i=0; i<len; ++i)
		printf("%d", id[str[i]]);
	printf("\n");
}
int main()
{
	while(scanf("%d%d", &n, &nc) != -1)
	{
		memset(hsh, 0, sizeof(hsh));
		memset(id, -1, sizeof(id));
		scanf("%s", str);
		len = strlen(str), cnt = 0, ans = 0;
		for (int i=0; i<len; ++i)
			if (id[str[i]] == -1)
			{
				id[str[i]] = cnt++;
			}
		//3 4debug1();
		for(int i=0; i<=len-n; ++i)
		{
			int s = 0;
			for (int j=i; j<i+n; ++j)
				s = s*nc + id[str[j]];
			if (!hsh[s])
			{
				hsh[s] = true;
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}