#include<iostream>
#include<string>
using namespace std;
const int dx[8] = {1, -1, 0, 0, 1, -1, 1,  -1};
const int dy[8] = {1, 1, -1, 1, 0, 0, -1, -1 };
int map[200][200];
int ans = 0;
int row, col;
void dfs(int nx, int ny, int key);

int main(){
	
	scanf("%d%d",&row,&col);
	string line;
	for (int i = 0; i < row; ++i){
		cin >> line;
		for (int j = 0; j < col; ++j)
			if (line[j] == '.') map[i][j] = -1;
	}
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j){
			
			if (map[i][j] == 0) {
				map[i][j]= ++ ans;
				dfs(i, j, ans);
			}
		}
	cout << ans ;
	return 0;
}

void dfs(int nx, int ny, int key){
	for (int r = 0; r < 8; ++r){
		int rx = nx + dx[r], ry = ny + dy[r];
		
		if (rx>=0&&ry>=0&&rx<row&&ry<col&&map[rx][ry] == 0){
			
			map[rx][ry] = key;
			dfs(rx, ry, key);
			
		}
		
	}
	return;
}
	