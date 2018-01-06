#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=5*(1e5)+10;
int a[maxn];
int q[maxn],h[maxn];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	int tmp=0,max=a[1];
	bool flag=false;
	for (int i=1;i<=n;++i){
		if (tmp+a[i]>0) {
			tmp+=a[i];
			flag=true;
		}
		else{
			flag=false;tmp=0;
		}
		if (max<tmp&&a[i]>max) max=a[i];
		if (max<tmp&&flag) max=tmp;
		q[i]=max;
	}
	tmp=0;max=a[n];
	flag=false;
	for (int i=n;i>=1;--i){
		if (tmp+a[i]>0) {
			tmp+=a[i];
			flag=true;
		}
		else{
			flag=false;tmp=0;
		}
		if (!flag&&a[i]>max) max=a[i];
		if (max<tmp&&flag) max=tmp;
		h[i]=max;
	}
	
	int ans=-1e9;
	for(int i=1;i<=n-2;++i){
		if (q[i]+h[i+2]>ans) ans=q[i]+h[i+2];
	}
	cout << ans << endl;
	return 0;
}