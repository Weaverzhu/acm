#include<bits/stdc++.h>
using namespace std;

vector<int> r1, r2, r3;
int m, k;
void solve()
{
    r1.clear(); r2.clear(); r3.clear();
	scanf("%d%d", &m, &k);
	int n, tmp;
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
	{
		scanf("%d", &tmp);
		r1.push_back(tmp);
	}
	sort(r1.begin(), r1.end());
	if (r1.size() > k) r1.resize(k);
	for (int i=2; i<=m; ++i)
	{
		scanf("%d", &n);
		r3.clear();

		for (int j=1; j<=n; ++j)
		{
			int tmp;
			scanf("%d", &tmp);
			r3.push_back(tmp);
			sort(r3.begin(), r3.end());

		}
		r2.clear();
//		printf("r1= ");
//		for (int j=0; j<r1.size()-1; ++j) printf("%d ",r1[j]); printf("%d\nr3= ",r1[r1.size()-1]);
//		for (int j=0; j<r3.size()-1; ++j) printf("%d ",r3[j]); printf("%d\nr2= ",r3[r3.size()-1]);
		for (int j=0; j<min(n, k); ++j)
			for (int k=0; k<r1.size(); ++k)
				r2.push_back(r1[k] + r3[j]);
		sort(r2.begin(), r2.end());
		if (r2.size()>k) r2.resize(k);
//		for (int j=0; j<r2.size(); ++j) printf("%d ", r2[j]); printf("%d\n", r2[r2.size()-1]);
		r1.clear();
		for (int j=1; j<=r2.size(); ++j) r1.push_back(r2[j-1]);
	}
	for (int i=0; i<k-1; ++i) printf("%d ", r1[i]);
	printf("%d\n", r1[k-1]);
}

int main()
{

	int t;
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}
