#include<bits/stdc++.h>
using namespace std;
const int maxl = 100+10;
char str[maxl];
int n, m;
const char fri[5][200] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

int main()
{
	// freopen("in.txt", "r", stdin);
	while(scanf("%s", str) != -1)
	{
		int len = strlen(str);
		int cnt[5];
		for (int i=0; i<5; ++i) cnt[i] = 0;
		for (int i=0; i<5; ++i)
		{
			int flen = strlen(fri[i]);
			for (int j=0; j<=len-flen; ++j)
			{
				bool suc = true;
				if (str[j] == fri[i][0])
				{
					for (int k=0; k<flen; ++k)
						if (str[k+j] != fri[i][k])
						{
							suc = false;
							break;
						}
					if (suc) {++cnt[i];}
				}
			}

		}
		int sum = 0;
		for (int i=0; i<5; ++i) sum += cnt[i];
		// for (int i=0; i<5; ++i) cout << cnt[i] << " ";
		// cout << endl;
		if (sum == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}