#include<bits/stdc++.h>
using namespace std;
unsigned long long a, b, c, d, s, x = 4611686018427387904;
int main(){
	cin >> a;
	while(cin >> a >> b >> c >> d)
	{
		if (a == x && b == x && c == x && d == x)
			cout << "18446744073709551616\n";
		else{
			s = a+b+c+d;
			cout << s << endl;
		}
	}
	return 0;
}