#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
//const int maxn=50000;
//int p[maxn+10];
using namespace std;
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out1.txt","w",stdout);
//	cout<<sqrt(2147483647);
	ll t,n;
	
	
	
	cin>>t;
	for (int i=0;i<t;++i){
		cin>>n;
		printf("%d=",n);
		ll p=2;
		while(p*p<=n){
			while(n%p==0){
				printf("%d",p);
				n/=p;
				if (n!=1) printf("*");
			}
			p++;
		}
		if (n!=1)printf("%d\n",n);
		else printf("\n");
	}
	return 0;
}
	