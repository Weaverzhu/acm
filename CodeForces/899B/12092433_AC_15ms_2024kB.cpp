#include<iostream>
#include<cstdio>
using namespace std;
const int y0[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int y1[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int N = 30;
int a[N];
int n;

bool y0y0y0(){
    for (int i=0; i<12; ++i){
        int st = i;
        bool suc = true;
        for (int j=0; j<n; ++j){
            int now = i+j;
            if (now<12) now = y0[now];
            else if (now>=12 && now<24) now = y0[now-12];
            else if (now>=24 && now<36) now = y0[now-24];
            if (now != a[j]){
                suc = false;
                break;
            }
        }
        if (suc) return true;
    }
    return false;
}
bool y1y0y0(){
    for (int i=0; i<12; ++i){
        int st = i;
        bool suc = true;
        for (int j=0; j<n; ++j){
            int now = i+j;
            if (now<12) now = y1[now];
            else if (now>=12 && now<24) now = y0[now-12];
            else if (now>=24 && now<36) now = y0[now-24];
            if (now != a[j]){
                suc = false;
                break;
            }
        }
        if (suc) return true;
    }
    return false;
}
bool y0y1y0(){
    for (int i=0; i<12; ++i){
        int st = i;
        bool suc = true;
        for (int j=0; j<n; ++j){
            int now = i+j;
            if (now<12) now = y0[now];
            else if (now>=12 && now<24) now = y1[now-12];
            else if (now>=24 && now<36) now = y0[now-24];
            if (now != a[j]){
                suc = false;
                break;
            }
        }
        if (suc) return true;
    }
    return false;
}
bool y0y0y1(){
    for (int i=0; i<12; ++i){
        int st = i;
        bool suc = true;
        for (int j=0; j<n; ++j){
            int now = i+j;
            if (now<12) now = y0[now];
            else if (now>=12 && now<24) now = y0[now-12];
            else if (now>=24 && now<36) now = y1[now-24];
            if (now != a[j]){
                suc = false;
                break;
            }
        }
        if (suc) return true;
    }
    return false;
}

int main(){
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
        scanf("%d", &a[i]);
    bool b1 = y0y0y0(),
    b2 = y1y0y0(),
    b3 = y0y1y0(),
    b4 = y0y0y1();

    if (b1||b2||b3||b4){
        printf("YES\n");
    }else printf("NO\n");

    return 0;
}