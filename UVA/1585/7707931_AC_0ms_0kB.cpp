#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
char tmp[100];
int i,j,k,l,m,n;
void work();
void work()
{
  int i,j,k,l,m,n;
  scanf("%s",tmp);
  string a(tmp);
  int leng=a.length();
  i=0;int pre=1,ans=0;
  while(i<=leng-1)
  {
    if (a[i]=='O') 
    ans=ans+pre;
    if (a[i]=='O') pre++;
      else pre=1;
    i++;
  }
  printf("%d\n",ans);
  return;
}
int main()
{

  scanf("%d",&n);
  for (i=1;i<=n;i++) work();
  return 0;
}