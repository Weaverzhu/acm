#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int a[100+10],vis[100+10];
bool check(int a1,int a2,int a3){
	if (a1+a2<=a3||a1+a3<=a2||a2+a3<=a1) return false;
	else return true;
}
double s(int a1,int a2,int a3){
	double ans,p;
	p=(a1+a2+a3)/2.0;
	double t1=p-a1,t2=p-a2,t3=p-a3;
	ans=sqrt(p*t1*t2*t3);
	return ans;
}

int main(){
	int kase,n;
	scanf("%d",&kase);
	for (int i=0;i<kase;++i){
//		memset(vis,0,sizeof(vis));
		double ans=0.0;
		scanf("%d",&n);
		for (int j=0;j<n;++j) scanf("%d",&a[j]);
		for (int k1=0;k1<n;++k1){
			for (int k2=k1+1;k2<n;++k2){
				for (int k3=k2+1;k3<n;++k3){
					if (check(a[k1],a[k2],a[k3])==0) continue;
					double tmp=s(a[k1],a[k2],a[k3]);
					if (tmp>ans) ans=tmp;
				}
			}
		}
		if (ans>0) printf("%.3lf\n",ans);
		else printf("no\n");
//		cout<<ans<<endl;
	}
	return 0;
}
	
	