#include<iostream>
#include<set>
#include<cstring>
using namespace std;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
set<int> S;
int map[10][10];
int now, ans;
void dfs(int nx, int ny, int step);
int main(){
	for (int i = 1; i <= 5; ++i)
		for (int j = 1; j <= 5; ++j)
			cin >> map[i][j];
	for (int i = 1; i <= 5; ++i)
		for (int j = 1; j <= 5; ++j){
//			memset(map,0,sizeof(map));
			now = map[i][j];
			dfs(i, j, 1);
			
		}
		
			
	cout << ans << endl;
	return 0;
}
void check(){
	if (!S.count(now)){
		++ans;
		S.insert(now);
	}
	return;
}
void dfs(int nx, int ny, int step){
	int r;
	if (step == 6) {check();return;}
	for (int r = 0; r < 4; ++r){
		int tx = nx + dx[r], ty = ny + dy[r];
		if (tx >= 1 && tx <= 5 && ty >= 1 && ty <= 5){
			now *= 10;
			now = now + map[tx][ty];
			dfs(tx, ty, step + 1);	
			now = (now - map[tx][ty]) / 10;
		}
	}
	return;
}
			
	