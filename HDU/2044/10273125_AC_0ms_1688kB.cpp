#include<iostream>
#include<cstdio>
typedef long long ll;
ll f[60];
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	f[1]=1;f[2]=2;
	for (int i=3;i<55;++i){
		f[i]=f[i-1]+f[i-2];
	}
	for (int i=0;i<t;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		cout<<f[b-a]<<endl;
	}
	return 0;
}