#include<iostream>
using namespace std;
int n,m,k,ans;
int f[200000+10],s[200000+10];
int findroot(int x){
	int t;
	if (x==f[x]) return f[x];
	t=f[x];f[x]=findroot(f[x]);
	s[x]+=s[t];
	return f[x];
}
void merge(int x,int y){
	int a=findroot(x),b=findroot(y);
	if(a==b){
		if (s[y]!=s[x]+k) ++ans;
		return;
	}
	if (a>b){
		s[a]=s[y]-s[x]-k;
		f[a]=b;
	}else{
		s[b]=s[x]+k-s[y];
		f[b]=a;
	}
	return;
}
int main(){
	
	while(scanf("%d%d",&n,&m)!=-1){
	ans=0;
	for (int i=0;i<=n;++i){
		f[i]=i;s[i]=0;
	}
	for (int i=0;i<m;++i){
		int x,y;
		scanf("%d%d%d",&x,&y,&k);
		merge(x-1,y);
	}
	printf("%d\n",ans);
}
	return 0;
}
