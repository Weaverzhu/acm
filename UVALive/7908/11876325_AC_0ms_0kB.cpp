#include<bits/stdc++.h>
using namespace std;
int cnt;
int a[10];
int A, B, C, D;
void dfs(int now){
    if (now == 7){
        int aa=0, b=0, c=0, d=0;
        if (a[1] == 1) aa+=3;
        else if (a[1] == 2) aa+=1, b+=1;
        else if (a[1] == 3) b+=3;
        if (a[2] == 1) aa+=3;
        else if (a[2] == 2) aa+=1, c+=1;
        else if (a[2] == 3) c+=3;
        if (a[3] == 1) aa+=3;
        else if (a[3] == 2) aa+=1, d+=1;
        else if (a[3] == 3) d+=3;
        if (a[4] == 1) b+=3;
        else if (a[4] == 2) b+=1, c+=1;
        else if (a[4] == 3) c+=3;
        if (a[5] == 1) b+=3;
        else if (a[5] == 2) b+=1, d+=1;
        else if (a[5] == 3) d+=3;
        if (a[6] == 1) c+=3;
        else if (a[6] == 2) c+=1, d+=1;
        else if (a[6] == 3) d+=3;
        if (aa==A && b==B && c==C && d==D)++cnt;
        return;
    }
    for (int r=1; r<=3; ++r){
        a[now] = r;
        dfs(now+1);
    }
    return;
}
int main(){
    int t;
    cin >> t;
    for (int kk=1; kk<=t; ++kk){
        printf("Case #%d: ", kk);
        scanf("%d%d%d%d", &A, &B, &C, &D);
        cnt = 0;
        dfs(1);
        if (cnt == 0)
            printf("Wrong Scoreboard\n");
        else if (cnt == 1)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
