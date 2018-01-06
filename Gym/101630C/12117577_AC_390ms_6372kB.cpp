#include <bits/stdc++.h>  
using namespace std;  
struct jj  
{  
    int u,v,next;  
}w[100000],w1[100000];  
int h[50000],h1[50000],visw[100000],vis[50000],numw,numw1;  
void insert(int u,int v)  
{  
    w[numw].u=u;  
    w[numw].v=v;  
    w[numw].next=h[u];  
    h[u]=numw++;  
    w1[numw1].v=u;  
    w1[numw1].next=h1[v];  
    h1[v]=numw1++;  
}  
void dfs(int t)  
{  
    int i;  
    for(i=h[t];i!=-1;i=w[i].next)  
    {  
        if(vis[w[i].v]==0)  
        {  
            vis[w[i].v]=1;  
            visw[i]=1;  
            dfs(w[i].v);  
        }  
    }  
}  
void dfs1(int t)  
{  
    int i;  
    for(i=h1[t];i!=-1;i=w1[i].next)  
    {  
        if(vis[w1[i].v]==0)  
        {  
            vis[w1[i].v]=1;  
            visw[i]=1;  
            dfs1(w1[i].v);  
        }  
    }  
}  
int main()  
{  
    int t,x,y,i,i1,num,n,m;  
    scanf("%d",&t);  
    while(t--)  
    {  
        memset(h,-1,sizeof(h));  
        memset(h1,-1,sizeof(h1));  
        memset(visw,0,sizeof(visw));    //visw数组是记录哪些边被访问过，哪些没有被访问过  
        numw=0;  
        numw1=0;  
        scanf("%d %d",&n,&m);  
        for(i=1;m>=i;i++)  
        {  
            scanf("%d %d",&x,&y);  
            insert(x-1,y-1);  
        }  
        memset(vis,0,sizeof(vis));  
        dfs(0);  
        memset(vis,0,sizeof(vis));  
        dfs1(0);  
        num=m;  
        for(i=0;m>i&&num!=2*n;i++)  
        {  
            if(visw[i]==0)  
            {  
                num--;  
                printf("%d %d\n",w[i].u+1,w[i].v+1);  
            }  
        }  
    }  
    return 0;  
}  