#include <iostream>  
#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
#include <queue>  
using namespace std;  
  
const int maxn=1111111;  
const int INF=0xfffffff;  
  
struct node{  
    int to;  
    int w;  
    int v;  
    int next;  
}a[maxn];  
  
int n,m,s,l;  
int dis[maxn],head[maxn],vis[maxn];  
int edge;  
queue<int>q;  
  
void inint()  
{  
    edge=0;  
    memset(head,-1,sizeof(head));  
}  
  
void addedge(int v,int u,int w)  
{  
    a[edge].v=v;  
    a[edge].to=u;  
    a[edge].w=w;  
    a[edge].next=head[v];  
    head[v]=edge++;  
}  
  
bool spfa(int s)  
{  
    int v,i;  
    while(!q.empty()) q.pop();  
    for(i=1;i<=n;i++)  
    dis[i]=(i==s?0:INF);  
    memset(vis,0,sizeof(vis));  
    vis[s]=1;  
    q.push(s);  
    while(!q.empty())  
    {  
        int tmp=q.front();  
        q.pop();  
        for(i=head[tmp];i!=-1;i=a[i].next)  
        {  
            if(dis[tmp]+a[i].w<dis[v=a[i].to])  
            {  
                dis[v]=dis[tmp]+a[i].w;  
                if(!vis[v])  
                {  
                    vis[v]=true;  
                    q.push(v);  
                }  
            }  
        }  
        vis[tmp]=false;  
    }  
    return true;  
}  
  
int main()  
{  
    while(scanf("%d%d%d",&n,&m,&s)!=EOF)  
    {  
        int i;  
        int v,u,w;  
        inint();  
        for(i=0;i<m;i++)  
        {  
            scanf("%d%d%d",&v,&u,&w);  
            addedge(v,u,w);  
            addedge(u,v,w);  
        }  
        scanf("%d",&l);  
        spfa(s);  
        int ans=0;  
        for(i=1;i<=n;i++)  
           if(dis[i]==l)  ans++;  
        //cout<<ans<<endl;  
        /*for(i=head[s];~i;i=a[i].next) 
        { 
            if(a[i].w>l) 
                ans++; 
        }*/  
        for(i=0;i<edge;i+=2)  
        {  
            v=a[i].v;  
            u=a[i].to;  
            w=a[i].w;  
            if((dis[v]<l)&&(l-dis[v]<w)&&(w-(l-dis[v])>l-dis[u]))  
                  ans++;  
            if((dis[u]<l)&&(l-dis[u]<w)&&(w-(l-dis[u])>l-dis[v]))  
                  ans++;  
            if((dis[v]<l)&&(dis[u]<l)&&(dis[u]+dis[v]+w==l*2))  
                  ans++;  
        }  
        cout<<ans<<endl;  
    }  
  
    return 0;  
}  