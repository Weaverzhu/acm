#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int maxn=1000;
int n;
int s[maxn];
int stop=-1;
int main(){
//	freopen("in.txt","r",stdin);
	int t;
//	cin.get();
	scanf("%d",&t);
	cin.get();
	for (int i=0;i<t;++i){
		string line;stop=-1;
		bool flag=false;
		getline(cin,line);
		for(int i=0;i<line.length();++i){
			if(line[i]=='['||line[i]=='(') s[++stop]=line[i];
			else if (stop>=0&&s[stop]=='('&&line[i]==')')--stop;
			else if (stop>=0&&s[stop]=='['&&line[i]==']')--stop;
			else flag=true;
		}
		if (!flag&&stop==-1) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}