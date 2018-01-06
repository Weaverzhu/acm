#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, m, len;
char s[N];
typedef long long LL;

class bign{
public:
    int len, a[10000];
    bign(): len(0){
        memset(a, 0, sizeof(a));
    }
    void add(int b){
        a[0] += b;
        len = max(len, 1);
        int j = 0;
        for (int i=0; i<len; ++i){
            a[i] = a[i] + j;
            j = a[i] / 10;
            a[i] = a[i] % 10;
        }
        while(j){
            a[len++] = j % 10;
            j = j / 10;
        }
    }
    void add(const bign &b){
        int l = max(len, b.len);
        for(int i=0; i<l; ++i){
            a[i] = a[i] + b.a[i];
        }
        len = l;
        int j = 0;
        for (int i=0; i<len; ++i){
            a[i] += j;
            j = a[i] / 10;
            a[i] = a[i] % 10;
        }
        while(j){
            a[len++] = j % 10;
            j = j / 10;
        }
    }
    void muilt(int b){
        for (int i=0; i<len; ++i){
            a[i] = a[i] * b;
        }
        int j = 0;
        for (int i=0; i<len; ++i){
            a[i] += j;
            j = a[i] / 10;
            a[i] = a[i] % 10;
        }
        while(j){
            a[len++] = j % 10;
            j = j / 10;
        }
    }
    void pt(){
        for (int i=len-1; i>=0; --i)
            printf("%d", a[i]);
    }



}ans, cnt;

int main(){
    ans.add(0); cnt.add(1);
    scanf("%s", s);
    len = strlen(s);
    if (s[0] == 'P'){
        ans.add(1);
    }else if (s[0] == 'L'){
        ans.add(2);
    }else if (s[0] == 'R'){
        ans.add(3);
    }else if (s[0] == '*'){
        ans.add(6); cnt.add(2);
    }
    for (int i=1; i<len; ++i){
        if (s[i] == 'L'){
            ans.muilt(2);
        }else if (s[i] == 'R'){
            ans.muilt(2);
            ans.add(cnt);
        }else if (s[i] == '*'){
            ans.muilt(5);
            ans.add(cnt);
            cnt.muilt(3);
        }
    }
    ans.pt();
    puts("");
}
