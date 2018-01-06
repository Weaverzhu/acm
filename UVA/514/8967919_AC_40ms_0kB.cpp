#include<cstdio>
#include<stack>
using namespace std;
stack<int> s;
int main(){
	int n,a[1000],i,j=0,ok=1;
	while(scanf("%d",&n)==1&&n)
	{
		while(scanf("%d",&a[0])==1&&a[0])
		{
			for (i=1;i<n;i++) scanf("%d",&a[i]);
			i=1;
			while(j<n)
			{
				if (!s.empty()&&s.top()==a[j]){ s.pop();j++;}
				else if (i<n+1) s.push(i++);
				else {ok=0;break;}
			}
			printf("%s\n",ok?"Yes":"No");
			j=0;
			ok=1;
		}
		printf("\n");
	}
	return 0;
}