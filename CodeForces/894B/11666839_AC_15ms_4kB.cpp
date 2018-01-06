#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const LL M = 1e9+7;
LL pmd(LL a, LL b){
	// cout << a << " " << b << endl;
	// a = a % M; b = b % M;
	// cout << a << " " << b << endl;
	LL res = 1;
	while(b){
		if (b%2) res = res * a % M;
		a = a * a % M;
		// cout << a << endl;
		b = b / 2;
	}
	return res;
}
int main(){
	LL a, b, k;
	cin >> a >> b >> k;
	LL kk;
	if (a > b){
		kk = a; a = b; b = kk;
	}
	// cout << (a-1)%M*(b-1)%M <<  endl;
	LL tmp = pmd(2, b-1)%M;
	// cout << tmp << endl;
	if ((a+b)%2 && k==-1){
		cout << 0 << endl;
	}
	else cout << pmd(pmd(2, b-1)%M, a-1) << endl;
	return 0;
}