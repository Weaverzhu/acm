#include<cstdio>
#include<cstdlib>
#include<stack>
#include<map>
#include<cstring>
using namespace std;
stack<int> ta,tb;
const int maxn=26+5;
int da[maxn],db[maxn];
char name[maxn][maxn],readin[10000];
int n,ok,error,ans,id;
map<char,int> nameid;

int isalpha(char a){
	int b=a;
	if (b>=65&&b<=90) return 1;else return 0;
	return 0;
}
void go(){
	int a,b,c,d;
	c=ta.top();d=tb.top();
	ta.pop();tb.pop();
	a=ta.top();b=tb.top();
	ta.pop();tb.pop();
	if (b==c){
		ans+=a*b*d;
		ta.push(a);tb.push(d);
	}
	else {error=1;return;};
	return;
}
void go2(){
	int a,b,c,d;
	ta.pop();tb.pop();
	c=ta.top();d=tb.top();ta.pop();tb.pop();
	if(!ta.empty()&&ta.top()<=0) ta.pop();
	if(!tb.empty()&&tb.top()<=0) tb.pop();
	if (!ta.empty()&&ta.top()>0){
	    a=ta.top();b=tb.top();
	    ta.push(c);tb.push(d);
	    
		go();return;
	}
	ta.push(c);tb.push(d);
	return;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s%d%d",&name[i],&da[i],&db[i]);
		nameid[name[i][0]]=i;
	}
	nameid['(']=n+1;nameid[')']=n+2;
	da[n+1]=-1;da[n+2]=-2; 
	char now;
	while(scanf("%s",readin)==1){
		ok=0;error=0;ans=0;
		while(!ta.empty()) ta.pop();
		while(!tb.empty()) tb.pop();
		for (int i=0;i<strlen(readin);i++){
			now=readin[i];
			id=nameid[now];
			ta.push(da[id]);tb.push(db[id]);
			
			if (isalpha(now)==1&&ok==1) go();
			    else if (isalpha(now)==1&&ok==0) ok=1;
			    else if (now=='(') ok=0;
			    else if (now==')') go2();
			if (error) break;
			
		}
		if (error) printf("error\n"); else printf("%d\n",ans);
	}
	return 0;
}
	 
		
	 
	