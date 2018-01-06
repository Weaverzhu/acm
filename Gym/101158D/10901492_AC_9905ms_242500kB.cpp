#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
set<ull> ss;
ll a[4100][30],b[4100][30];
char sa[4100],sb[4100];
int la,lb;
bool check(int n)
{
	for (int i=0;i+n-1<lb;++i)
	{
		ull f=2333;
		for (int j=0;j<26;++j) f+=(f<<4)+b[i+n][j]-b[i][j];
		if (ss.count(f)) return true;
	}
	return false;
}
int main()
{
     bool suc=false;
    scanf("%s%s",sa,sb);
    la=strlen(sa);lb=strlen(sb);
    int tl=min(la,lb);
    int mid;
    for (int i=0;i<la;++i)
    {
    	for (int j=0;j<26;++j)
    		a[i+1][j]=a[i][j];
    	a[i+1][sa[i]-'a']++;
	}
	for (int i=0;i<lb;++i)
    {
    	for (int j=0;j<26;++j)
    		b[i+1][j]=b[i][j];
    	b[i+1][sb[i]-'a']++;
	}
    for (int i=0;i<la;++i)
    {
    	for (int j=i;j<la;++j)
    	{
    		ull f=2333;
    		for (int k=0;k<26;++k) f+=(f<<4)+a[j+1][k]-a[i][k];
			ss.insert(f); 
		}
	}
    for (int i=tl;i>=1;--i)
    {
    	if (check(i))
    	{
    		cout<<i<<endl;
    		return 0;
		}
	}
	cout<<0<<endl;
    return 0;
}