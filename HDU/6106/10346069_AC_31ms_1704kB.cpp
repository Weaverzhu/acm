#include<iostream>
#include<cstdio>
using namespace std;
struct ban{
	int a,b,c,ab,bc,ac,abc;
};
const int maxn=100+10;
ban data[maxn];
void solve(){
	int n;
	scanf("%d",&n);
	int max=0;
	for (int i=1;i<=n;++i){
		int a,b,c,d,e,f,g;
		bool flag=true;
		int sum=0;
		scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
		data[i].abc=g;if(g<0) flag=false;
		data[i].ab=d-g;if (d-g<0) flag=false;
		data[i].bc=e-g;if (e-g<0) flag=false;
		data[i].ac=f-g;if (f-g<0) flag=false;
		data[i].a=a-data[i].ab-data[i].ac-data[i].abc;
		if (data[i].a<0) flag=false;
		data[i].b=b-data[i].ab-data[i].bc-data[i].abc;
		if (data[i].b<0) flag=false;
		data[i].c=c-data[i].ac-data[i].bc-data[i].abc;
		if (data[i].c<0) flag=false;
		if (flag){
			sum=data[i].a+data[i].b+data[i].c+data[i].ab+data[i].ac+data[i].bc+data[i].abc;
			if (sum>max) max=sum;
		}
	}
	cout<<max<<endl;
}
	
int main(){
	int t;
	scanf("%d",&t);
	for (int i=0;i<t;++i) solve();
	return 0;
}