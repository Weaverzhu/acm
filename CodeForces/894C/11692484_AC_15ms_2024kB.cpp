#include <bits/stdc++.h>
using namespace std;
const int maxn=1000+5;
int inp[maxn];

int main(){
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)    scanf("%d",&inp[i]);
    bool can=true;
    for(int i=1;i<m;i++){
        if(inp[i]%inp[0]!=0)  can=false;
    }
    if(can){
        printf("%d\n",2*m);
        for(int i=0;i<m;i++){
            if(i!=0)    printf(" ");
            printf("%d %d",inp[0],inp[i]);
        }printf("\n");
    }
    else
        printf("-1\n");
    return 0;
}