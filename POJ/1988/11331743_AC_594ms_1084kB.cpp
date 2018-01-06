#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 30005;
int n, fa[maxn], r[maxn], mx[maxn];
void init(){
	for (int i=1; i<maxn; ++i)
		fa[i] = i, r[i] = 0, mx[i] = 1;
}
int find(int x){
	int fx = fa[x];
	if (fa[x] != x){
		fx = find(fa[x]);
		r[x] += r[fa[x]];
	}
	return fa[x] = fx;
}
void U(int x, int y){
	int fx = find(x), fy = find(y);
	fa[fy] = fx;
	r[fy] += mx[fx];
	mx[fx] += mx[fy];
}
int main(){
	char op[3];
	int i, j;
	while(~scanf("%d", &n)){
		init();
		while(n--){
			scanf("%s", op);
			if (op[0] == 'C'){
				scanf("%d", &i);
				int f = find(i);
				printf("%d\n", mx[f]-r[i]-1);
			}else{
				scanf("%d%d", &i, &j);
				U(i, j);
			}
		}
	}
	return 0;
}
