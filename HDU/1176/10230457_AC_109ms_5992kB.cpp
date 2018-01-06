#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1e5+10;
int f[maxn][11];
int n;
int main(){
	scanf("%d",&n);
	while(n!=0){
		memset(f,0,sizeof(f));
		int maxt=0;
		for (int i=0;i<n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			f[b][a]+=1;
			if (b>maxt)maxt=b;
		}
		for (int i=maxt+5;i>=0;--i)
			for (int j=0;j<=10;++j){
				int tmp=f[i+1][j];
				if(j>0)tmp=max(tmp,f[i+1][j-1]);
				if(j<10)tmp=max(tmp,f[i+1][j+1]);
				f[i][j]+=tmp;
			}
		cout<<f[0][5]<<endl;
		scanf("%d",&n);
	}
	return 0;
}