#include<iostream>
using namespace std;
const long long m = 1e9;
const long long maxn = 1e6+10;
long long f[maxn];
int main(){
	int n;
	f[0]=1;
	cin >> n;
	for (int i =1;i<=n;++i){
		if(i%2)f[i]=f[i-1] %m;
		else f[i]=(f[i/2]+f[i-1])%m;
		
		
	}
	cout << f[n]%m << endl;
	return 0;
}