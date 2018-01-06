#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void mysort(char *v[], int L, int R);
/* PreCondition:
      v points to an array of char*,
      L,R are indexes of the array to be sorted
   PostCondition:
      sort v with the ascending order of strings
      pointed by elements of the array pointed by v
*/

#define MAXLINES 5000
char *lineptr[MAXLINES];

void readlines(char *lineptr[], int nlines);

void writelines(char *lineptr[], int nlines);
int len[MAXLINES];
int main() {
    int nlines;
    scanf("%d", &nlines);
    readlines(lineptr, nlines);
/********** mysort is called here *************************/
    mysort(lineptr, 0, nlines - 1);
    puts("fuck");
/***********************************************************/
    writelines(lineptr, nlines);
    puts("fuck");
    return 0;
}
char tmp[1000005];
// int cmp1(void *a, void *b){
//   a = (char*)a; b=(char*)b;
//   int lena = strlen(a), lenb = strlen(b);
//   if (lena != lenb) return lena < lenb;
//   for (int i=0; i<lena; ++i){
//     if (a[i] != b[i]) return a[i] < b[i];
//   }
//   return 0;
// }
void readlines(char *lineptr[], int nlines){
  for (int i=0; i<nlines; ++i){
    scanf("%s", lineptr[i]=tmp);
    // printf("%s", lineptr[i]);
  }


}
void writelines(char *lineptr[], int nlines){
  for (int i=0; i<nlines; ++i){
    printf("%s\n", lineptr[i]);
  }

}
int cmp(const void *a, const void *b){
  char *pa=*(char **)a,*pb=*(char **)b;
  int x=int(strlen(pa)-strlen(pb));
  return x ? x : strcmp(pa,pb);
}
void mysort(char *v[], int L, int R){
  qsort(lineptr, R-L+1, sizeof(char*), cmp);
}