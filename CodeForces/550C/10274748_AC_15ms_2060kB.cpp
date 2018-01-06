#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int n[1000];
int main(){
	string line;
	cin>>line;
	int leng=line.length();
	for (int i=0;i<leng;++i) n[i]=line[i]-'0';
	for (int i=0;i<leng;++i)
		for (int j=i+1;j<leng;++j)
			for (int k=j+1;k<leng;++k){
				int num=100*n[i]+10*n[j]+n[k];
				if (num%8==0){
					printf("YES\n%d\n",num);
					return 0;
				}
			}
	for (int i=0;i<leng;++i)
		for(int j=i+1;j<leng;++j){
			int num=10*n[i]+n[j];
			if (num%8==0){
				printf("YES\n%d\n",num);
				return 0;
			}
		}
	for (int i=0;i<leng;++i)
		if (n[i]%8==0){
			printf("YES\n%d\n",n[i]);
			return 0;
		}
	printf("NO\n");
	return 0;
}
			