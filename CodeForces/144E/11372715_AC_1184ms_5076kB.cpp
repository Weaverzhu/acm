#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> P;
vector<P> p[100000];
int n,m;
int a,b;
int main(void){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		int y=n-b;
		int x=a-1;
		p[y].push_back(P(x,i+1));
	}
	priority_queue<P,vector<P>,greater<P> > que;
	vector<int> ans;
	for(int i=0;i<n;i++){
		for(int j=0;j<(int)p[i].size();j++){
			que.push(P(p[i][j].first,p[i][j].second));
		}
		if(!que.empty()){
			while(!que.empty()&&que.top().first<i){
				que.pop();
			}
		}
		if(!que.empty()){
			ans.push_back(que.top().second);
			que.pop();
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
	return 0;
}