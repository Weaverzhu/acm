#include<stdio.h>
#include<string.h>
const int N = 1e5+5;
char a[N][10];
char s[N];
int s1[N];
double s2[N];
int o1, o2;
int chdouble(char a[]){
	int len = strlen(a);
	for (int i=0; i<len; ++i){
		if (a[i] == '.') return 1;
	}
	return 0;
}
int chint(char a[]){
	int len = strlen(a);
	for (int i=0; i<len; ++i){
		if (a[i] == '.') return 0;
	}
	return 1;
}
double getd(char a[]){
	int len = strlen(a);
	int cnt = 0;
	for (int i=0; i<len; ++i)
		if (a[i] == '.'){
			cnt = len-i;
		}
	double x = 1, res = 0;
	for (int i=0; i<cnt; ++i)
		x /= 10;
	for (int i=0; i<len; ++i){
		if (a[i] != '.'){
			int now = a[i] - '0';
			res = res * 10 + x*now;
		}
	}
	return res;
}
double geti(char a[]){
	int len = strlen(a);
	double res = 1;
	for (int i=0; i<len; ++i)
		res = res * 10 + a[i] - '0';
	return res;
}

int main(){
	int n = 0;
	while(~scanf("%s", s)){
		for (int i=0; i<strlen(s); ++i)
			a[n++][i] = s[i];
	}
	for (int i=n-1; i>=0; --i){
		int suc = 0;
		if (strlen(a[i]) == 1 && a[i][0] == '+'){
			s1[o1++] = 0; suc = 1;
		}else if (strlen(a[i]) == 1 && a[i][0] == '-'){
			s1[o1++] = 1; suc = 1;
		}
		else if (strlen(a[i]) == 1 && a[i][0] == '*'){
			s1[o1++] = 2; suc = 1;
		}
		else if (strlen(a[i]) == 1 && a[i][0] == '/'){
			s1[o1++] = 3; suc = 1;
		}
		if (suc == 0){
			double x = 0;
			if (chdouble(a[i]))
				x = getd(a[i]);
			else if (chint(a[i]))
				x = geti(a[i]);

			s2[o2++] = x;
		}
		if (o1>=1 && o2>=2){
			double x1 = s2[--o2], x2 = s2[--o2];
			int op = s1[--o1];
			if (op == 0) s2[o2++] = x1+x2;
			else if (op == 1) s2[o2++] = x2-x1;
			else if (op == 2) s2[o2++] = x2*x1;
			else if (op == 3) s2[o2++] = x2/x1;
		}


	}
	printf("%lf\n", s2[0]);
	return 0;
}