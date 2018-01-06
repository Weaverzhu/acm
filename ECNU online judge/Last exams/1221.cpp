#include<stdio.h>
#include<stdlib.h>
#define N 100000
int isprime[N+5], p[N+5], psz;
int sum[N+5];
void getp(){
	psz = 0;
	for (int i=2; i<=N; ++i)
		isprime[i] = 1;
	for (int i=2; i<=N; ++i){
		if (isprime[i] == 1){
			p[psz++] = i;
			for (int j=2*i; j<=N; j+=i)
				isprime[j] = 0;
		}
	}
	sum[0] = sum[1] = 0;
	for (int i=2; i<=N; ++i)
		sum[i] = sum[i-1] + isprime[i];
}

struct node{
	int v, l, r;
} dat[N+5];

int cmp(const void *a, const void *b){
	struct node *pa, *pb;
	pa = (struct node*)a; pb = (struct node*)b;
	if (pa->v != pb->v) return pa->v > pb->v;
	if (pa->l != pb->l) return pa->l > pb->l;
	return pa->r > pb->r;
}

int main(){
	freopen("in.txt", "r", stdin);

	getp();
	int t;
	scanf("%d", &t);
	for (int kk=0; kk<t; ++kk){
		printf("case #%d:\n", kk);
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; ++i){
			int l, r;
			scanf("%d%d", &l, &r);
			dat[i] = (struct node){sum[r] - sum[l-1], l, r};
		}
		// for (int i=0; i<n; ++i){
		// 	printf("%d %d %d\n", dat[i].v, dat[i].l, dat[i].r);
		// }

		qsort(dat, n, sizeof(dat[0]), cmp);

		for (int i=0; i<n; ++i)
			printf("%d %d\n", dat[i].l, dat[i].r);
	}


	return 0;
}
