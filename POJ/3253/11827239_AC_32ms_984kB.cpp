#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 20005;
int a[N], n;
priority_queue<int, vector<int>, greater<int> > pq;

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", &a[i]), pq.push(a[i]);
	long long ans = 0;
	while(!pq.empty()){
		int a = pq.top(), b;
		pq.pop(); 
		if (!pq.empty()) b = pq.top();
		else {
			break;
		}
		ans += a+b;
		// cout << a << " " << b << endl;
		pq.pop();
		pq.push(a+b);
	}
	cout << ans << endl;

	return 0;
}