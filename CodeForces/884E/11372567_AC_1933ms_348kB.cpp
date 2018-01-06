#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define N 16385
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,_,ans,fa[2*N],tmp[N];
bool a[2][N];char ch;
bool check(char ch){
	if(ch<='9'&&ch>='0') return 1;
	if(ch<='F'&&ch>='A') return 1;
	return 0;
}
int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
void Union(int x,int y){fa[Find(x)]=Find(y);}
void rua()
{
	for(int i=0;i<m/4;i++)
	  {
	  ch=getchar();while(!check(ch))ch=getchar();
	  int x=(ch>='A')?(ch-'A'+10):ch-'0';
	  for(int j=0;j<4;j++)a[_][4*i+3-j]=x&(1<<j),ans+=a[_][4*i+3-j];
	  }
	for(int i=0;i<m;i++)
	  {
	  if(!a[_][i])continue;
	  if(i && a[_][i-1] && a[_^1][i])
	    {
	    if(Find(_*m+i-1)==Find((_^1)*m+i))
	      Union(_*m+i,_*m+i-1),ans--;
	    else
	      Union(_*m+i,_*m+i-1),Union(_*m+i,(_^1)*m+i),ans-=2;
	    continue;
		}
	  if(i && a[_][i-1])Union(_*m+i,_*m+i-1),ans--;
	  if(a[_^1][i])Union(_*m+i,(_^1)*m+i),ans--;
	  }
	_^=1;
	for(int i=0;i<m;i++)
	  {
	  Find(m-_*m+i);
	  if(_*m<=fa[m-_*m+i] && fa[m-_*m+i]<_*m+m)
	    tmp[fa[m-_*m+i]%m]=i;
	  }
	for(int i=0;i<m;i++)
	  if(_*m<=fa[m-_*m+i] && fa[m-_*m+i]<_*m+m)
	    fa[m-_*m+i]=m-_*m+tmp[fa[m-_*m+i]%m];
	for(int i=0;i<m;i++)fa[_*m+i]=_*m+i;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<2*m;i++)fa[i]=i;
	for(int i=1;i<=n;i++)rua();
	printf("%d\n",ans);
	return 0;
}