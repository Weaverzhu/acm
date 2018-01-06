#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

int a[2000000],b[2000000],c[2000000],btop,ans[2000000],m[2000000],anst;

int main(){
	for (int i=1;i<=600&&(i*(i+1)/2)<=125250;++i){
		m[i*(i+1)/2]=i;
	}
//	cout<<m[125250]<<endl;
	int n;
	while(scanf("%d",&n)!=-1){
		if (n==2){
			int tmp;
			cout<<1<<endl;
			scanf("%d",&tmp);
			scanf("%d",&tmp);
			cout<<tmp<<endl;
			continue;
		}
		if (n<2){
			int tmp;
			for (int i=1;i<=n;++i) scanf("%d",&tmp);
			cout<<0<<endl;
			continue;
		}
		int x=m[n];
		printf("%d\n",x);
		for (int i=1;i<=n;++i) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		btop=0;
		int open=0;
		while(open<n){
			++open;
			b[++btop]=a[open];
			int cl=open;
			while(a[open]==a[cl])++cl;
			c[btop]=cl-open;
			open=cl-1;
		}
		open=1;anst=0;
		while(anst<=x&&open<=btop){
			int a1,a2;
			while(c[open]==0&&open<=btop)++open;
			ans[++anst]=b[open];--c[open];a1=b[open];
			if (anst==x) break;
			int tmp=open,target;
			for (int i=1;i<=anst-1;++i){
				target=a1+ans[i];
				while(b[tmp]!=target)++tmp;
				--c[tmp];
			}
			while(c[open]==0&&open<=btop)++open;
			ans[++anst]=b[open];--c[open];a2=b[open];
			if (anst==x) break;
			
			
			tmp=open;
			for (int i=1;i<=anst-2;++i){
				target=a2+ans[i];
				while(b[tmp]!=target)++tmp;
				--c[tmp];
			}
			while(b[tmp]!=a1+a2)++tmp;
			--c[tmp];
		}
			
		
		for (int i=1;i<anst;++i) printf("%d ",ans[i]);
		printf("%d\n",ans[anst]);
	}
		
	
	return 0;
}