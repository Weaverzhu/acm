#include<bits/stdc++.h>
using namespace std;
const double e = 2.718281828459;

int main(){
	int m;
	// cout << log(2) << endl;
	int kase=1;
	while(~scanf("%d", &m)){
		double ans = m * ((log(2)/log(10)));
		int Ans = ans;
		printf("Case #%d: ", kase++);
		cout << Ans << endl;
	}



	return 0;
}