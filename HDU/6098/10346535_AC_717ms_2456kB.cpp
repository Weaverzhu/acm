#include<iostream>
#include<cstdio>
#include<algorithm>
const int maxn=1e5+10;
int a[maxn],id[maxn];;
using namespace std;
void qsort(int left, int right){
	int i=left,j=right,x=a[id[i]],k;
	do{
		while(a[id[i]]<x)++i;
		while(a[id[j]]>x)--j;
		if (i<=j){
			k=id[i];id[i]=id[j];id[j]=k;
			i++;j--;
		}
	}while(i<j);
	if (i<right) qsort(i,right);
	if (left<j) qsort(left,j);
	return;
}
void solve(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		id[i]=i;
	}
	qsort(1,n);
//	for (int i=1;i<=n;++i) cout<<a[id[i]]<<endl;
	for (int i=2;i<n;++i)
		for (int j=n;j>=1;--j){
			if (id[j]%i!=0){
				printf("%d ",a[id[j]]);
				break;
			}
		}
	for (int j=n;j>=1;--j){
		if (id[j]%n!=0){
			printf("%d\n",a[id[j]]);
			break;
		}
	}
	
}
int main(){
	int t;
	scanf("%d",&t);
	for (int i=0;i<t;++i) solve();
	return 0;
}