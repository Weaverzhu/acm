#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int dis[maxn];
int sum=0;
int main(){
    int n;
    scanf("%d",&n);
    string s;
    cin>>s;
    int ans=0;
    memset(dis,-1,sizeof(dis));
    for(int i=0;i<n;i++){
        if(s[i]=='1') sum++;
        else if(s[i]=='0') sum--;
        if(sum==0){
            ans=max(ans,i+1);
            continue;
        }
        if(dis[sum+100000]==-1){
            dis[sum+100000]=i;
        }else{
            ans=max(ans,i-dis[sum+100000]);
        }
    }
    printf("%d\n",ans);
	return 0;
}
