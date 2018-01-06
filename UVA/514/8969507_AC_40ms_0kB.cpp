#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
using namespace std;
const int maxn=1010;
vector <int> rail;
int n;
void work(){
	int m,target[maxn];
	scanf("%d",&target[0]);
	while(target[0]!=0){
		rail.resize(1);
		rail[0]=1;
		int now=0,top=1,flag=1;
		for (int i=1;i<n;i++) scanf("%d",&target[i]);
	
		while (now<=n-1){
		    if (top<target[now]){
			    while (top<target[now]){
				    top++;rail.push_back(top);
			    }
			    now++;rail.resize(rail.size()-1);
		    }
		    else if (rail[rail.size()-1]==target[now]){
		    	rail.resize(rail.size()-1);now++;
		    	
		    }
		    else{
		    	
		    	
		    	flag=0;
		    	break;
		    }
		}
		if (flag==1) printf("Yes"); else printf("No");
		scanf("%d",&target[0]);
		if (target[0]!=0) printf("\n"); 
	}

	scanf("%d",&n);
	if (n!=0)
	printf("\n\n");
	return;
}
		
		
int main(){
	scanf("%d",&n);
	while(n!=0){
		work();
		
	}
	printf("\n\n");
	return 0;
}