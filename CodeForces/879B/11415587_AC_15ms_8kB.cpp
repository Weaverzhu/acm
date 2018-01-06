#include<bits/stdc++.h>
using namespace std;
const int maxn = 500+10;
int a[maxn], b[maxn], n;
long long k;
queue<int> Q;
int main(){
	while(~scanf("%d%I64d", &n, &k)){
		if (k >= n) k = n;
		while(!Q.empty()) Q.pop();
		for (int i=0; i<n; ++i){
			scanf("%d", &a[i]);
			Q.push(a[i]);
		}
		bool suc = false;
		int a = Q.front(); Q.pop();
		int b = Q.front(); Q.pop();
		if (a < b) swap(a, b);
		Q.push(b);
		while (!suc){
			suc = true; 
			for (int i=0; i<k-1; ++i){
				int tmp = Q.front(); Q.pop();
				if (tmp < a) Q.push(tmp);
				else{
					Q.push(a);
					a = tmp;
					suc = false;
					break;
				}
			}
		}
		cout << a << endl;
	}
	return 0;
}