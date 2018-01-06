#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn];
int n;
int main(){
	while(scanf("%d", &n) != -1){
		for (int i=0; i<n; ++i)
			scanf("%d", &a[i]);
		bool ismax, ismin;
		int cnt = 0;
		for (int i=1; i<n-1; ++i){
			ismax = false;
			ismin = false;
			if (a[i] > a[i-1] && a[i] > a[i+1]) ismax = true;
			if (a[i] < a[i-1] && a[i] < a[i+1]) ismin = true;
 			if (ismax || ismin) ++cnt;
 		}

 		cout << cnt << endl;
	}


	return 0;
}