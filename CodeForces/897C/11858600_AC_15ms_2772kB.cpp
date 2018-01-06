#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const char f0[] = "What are you doing at the end of the world? Are you busy? Will you save us?",
fx[] = "What are you doing while sending \"\"? Are you busy? Will you send \"\"?",
f1[] = "What are you doing while sending \"What are you doing at the end of the world? Are you busy? Will you save us?\"? Are you busy? Will you send \"What are you doing at the end of the world? Are you busy? Will you save us?\"?";
typedef long long LL;
typedef unsigned long long ull;
ull a[100005];
int q, n;
int mm = 60;
LL k;
char findk(int n, LL k){
    if (n == 0) return f0[k-1];
    else{
        if (k >= 1 && k <= 34) return fx[k-1];
        if (k <= 34+a[n-1] || n > mm) return findk(n-1, k-34);
        if (k <=34+a[n-1]+32) return fx[k-a[n-1]-1];
        if (k <= 66+2*a[n-1]) return findk(n-1, k-66-a[n-1]);
        return fx[k-2*a[n-1]-1];
    }
}
int main(){
//    freopen("in.txt", "r", stdin);
    cin >> q;
//    q = 218;
    int l0 = strlen(f0), l1 = strlen(f1), lx = strlen(fx);
//    cout << l0 << endl;
    a[0] = l0;
    for (int i=1; i<=63; ++i){
        a[i] = a[i-1]*2 + lx;
    }
    mm = 60;
//    cout << a[60] << endl;
    for (int qq=0; qq<q; ++qq){
        cin >> n >> k;
//        n = 1; k = qq+1;
        if (n < 60 && k > a[n]) {printf("."); continue;}
        printf("%c", findk(n, k));
    }
    printf("\n");
    return 0;
}