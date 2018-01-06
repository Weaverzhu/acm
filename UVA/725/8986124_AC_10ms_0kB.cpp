#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,tmp;
void work(){
	int start=1234,a[20],vis[20],success=0;
	for (int i=start;i<56789;i++){
		tmp=n*i;int flag=1;
		memset(vis,0,sizeof(vis));
		if (tmp>98765) break;
		if (tmp<1234) continue;
		a[0]=i*n /10000;
		a[1]=i*n /1000 %10;
		a[2]=i*n /100 %10;
		a[3]=i*n /10 %10;
		a[4]=i*n  %10;
		a[5]=i / 10000;
		a[6]=i / 1000 %10;
		a[7]=i / 100 %10;
		a[8]=i / 10 %10;
		a[9]=i  %10;
		for (int j=0;j<10;j++)
		    vis[a[j]]=1;
		for (int j=0;j<10;j++)
		    if (vis[j]!=1){
		    	flag=0;break;
		    }
		if (flag==1){
			success=1;
			printf("%d / ",n*i);
			if (i<10000) printf("0");
			printf("%d = %d\n",i,n);
		}
	}
	if (success==0) printf("There are no solutions for %d.\n",n);
	scanf("%d",&n);
	if (n!=0)
	printf("\n");
	return;
}
int main(){
	scanf("%d",&n);
	while (n!=0){
		work();
		
	}

	return 0;
}