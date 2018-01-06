#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define maxn 100010
#define LL long long 
const LL INF=1e15;
int c[maxn];
string str[maxn][2];
LL dp[maxn][2];

string reverse(string s)
{
	string res=s;
	int i,len=res.length();
	for(i=0;i<len/2;++i)
		swap(res[i],res[len-1-i]);
	return res;
}

int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;++i)
			scanf("%d",&c[i]);
		for(i=0;i<n;++i)
		{
			cin>>str[i][0];
			str[i][1]=reverse(str[i][0]);
		}
		for(i=0;i<n;++i)
			dp[i][0]=dp[i][1]=INF;
		dp[0][0]=0; dp[0][1]=c[0];
		for(i=1;i<n;++i)
		{
			if(str[i][0]>=str[i-1][0])
				dp[i][0]=dp[i-1][0];
			if(str[i][1]>=str[i-1][0])
				dp[i][1]=dp[i-1][0]+c[i];
			if(str[i][0]>=str[i-1][1])
				dp[i][0]=min(dp[i][0],dp[i-1][1]);
			if(str[i][1]>=str[i-1][1])
				dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
			if(dp[i][1]==INF&&dp[i][0]==INF)
				break;
		}
		if(i==n)
			printf("%I64d\n",min(dp[n-1][0],dp[n-1][1]));
		else
			printf("-1\n");
	}
	return 0;
}