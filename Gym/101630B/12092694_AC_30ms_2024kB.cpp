#include<bits/stdc++.h>
using namespace std;
int a, b, c;
int w, h;
bool check(int x[], int id){
	int w0, h0;
	if (x[0] == 3 && x[1] == 1 && x[2] == 2){
		id = id;
	}
	if (id == 1){
		w0 = x[0] + 2*x[1], h0 = 2*x[1] + 2*x[2];

	}else if (id == 2){
		w0 = x[0]+x[1]+x[2], h0 = 2*x[0] + 2*x[1];
	}else if (id == 3){
		w0 = 2*x[0] + x[1]; h0 = x[0]+x[1]+2*x[2];
	}else if (id == 4){
		w0 = x[0]+x[1]+x[2]; h0 = 2*x[0]+x[1]+x[2];
	}else if (id == 5){
		w0 = 3*x[2]+x[1]+x[0]; h0 = x[1]+x[0];
	}
	if (w0 <= w && h0 <= h)
		return true;
	if (w0 <= h && h0 <= w)
		return true;
	return false;

}

int main(){

	cin >> a >> b >> c >> w >> h;
	for (int i=1; i<=5; ++i){
		int x[3];
		x[0] = a, x[1] = b, x[2] = c;
		if (check(x, i)){
			printf("Yes\n");
			return 0;
		}
		x[0] = a, x[1] = c, x[2] = b;
		if (check(x, i)){
			printf("Yes\n");
			return 0;
		}
		x[0] = b, x[1] = a, x[2] = c;
		if (check(x, i)){
			printf("Yes\n");
			return 0;
		}
		x[0] = b, x[1] = c, x[2] = a;
		if (check(x, i)){
			printf("Yes\n");
			return 0;
		}
		x[0] = c, x[1] = b, x[2] = a;
		if (check(x, i)){
			printf("Yes\n");
			return 0;
		}
		x[0] = c, x[1] = a, x[2] = b;
		if (check(x, i)){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");


	return 0;
}
