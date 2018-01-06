/***************************************************************/
/*                                                             */
/*  DON'T MODIFY main function ANYWAY!                         */
/*                                                             */
/***************************************************************/

#include <stdio.h>
#include <string.h>

int isRotation(char s1[],char s2[])
   /* PreCondition:  s1和s2是长度不超80的两个字符串
     PostCondition: s2可以是s1经过循环移动后得到时返回1，否则0
   */
{
    int len1 = strlen(s1), len2 = strlen(s2);
    if (len1 != len2) return 0;
    for (int i=0; i<len1; ++i)
        for (int j=0; j<len2; ++j)
            if (s1[i] == s2[j]){
                int suc = 1;
                for (int k=0; k<len1; ++k){
                    int i1 = (k+i)%len1, j1 = (k+j)%len1;
                    if (s1[i1] != s2[j1]) {suc = 0; break;}
                }

                if (suc) return 1;

            }

    //TODO: your function definition
    return 0;
}

/***************************************************************/
#define N 80
int main()
{
    char s[N+1],t[N+1];
    scanf("%s%s",s,t);

    //********** isRotation is called here *************
    if(isRotation(s,t)) printf("\"%s\" is a rotation of \"%s\"\n",s,t);
    else printf("\"%s\" is NOT a rotation of \"%s\"\n",s,t);
    //**************************************************

    return 0;
}
