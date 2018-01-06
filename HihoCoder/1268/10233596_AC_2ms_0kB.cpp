#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool r=false;
int m[3][3],ans[3][3],vis[10];
int xi[20],yi[20],ni=0;
void check(){
	int heng[3],shu[3],dui1=0,dui2=0;
	memset(heng,0,sizeof(heng));
	memset(shu,0,sizeof(shu));
	for (int i=0;i<3;++i){
		heng[0]+=m[0][i];
		shu[0]+=m[i][0];
		heng[1]+=m[1][i];
		heng[2]+=m[2][i];
		shu[1]+=m[i][1];
		shu[2]+=m[i][2];
		dui1+=m[i][i];
	}
	dui2=m[0][2]+m[1][1]+m[2][0];
	int ansi;
	bool suc=true;
	ansi=heng[0];
	for (int i=0;i<3;++i){
		if (heng[i]!=ansi||shu[i]!=ansi){
			suc=false;
			break;
		}
	}
	if (dui1!=ansi||dui2!=ansi) suc=false;
	if (suc){
		if(r){
			printf("Too Many\n");
			exit(0);
		}
		for (int i=0;i<3;++i)
			for (int j=0;j<3;++j){
				ans[i][j]=m[i][j];
			}
		r=true;
	}
}
	
	
	
	
void dfs(int remain){
	if (remain==0){
		check();
		return;
	}
	for(int r=1;r<=9;++r){
		if (vis[r]==0){
			int xr=xi[remain],yr=yi[remain];
			m[xr][yr]=r;
			vis[r]=1;
			dfs(remain-1);
			m[xr][yr]=0;
			vis[r]=0;
		}
	}
	return;
}
		
int main(){
	int cnt=0;
	for (int i=0;i<3;++i)
		for (int j=0;j<3;++j){ 
			scanf("%d",&m[i][j]);
			
			if (m[i][j]==0){
				++cnt;
				xi[cnt]=i;
				yi[cnt]=j;
			}else vis[m[i][j]]=1;
				
		}
	if (cnt==9){
		printf("Too Many\n");
		return 0;
	}
	dfs(cnt);
	for (int i=0;i<3;++i){
		for (int j=0;j<3;++j){
			printf("%d",ans[i][j]);
			if (j<2) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}