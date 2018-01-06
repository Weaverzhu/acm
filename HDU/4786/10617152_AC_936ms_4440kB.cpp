#include<iostream>  
#include<algorithm>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
  
struct EdgeNode  
{  
    int u;  
    int v;  
    int w;  
}Edges[200100];  
  
int cmp(EdgeNode a, EdgeNode b)  
{  
    return a.w < b.w;  
}  
int Father[100100],Fibo[100100],j,id,N,M;  
  
int Fibonaci()  
{  
    Fibo[1] = 1;  
    Fibo[2] = 2;  
    for(int i = 3; Fibo[i] <= 100100; ++i)  
    {  
        Fibo[i] = Fibo[i-1] + Fibo[i-2];  
        if(Fibo[i] >= 100100)  
            return i;  
    }  
}  
  
int Find(int x)  
{  
    if(x != Father[x])  
        Father[x] = Find(Father[x]);  
    return Father[x];  
}  
  
int Kruskal1()  
{  
    for(int i = 0; i <= N; ++i)  
        Father[i] = i;  
    int Num = 0,Sum = 0;  
    for(int i = 0; i < id; ++i)  
    {  
        int u = Find(Edges[i].u);  
        int v = Find(Edges[i].v);  
        if(u != v)  
        {  
            Father[u] = v;  
            Num++;  
            Sum += Edges[i].w;  
        }  
        if(Num == N-1)  
            break;  
    }  
    if(Num == N-1)  
        return Sum;  
    else  
        return 0;  
}  
  
int Kruskal2()  
{  
    for(int i = 0; i <= N; ++i)  
        Father[i] = i;  
    int Num = 0,Sum = 0;  
    for(int i = id-1; i >= 0; --i)  
    {  
        int u = Find(Edges[i].u);  
        int v = Find(Edges[i].v);  
        if(u != v)  
        {  
            Father[u] = v;  
            Num++;  
            Sum += Edges[i].w;  
        }  
        if(Num == N-1)  
            break;  
    }  
    if(Num == N-1)  
        return Sum;  
    else  
        return 0;  
}  
int main()  
{  
    int T,kase = 0,u,v,w;  
    j = Fibonaci();  
    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%d%d",&N,&M);  
        id = 0;  
        for(int i = 0; i <= N; ++i)  
            Father[i] = i;  
        for(int i = 0; i < M; ++i)  
        {  
            scanf("%d%d%d",&u,&v,&w);  
            Edges[id].u = u;  
            Edges[id].v = v;  
            Edges[id++].w = w;  
            Edges[id].u = v;  
            Edges[id].v = u;  
            Edges[id++].w = w;  
        }  
        sort(Edges, Edges+id, cmp);  
        int Num1 = Kruskal1();  
        int Num2 = Kruskal2();  
        bool flag = 0;  
        for(int i = Num1; i <= Num2; ++i)  
        {  
            if(flag)  
                break;  
            for(int k = 1; k < j; ++k)  
            {  
                if(i == Fibo[k])  
                {  
                    flag = 1;  
                    break;  
                }  
            }  
        }  
        if(flag)  
            printf("Case #%d: Yes\n",++kase);  
        else  
            printf("Case #%d: No\n",++kase);  
    }  
  
    return 0;  
} 