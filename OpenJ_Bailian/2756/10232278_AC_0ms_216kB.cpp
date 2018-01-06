#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=10000;
int a[maxn];
int ca=0;
int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	a[ca++]=x;
	while(x!=1){
		x/=2;
		a[ca++]=x;
	}
	int ans;
	while(y!=1){
		for (int i=0;i<ca;++i)
			if (a[i]==y){
				cout<<a[i]<<endl;
				return 0;
			}
		y/=2;
	}
	cout << 1 << endl;
	return 0;
}