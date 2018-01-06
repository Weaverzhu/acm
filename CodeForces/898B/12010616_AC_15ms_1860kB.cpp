#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL extend_euclid(LL a, LL b, LL &x, LL &y){
    if (b == 0){
        x = 1; y = 0;
        return a;
    }
    LL n = extend_euclid(b, a%b, x, y);
    LL tmp = x;
    x = y; y = tmp - (LL)(a/b)*y;
    return n;
}
bool le(LL a, LL b, LL c, LL &x, LL &y){
    LL n = extend_euclid(a, b, x, y);
    if (c % n)
        return false;
    LL k = c/n;
    x *= k;
    y *= k;
}
LL gcd(LL a, LL b){
    while(b){
        LL c = a%b; a = b; b = c;
    }
    return a;
}
LL n, a, b;
int main(){
    cin >> n >> a >> b;
    LL x=0, y=0;
    le(a, b, n, x, y);
    if (n%gcd(a, b) == 0){
        if (x < 0){
            LL tmp;
            if((-x)%b) tmp = ((-x)/b+1)*b;
            else tmp = (-x);
            x += tmp;
            y -= tmp/b*a;
        }else if (y < 0){
            LL tmp;
            if ((-y)%a) tmp = ((-y)/a+1)*a;
            else tmp = (-y);
            y += tmp;
            x -= tmp/a*b;
        }
        if (x >= 0 && y >= 0){
            printf("YES\n");
            printf("%lld %lld\n", x, y);
        }else{
            printf("NO\n");
        }
    }else{
        printf("NO\n");
    }

    return 0;

}