#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int a[30],b[30];
int main(){
	string line;
	cin>>line;
	for (int i=0;i<line.length();++i) ++a[line[i]-'A'];
	cin>>line;
	for (int i=0;i<line.length();++i) ++a[line[i]-'A'];
	cin>>line;
	for (int i=0;i<line.length();++i) ++b[line[i]-'A'];
	bool flag=true;
	for (int i=0;i<26;++i)
		if (a[i]!=b[i]){
			flag=false;
			break;
		}
	if (flag) printf("YES\n"); else printf("NO\n");
	
	return 0;
}

