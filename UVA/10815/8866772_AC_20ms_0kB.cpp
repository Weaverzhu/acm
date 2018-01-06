#include<cstdio>
#include<cstring>
#include<set>
#include<sstream>
#include<stack>
#include<vector>
#include<iostream>
using namespace std;
set<string>dict;//stringÎª¼¯ºÏ 
int main(){
	string s,buf;
	while(cin>>s){
		for (int i=0;i<s.length();i++)
		    if (isalpha(s[i])) s[i]=tolower(s[i]); else s[i]=' ';// isalpha ÅÐ¶ÏÊÇ·ñÎª×ÖÄ»£¬tolower×ª»»´óÐ¡Ð´ 
		stringstream ss(s);
		while (ss>>buf) dict.insert(buf);
	}
	for (set<string>::iterator it =dict.begin();it!=dict.end();++it) //Ïê¼ûp113
	    cout<<*it<<"\n";
	return 0;
}
	