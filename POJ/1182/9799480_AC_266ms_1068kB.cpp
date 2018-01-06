#include<iostream>
#include<cstdio>
using namespace std;
int f[50005],d[50005],n,k,d1,x,y,ans;
int find(int x)//寻找祖先的函数
{
    if(x!=f[x])
    {
        int xx=f[x];
        f[x]=find(f[x]);
        d[x]=(d[x]+d[xx])%3;
    }
    return f[x];
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {f[i]=i;d[i]=0;}
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%d",&d1,&x,&y);
        if((d1==2&&x==y)||(x>n||y>n))
        {ans++;continue;}//弱智的假话
        if(d1==1)
        {
            if(find(x)==find(y))//x y在一个并查集中，找假话
            {if(d[x]!=d[y]) ans++;}//关于距离
            else//x y不在一个并查集中，合并并查集
            {
                d[f[x]]=(d[y]-d[x]+3)%3;//关于距离
                f[f[x]]=f[y];//关于父亲
            }
        }
        if(d1==2)
        {
            if(find(x)==find(y))//x y在一个并查集中，找假话
            {if(d[x]!=(d[y]+1)%3) ans++;}//关于距离
            else//x y不在一个并查集中，合并并查集
            {
                d[f[x]]=(d[y]-d[x]+4)%3;//关于距离
                f[f[x]]=f[y];//关于父亲
            }
        }
    }
    printf("%d\n",ans);
}