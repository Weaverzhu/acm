#include<iostream>
#include<cstdio>
#include<string>
const int maxn=800+5;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int map[maxn][maxn],ans[maxn][maxn];
using namespace std;
string a;
struct node{
	int x,y,step=0;
};
node data[700000+10];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int cl=-1,op=-1;
	for (int i=1;i<=n;++i){
		cin>>a;
		for (int j=1;j<=m;++j){
			if (a[j-1]=='0') map[i][j]=0;else map[i][j]=1;
			if (map[i][j]==0){
				op++;
				data[op].x=i;
				data[op].y=j;
				data[op].step=0;
			}
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (map[i][j]==1) ans[i][j]=-1;
		}
	}
	do{
		++cl;
		for (int r=0;r<4;++r){
			int nx=data[cl].x+dx[r],
				ny=data[cl].y+dy[r];
			
			if (nx>=1&&nx<=n&&ny>=1&&ny<=m
				&&map[nx][ny]!=0
				&&(ans[nx][ny]==-1||ans[nx][ny]>(data[cl].step+1))){
				++op;
				data[op].x=nx;data[op].y=ny;
				data[op].step=data[cl].step+1;
				ans[nx][ny]=data[op].step;
			}
		}
	}while(cl<op);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			printf("%d",ans[i][j]);
			if (j<n) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
			
	