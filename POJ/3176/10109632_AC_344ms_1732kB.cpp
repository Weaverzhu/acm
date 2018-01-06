#include<iostream>
using namespace std;
const int maxn = 350+10;
int f[maxn][maxn],d[maxn][maxn];
int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; ++i){
		for (int j = 0; j <= i;++j) {
			cin >> d[i][j];
			f[i][j]=d[i][j];
		}
	}
	for (int i=0;i<n;++i)
		for(int j=0;j<=i;++j){
			if (f[i][j]+d[i+1][j]>f[i+1][j]) f[i+1][j]=f[i][j]+d[i+1][j];
			if (f[i][j]+d[i+1][j+1]>f[i+1][j+1]) f[i+1][j+1]=f[i][j]+d[i+1][j+1];
		}
	int max = 0;
	for (int i = 0; i < n; ++i)
		if (f[n-1][i]>max) max=f[n-1][i];
	cout << max << endl;
	return 0;
}