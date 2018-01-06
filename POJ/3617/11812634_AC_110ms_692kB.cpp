#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 4005;
char s1[N], s2[N];
int min(int a, int b){return a>b? b : a;}
bool cmp(char s1[], char s2[]){
	int len1 = strlen(s1), len2 = strlen(s2);
	int m;
	if (len1 > len2) m = 1;
	else m = 0;
	int mlen = min(len1, len2);
	for (int i=0; i<mlen; ++i){
		if (s1[i] < s2[i]) return true;
		else if (s2[i] < s1[i]) return false;
	}
	return m;
}
void pro(char s1[]){
	int len = strlen(s1);
	for (int i=0; i<len-1; ++i)
		s1[i] = s1[i+1];
	s1[len] = 0;
	return;
}
int n;
int main(){
	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));

	scanf("%d", &n); getchar();
	for (int i=0; i<n; ++i){
		char ch;
		scanf("%c", &ch); getchar();
		s1[i] = ch;
		s2[n-i-1] = ch;
	}
	for (int i=0; i<n; ++i){
		if (i%80 == 0 && i>0) printf("\n");
		if (cmp(s1, s2)){
			printf("%c", s1[0]);
			pro(s1);
		}else{
			printf("%c", s2[0]);
			pro(s2);
		}
	}
	if (n%80) printf("\n");
	return 0;
}