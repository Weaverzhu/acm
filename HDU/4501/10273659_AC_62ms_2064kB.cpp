#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
struct good{
	int val,a,b;
};
const int maxn=100;
const int maxv1=100;
const int maxv2=100;
const int maxk=5;

int f[maxv1+10][maxv2+10][maxk+3];

good data[maxn+10];


int main(){
	int n,v1,v2,k;
	while(scanf("%d%d%d%d",&n,&v1,&v2,&k)!=EOF){
		for (int i=1;i<=n;++i){
			scanf("%d%d%d",&data[i].a,&data[i].b,&data[i].val);
		}
		memset(f,0,sizeof(f));
		for(int in=1;in<=n;++in){
			
			for (int iv1=v1;iv1>=0;--iv1){
				for (int iv2=v2;iv2>=0;--iv2){
					for (int ik=k;ik>=0;--ik){
						int tmp=f[iv1][iv2][ik];
						if (iv1-data[in].a>=0) tmp=max(tmp,f[iv1-data[in].a][iv2][ik]+data[in].val);
						if (iv2-data[in].b>=0) tmp=max(tmp,f[iv1][iv2-data[in].b][ik]+data[in].val);
						if (ik-1>=0) tmp=max(tmp,f[iv1][iv2][ik-1]+data[in].val);
						f[iv1][iv2][ik]=tmp;
					}
				}
			}
		}
		cout<<f[v1][v2][k]<<endl;
	}
	return 0;
}
			
			
	