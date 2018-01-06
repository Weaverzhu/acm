#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
int n;
const int N = 60005;
int f[N], ans[N], sz;
const int INF = 0x3f3f3f3f;
set<int> S;
set<int>::iterator it;
int main(){
    int n;
    cin >> n;
    int sz, s, t, now;
    if (n%4==0 || n%4 == 3){
        printf("0\n");
        sz = 0, s, t, now = n/4;
        if (n%4 == 3){
            ans[sz++] = 1;
            ans[sz++] = 2;
            s = 4; t = n;
        }else{
            s = 1; t = n;
        }
        for (int i=0; i<now; ++i){
            ans[sz++] = s++;
            ans[sz++] = t--;
        }

    }else{
        printf("1\n");
        sz = 0, s, t, now=n/4;
        if (n%4 == 1){
            ans[sz++] = 1;
            s = 2; t = n;
        }else{
            ans[sz++] = 1;
            s = 3; t = n;
        }
        for (int i=0; i<now; ++i){
            ans[sz++] = s++;
            ans[sz++] = t--;
        }
    }
    printf("%d", sz);
    for (int i=0; i<sz; ++i)
        printf(" %d", ans[i], i == sz-1? '\n' : ' ');
    printf("\n");
    return 0;

}