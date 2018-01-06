#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100000+10;
int pre[maxn],next[maxn];
int n,m,command,reverse,now,kase,start;
long long ans=0;
void left(int a,int b){
	int pa,pb,na,nb;
	if (next[b]==a){
		pb=pre[b];na=next[a];
		next[a]=b;pre[b]=a;
		pre[a]=pb;next[b]=na;
		next[pb]=a;pre[na]=b;
		return;
	}
	
	pa=pre[a];pb=pre[b];na=next[a];nb=next[b];
	next[pb]=a;pre[b]=a;pre[a]=pb;next[a]=b;
	next[pa]=na;pre[na]=pa;
	return;
}
void swap(int a,int b){
	int pa,pb,na,nb;
	pa=pre[a];pb=pre[b];na=next[a];nb=next[b];
	pre[a]=pb;pre[b]=pa;next[a]=nb;next[b]=na;
	next[pa]=b;pre[na]=b;next[pb]=a;pre[nb]=a;
	return;
}
void shuchu(){
	int now=0;
	while(next[now]!=n+1){
		printf("%d ",next[now]);
		now=next[now];
	}
	printf("\n");
	return;
}
int main(){
	while(scanf("%d%d",&n,&m)==2){
		for (int i=0;i<=n+1;i++){
			pre[i]=i-1;next[i]=i+1;
		}
		pre[0]=0;next[n+1]=n+1;
		reverse=0;ans=0;
		// initialize
		for (int i=1;i<=m;i++){
			int a,b;
			scanf("%d",&command);
			if (command==1||command==2) command=(reverse+command)%2;
			switch (command){
				case 1: scanf("%d%d",&a,&b);if (next[a]!=b) left(a,b);
				break;
				case 0: scanf("%d%d",&a,&b);if (pre[a]!=b) left(a,next[b]);
				break;
				case 3: 
				    scanf("%d%d",&a,&b);
				    if (next[a]!=b&&next[b]!=a) swap(a,b);
				        else if (next[a]==b) left(b,a);
				        else if (next[b]==a) left(a,b);
				break;
				case 4: reverse=(reverse+1)%2;
				break;
			}
			//shuchu();
		}
		now=1;
		if (reverse){
			start=n+1;
			while(pre[start]!=0){
				start=pre[start];
				if (now%2) ans+=start;
				now++;
			}
		}
		else{
			start=0;
			while(next[start]!=n+1){
				start=next[start];
				if (now%2) ans+=start;
				now++;
			}
		}
		printf("Case %d: %lld\n",++kase,ans);
	}
	return 0;
}
				