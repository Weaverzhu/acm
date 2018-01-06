#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
int n,r;
struct node{
	int s,k,key;
};
node a[maxn];

inline int cmp(node a,node b){
	return a.key>b.key?1:0;
}

int main(){
	scanf("%d%d",&n,&r);
	for (int i=0;i<n;++i){
		scanf("%d%d",&a[i].s,&a[i].k);
		a[i].key=min(2*a[i].s,a[i].k)-min(a[i].s,a[i].k);
	}
	sort(a,a+n,cmp);
	for (int i=0;i<r;++i) a[i].s+=a[i].s;
	ll ans = 0;
	for (int i=0;i<n;++i) ans+=min(a[i].s,a[i].k);
	cout << ans << endl;
	return 0;
}