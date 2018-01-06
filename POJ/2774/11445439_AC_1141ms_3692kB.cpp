#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
char s1[N], s2[N];
const int MOD = 1e9+7;
typedef unsigned long long ull;
ull h1[N], h2[N], poww[N], a[N];
inline ull getHash(ull h[], int i, int j){
	return h[j]-h[i]*poww[j-i];
}
int len1, len2;
bool suc(int mid){
	// int b[100], cnt2=0;
	int cnt = 0;
	for (int i=mid; i<=len1; ++i){
		a[cnt++] = getHash(h1, i-mid, i);
	}
	sort(a, a+cnt);
 	// if (mid == 1)
	// for (int i=0; i<cnt; ++i) printf("%d ", a[i]);
	// printf("\n=============\n");
	// printf("\n");

	for (int i=mid; i<=len2; ++i){
		ull tmp = getHash(h2, i-mid, i);
		// b[cnt2++] = tmp;
		if (binary_search(a, a+cnt, tmp))
			return true;
	}
	// if (mid == 1)
	// for (int i=0; i<cnt; ++i) printf("%d ", b[i]);
	return false;
}
void print_substr(int i, int j){
	printf("i-j's hash = %d\n", getHash(h1, i, j));
}
void debug1(){
	// for (int i=0; i<i-j)
	// cout << getHash(h1, 1, 1) << endl;
// 	for (int i=0; i<len1; ++i)
// 		print_substr(i, i);
	cout << getHash(h1, 0, 1) << endl;
	cout << getHash(h2, 0, 1) << endl;
}
const int su = 131;
int main(){
	while(~scanf("%s", s1)){
		scanf("%s", s2);
		poww[0] = 1;

		len1 = strlen(s1), len2 = strlen(s2);
		int maxl = max(len1, len2), minl = min(len1, len2);
		h1[0] = h2[0] = 0;
		for (int i=1; i<=maxl; ++i){
			poww[i] = poww[i-1]*su ;
		}
		for (int i=0; i<len1; ++i){
			h1[i+1] = (h1[i]*su+s1[i]) ;
		}
		for (int i=0; i<len2; ++i){
			h2[i+1] = (h2[i]*su+s2[i]);
		}
		// debug1();
		int l = 0, r = minl+1;
		while(l < r-1){
			int mid = (l+r)/2;
			// cout << mid << endl;
			if (suc(mid))
				l = mid;
			else r = mid;
		}
		cout << l << endl;
		return 0;
	}
}