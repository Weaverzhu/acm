#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int t;
	int L,n;
	int x[100000+10];
	scanf("%d",&t);
	for (int xx=0;xx<t;++xx){
		
		
		scanf("%d%d",&L,&n);
		for (int i = 0; i < n; ++i) scanf("%d",&x[i]);
		int minT=0;
		for (int i=0;i<n;++i){
			minT=max(minT,min(x[i],L-x[i]));
		}
		int maxT=0;
		for (int i=0;i<n;++i){
			maxT=max(maxT,max(x[i],L-x[i]));
		}
		printf("%d %d\n",minT,maxT);
	}
}