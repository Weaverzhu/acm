#include <cstdio>  
#include <algorithm>  
#include <iostream>  
#include<vector>  
#include<cmath>  
#include<set>  
#include<cstring>  
#include<map>  
using namespace std;  
const int maxn = 1020;  
const int maxt = 100200;  
const int INF = 0x3f3f3f3f;  
const int mod = 1e9 + 7;  
const double pi = acos(-1.0);  
int n;  
int a[100010];  
map<int, int> ma;  
int main(){  
    long long k;  
    scanf("%d%I64d", &n, &k);  
    for(int i = 0; i < n; ++i){  
        scanf("%d", &a[i]);  
        ma[a[i]]++; //用map记下a[i]的个数  
    }  
    sort(a, a + n);  
    int p =(k - 1) / n;  
    p = a[p];  
    int kk = lower_bound(a, a + n, p) - a;  
    long long pp = k - (long long)kk * n;  
    long long y = ma[p]; // 所求数对的第一个数的个数  
    int t = unique(a, a + n) - a; // 去掉重复的数  
    long long cnt = 0;  
    int q;  
    for(int i = 0; i < t; ++i){ //从最小的开始加直到找到第k个，这里即第pp个。  
        long long x = ma[a[i]];  
        cnt += x * y;  
        if(cnt >= pp){q = a[i]; break;}  
    }  
    printf("%d %d\n", p, q);  
    return 0;  
}  
