#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

int t;
string str;
void solve(){
	int ans=0,tmp=0;
	cin>>str;
	string t1;
	t1="";tmp=0;
	int strl=str.length();
	for (int k=0;k<=strl;++k){
		t1="";tmp=0;
		for (int i=0;i<k;++i) t1+=str[i];
		t1+='A';
		for (int i=k;i<strl;++i) t1+=str[i];
		bool flag=true;
		while(flag){
			flag=false;
			int leng=t1.length();
			for (int i=0;i<leng-1;++i){
				bool flag1=false;
				int j=i+1;
				while(t1[i]==t1[j]&&j<leng){
					++j;
					flag1=true;
				}
				
				if(flag1){
					--j;
					t1.erase(i,j-i+1);
					tmp+=j-i+1;
					leng-=j-i+1;
					--i;
					flag=true;
				}
				
			}
//			cout<<t1<<endl;
		}
		if(tmp>ans) ans=tmp;
	}
	
	for (int k=0;k<=strl;++k){
		t1="";tmp=0;
		for (int i=0;i<k;++i) t1+=str[i];
		t1+='B';
		for (int i=k;i<strl;++i) t1+=str[i];
		bool flag=true;
		while(flag){
			flag=false;
			int leng=t1.length();
			for (int i=0;i<leng-1;++i){
				bool flag1=false;
				int j=i+1;
				while(t1[i]==t1[j]&&j<leng){
					++j;
					flag1=true;
				}
				
				if(flag1){
					--j;
					t1.erase(i,j-i+1);
					tmp+=j-i+1;
					leng-=j-i+1;
					--i;
					flag=true;
				}
				
			}
//			cout<<t1<<endl;
		}
		if(tmp>ans) ans=tmp;
	}
	
	for (int k=0;k<=strl;++k){
		t1="";tmp=0;
		for (int i=0;i<k;++i) t1+=str[i];
		t1+='C';
		for (int i=k;i<strl;++i) t1+=str[i];
		bool flag=true;
		while(flag){
			flag=false;
			int leng=t1.length();
			for (int i=0;i<leng-1;++i){
				bool flag1=false;
				int j=i+1;
				while(t1[i]==t1[j]&&j<leng){
					++j;
					flag1=true;
				}
				
				if(flag1){
					--j;
					t1.erase(i,j-i+1);
					tmp+=j-i+1;
					leng-=j-i+1;
					--i;
					flag=true;
				}
				
			}
//			cout<<t1<<endl;
		}
		if(tmp>ans) ans=tmp;
	}
	
	cout<<ans<<endl;
	return;
}
	
			
		
int main(){
	cin>>t;
	for (int i=0;i<t;++i){
		 solve();
	}
	return 0;
}