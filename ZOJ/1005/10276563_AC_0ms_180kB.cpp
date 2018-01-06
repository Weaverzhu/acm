#include<cstdio>  
#include<cstring>  
#include<algorithm>  
  
int ca,cb,n;  
int main() {  
    while(scanf("%d%d%d",&ca,&cb,&n) != EOF) {  
        if(cb == n) {  
            printf("fill B\nsuccess\n");  
            continue;  
        }  
        int i;  
        for(i = 2 ; ; i++) {  
            if((ca * i ) % cb == n)  
                break;  
        }  
        int carry = 0;  
        printf("fill A\npour A B\n");  
        carry = ca;  
        for(int j = 1 ; j < i ; j++) {  
            printf("fill A\npour A B\n");  
            carry += ca;  
            if(carry > cb) {  
                printf("empty B\npour A B\n");  
                carry %= cb;  
            }  
        }  
        printf("success\n");  
  
    }  
    return 0;  
}  