#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	int count = 0;
	int tmp;
	for (int i = 0; i < t; ++i){
		scanf("%d",&tmp);
		if (tmp > 35) ++count;
	}
	cout << t - count << endl;
	return 0;
}