#include<bits/stdc++.h>
using namespace std;


int tab[20][20];
int input[5];
int tmp[20];
const int maxn=1e5+10;
int ans[maxn];
void doit(int n,int m)
{
    for (int i=m;i>=1;--i)
    {
        tmp[i]=n%10;
        n/=10;
    }

}
bool che(int n)
{
    for (int i=1;i<=5;++i)
    {
        for (int j=0;j<=9;++j)
        {
            doit(n,5);
            if (tmp[i]!=j)
            {
                tmp[i]=j;
                tmp[0]=0;
                for (int k=1;k<=5;++k)tmp[k]=tab[tmp[k-1]][tmp[k]];
                if (tmp[5]==0) return true;
            }
        }

    }
    for (int i=1;i<=4;++i)
    {
        doit(n,5);
        if (tmp[i]!=tmp[i+1])
        {
            swap(tmp[i],tmp[i+1]);
            tmp[0]=0;
            for (int k=1;k<=5;++k)tmp[k]=tab[tmp[k-1]][tmp[k]];
            if (tmp[5]==0) return true;
        }

    }
    return false;
}
int main()
{

	for (int i=0;i<=9;++i)
		for (int j=0;j<=9;++j)
		{
			scanf("%d",&tab[i][j]);
		}
	for (int i=0;i<10000;++i)
    {
        memset(tmp,0,sizeof(tmp));
        doit(i,4);
        for (int k=1;k<=4;++k)tmp[k]=tab[tmp[k-1]][tmp[k]];
        ans[i]=i*10+tmp[4];
    }
    int res=0;
    for (int i=0;i<=9999;++i)
    {

        if (che(ans[i])) res++;
    }
    cout<<res<<endl;


	return 0;
}
