#include<stdio.h>
#include<string.h>
#define N 25

char s[N];
int cnt[26], ans[10];

void init(){
	memset(s, 0, sizeof(s));
	memset(cnt, 0, sizeof(cnt));
	memset(ans, 0, sizeof(ans));
}
int getI(char ch){return (int)(ch - 'A');}

int main(){
	

	int t;
	scanf("%d", &t);
	for (int kk=0; kk<t; ++kk){
		init();

		printf("case #%d:\n", kk);
		scanf("%s", s);
		int len = strlen(s);
		for (int i=0; i<len; ++i)
			cnt[getI(s[i])]++;
		

		ans[0] = cnt[getI('Z')]; cnt[getI('E')] -= ans[0]; cnt[getI('R')] -= ans[0]; cnt[getI('O')] -= ans[0];
		ans[2] = cnt[getI('W')]; cnt[getI('T')] -= ans[2]; cnt[getI('O')] -= ans[2];
 		ans[6] = cnt[getI('X')]; cnt[getI('S')] -= ans[6]; cnt[getI('I')] -= ans[6];
		ans[4] = cnt[getI('U')]; cnt[getI('F')] -= ans[4]; cnt[getI('O')] -= ans[4]; cnt[getI('R')] -= ans[4];
		ans[5] = cnt[getI('F')]; cnt[getI('I')] -= ans[5]; cnt[getI('E')] -= ans[5]; cnt[getI('V')] -= ans[5];
		ans[7] = cnt[getI('V')]; cnt[getI('S')] -= ans[7]; cnt[getI('N')] -= ans[7]; cnt[getI('E')] -= 2*ans[7];
		ans[1] = cnt[getI('O')]; cnt[getI('N')] -= ans[1]; cnt[getI('E')] -= ans[1];
		ans[8] = cnt[getI('G')]; cnt[getI('H')] -= ans[8]; cnt[getI('I')] -= ans[8]; cnt[getI('T')] -= ans[8]; cnt[getI('E')] -= ans[8];
		ans[3] = cnt[getI('H')]; cnt[getI('T')] -= cnt[3]; cnt[getI('R')] -= ans[3]; cnt[getI('E')] -= 2*ans[3];
		ans[9] = cnt[getI('I')];
		for (int i=0; i<=9; ++i){
			for (int j=0; j<ans[i]; ++j)
				printf("%c", i+'0');
		}
		puts("");
	}
	return 0;
}