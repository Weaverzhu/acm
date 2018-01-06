#include <bits/stdc++.h> 
  #ifndef WIN32
 #define Auto "%lld"
 #else
 #define Auto "%I64d"
 #endif
 using namespace std;
 typedef bool boolean;
 const signed int inf = (signed)((1u << 31) - 1);
 const signed long long llf = (signed long long)((1ull << 61) - 1);
 const double eps = 1e-6;
 const int binary_limit = 128;
 #define smin(a, b) a = min(a, b)
 #define smax(a, b) a = max(a, b)
 #define max3(a, b, c) max(a, max(b, c))
 #define min3(a, b, c) min(a, min(b, c))
 template<typename T>
 inline boolean readInteger(T& u){
     char x;
     int aFlag = 1;
     while(!isdigit((x = getchar())) && x != '-' && x != -1);
     if(x == -1) {
         ungetc(x, stdin);    
         return false;
     }
     if(x == '-'){
         x = getchar();
         aFlag = -1;
     }
     for(u = x - '0'; isdigit((x = getchar())); u = (u << 1) + (u << 3) + x - '0');
     ungetc(x, stdin);
     u *= aFlag;
     return true;
 }
 
 int n, q, c;
 int xs[100005], ys[100005], ss[100005];
 int sum[105][105][11];
 
 inline void init() {
     scanf("%d%d%d", &n, &q, &c);
     for(int i = 1; i <= n; i++) {
         scanf("%d%d%d", xs + i, ys + i, ss + i);
     }
 }
 
 inline void getPreSum() {
     memset(sum, 0, sizeof(sum));
     for(int i = 1; i <= n; i++) {
         sum[xs[i]][ys[i]][ss[i]]++;
		      }
     for(int i = 1; i <= 100; i++) {
         for(int j = 1; j <= 100; j++) {
             for(int k = 0; k <= 10; k++)
                 sum[i][j][k] += sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j - 1][k];
         }
     }
 }
 
 inline int getAns(int x, int y, int t0) {
     int rt = 0;
     for(int i = 0; i <= 10; i++)
         rt += (sum[x][y][i]) * ((i + t0) % (c + 1));
     return rt;
 }
 
 inline void solve() {
     int t0, x0, y0, x1, y1;
     while(q--) {
         scanf("%d%d%d%d%d", &t0, &x0, &y0, &x1, &y1);
         printf("%d\n", getAns(x1, y1, t0) - getAns(x0 - 1, y1, t0) - getAns(x1, y0 - 1, t0) + getAns(x0 - 1, y0 - 1, t0));
     }
 }
 
 int main() {
     init();
     getPreSum();
     solve();
     return 0;
 }