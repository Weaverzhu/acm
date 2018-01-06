#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<cmath>

using namespace std;
map<char, int>cnt;
int head,tail;
int check(){
	int c;
	if(cnt['h']>=2&&cnt['i']>=1&&cnt['o']>=1) c=1;
	if (cnt['h']==2&&cnt['i']==1&&cnt['o']==1) c=2;
	if ((cnt['h']<2||cnt['i']<1||cnt['o']<1)) c=0;
	return c;
}
int main(){
	string a;
	cin>>a;
	int ans=1e9;
	head=0;tail=0;
	for (tail=0;tail<a.length();++tail){
		cnt[a[tail]]++;
		bool flag=false;
		while(check()>0){
			flag=true;
			cnt[a[head]]--;
			head++;
		}
		if(flag){
			head--;cnt[a[head]]++;
		}
		if (check()==2) ans=min(ans,tail-head+1);
	}
	if (ans==1e9)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
	