#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int maxn = 50+10;
int n;
string sstd;
string a[maxn];
string getstr(int x, string sstd){
	string ans1="",ans2="",ans="";
	for(int i = 0; i <= x; ++i){
		ans1+=sstd[i];
	}
	for (int i = x+1;i<sstd.length();++i){
		ans2+=sstd[i];
	}
	ans+=ans2;
	ans+=ans1;
	return ans;
}


int main(){
	bool flag = false;
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	int leng;
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	sstd=a[0];leng=a[0].length();
	for (int i=0;i<n;++i)
		if (a[i].length()!=leng){
			cout << -1 << endl;
			return 0;
		}
	
	int ans=2147483647;
	for(int i = 0; i < leng ;++i){
		string str = getstr(i,sstd);
//		cout << str << endl;
//		if(str=="zwoxz") 
//			system("pause");
		int now=0;
		for (int j = 0; j < n; ++j){
			flag=true;
			for (int k =0;k<leng;++k){
				string nows=getstr(k,a[j]);
//				cout<<"nows="<<nows<<endl<<"sstd="<<sstd<<endl;
				if(nows==str){
					now+=k;
					flag=false;
					break;
					
				}
				
			}
			if(flag){
				cout << -1 << endl;
				return 0;
			}
		}
		if(now<ans)ans=now;
		
	}
	cout << ans << endl;
	return 0;
}