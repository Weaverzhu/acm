#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int a,x,y;
	scanf("%d%d%d",&a,&x,&y);
	if (y%a==0){
		printf("-1\n");
		return 0;
	}
	double b;
	int n=y/a+1;
	if (n%2==1&&n>1) b=a;else b=a/2.0;
	if (abs(x)<b){
		if (n==1) {
			printf("1\n");
			return 0;
		}
		if (n==2) {
			printf("2\n");
			return 0;
		}
		if (n>2){
			int tmp;
			if (n%2) tmp=(n-1)/2*3;
			else tmp=n/2*3;
			if (n%2&&x>0){
				printf("%d\n",tmp+1);
				return 0;
			}
			if (n%2&&x<0){
				printf("%d\n",tmp);
				return 0;
			}
			if (n%2&&x==0){
				printf("-1\n");
				return 0;
			}
			if (n%2==0){
				printf("%d\n",tmp-1);
			}
		}
			
	}else printf("-1\n");
	return 0;
}
