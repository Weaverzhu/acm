#include<bits/stdc++.h>
using namespace std;
const int N = 200000;
bool p[N];
int n, k;
int main(){
	cin >> n >> k;
	// p[2] = true;
	int cnt = 0;
	memset(p, false, sizeof(p));
	for(int i=2; i<=n; ++i){
		if (!p[i]){
			++cnt;
			if (cnt == k){
				cout << i << endl;
				return 0;
			}
			// cout << cnt << " " << i << endl;
			
			for (int j=2*i; j<=n; j+=i){
				if (!p[j]) cnt++;
				if (cnt == k && !p[j]){
					cout << j << endl;
					return 0;
				}
				
				// cout << cnt << " " << j << endl;
				p[j] = true;	
			}
		}
	}
	
	return 0;
}