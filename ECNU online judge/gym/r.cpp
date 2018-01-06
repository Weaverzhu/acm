//#include "stdafx.h"//If the vc++6.0, with this line.
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define N 10      //字符串个数
#define LN 21     //限制字符串长度为20
int mycmp(const void *a,const void *b){//比较函数
    char *pa=*(char **)a,*pb=*(char **)b;
    int x=int(strlen(pa)-strlen(pb));//依长度比较
    return x ? x : strcmp(pa,pb);//长度相等时依大小比较
}
int main(void){
    int i=0,j=0;
    char *f[N],w[LN*N];//声明指针数组f和字符串总空间
    printf("Input %d string(s)(length<=%d)...\n",N,LN);
    while(i<N){//输入并将字符串首址赋给f[i]
        if(scanf(" %[1234567890]",f[i]=w+j)>0 && strlen(f[i])<LN)
            i++,j+=LN;
    else printf("Error, redo: Required length less than %d:",LN);
    }
    qsort(f,N,sizeof(char *),mycmp);//调用库函数对字符串指针排序
    for(i=0;i<N;printf("%s\n",f[i++]));//输出...
    return 0;
}