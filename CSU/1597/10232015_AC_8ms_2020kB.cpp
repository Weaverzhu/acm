#include<iostream>
#include<cstdio>
int a,bb,x,y,p,n;
using namespace std;
void solve(){
	scanf("%d%d%d%d%d%d",&x,&y,&a,&bb,&p,&n);
	//kuaisumi
	
	int b[2][2],ans[2];
	ans[0]=x;ans[1]=y;
	b[0][0]=0;b[0][1]=1;b[1][0]=a;b[1][1]=bb;
	while(n>0){
		if (n%2){
			int t1=b[0][0]*ans[0]+b[0][1]*ans[1],t2=b[1][0]*ans[0]+b[1][1]*ans[1];
			ans[0]=t1%p;ans[1]=t2%p;
		}
		//b*b
		int t1=(b[0][0]*b[0][0]+b[0][1]*b[1][0]) %p;
		int t2=(b[0][0]*b[0][1]+b[0][1]*b[1][1]) %p;
		int t3=(b[1][0]*b[0][0]+b[1][1]*b[1][0]) %p;
		int t4=(b[1][0]*b[0][1]+b[1][1]*b[1][1]) %p;
		b[0][0]=t1%p;b[0][1]=t2%p;b[1][0]=t3%p;b[1][1]=t4%p;
		//b*b
		n/=2;
	}
	cout<<ans[1]<<endl;
}
	
	
	//kuaisumi
int main(){
	int kase;
	scanf("%d",&kase);
	for (int i=0;i<kase;++i) solve();
	return 0;
}