#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2000;
struct student{
	int m,num;
};
student data[maxn+10];
int ans[maxn+10];
int cmp(student a,student b){
	return a.m>b.m;
}
int n;
int main(){
	scanf("%d",&n);
		for (int i=1;i<=n;++i){
			scanf("%d",&data[i].m);
			data[i].num=i;
		}
		sort(data+1,data+n+1,cmp);
		ans[data[1].num]=1;
		int now=1;
		int tmp=1;
		for (int i=2;i<=n;++i){
			if (data[i].m==data[i-1].m){
				ans[data[i].num]=tmp;
				++now;
			}
			else{
				ans[data[i].num]=++now;
				tmp=now;
			}
		}
		for (int i=1;i<n;++i) printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
	
	return 0;
}