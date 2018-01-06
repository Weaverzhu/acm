#include<bits/stdc++.h>
using namespace std;


int main()
{
	char ch = getchar();
	while(ch != EOF){
		vector<char> ans;
		
		while(ch != '\n' && ch != EOF){
			ans.push_back(ch);
			ch = getchar();
		}
		for (int i=ans.size()-1; i>=0; --i)
			printf("%c", ans[i]);
		puts("");
		if (ch == EOF) break;
		else ch = getchar();
	}
	return 0;
}