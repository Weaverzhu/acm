#include<bits/stdc++.h>
using namespace std;
int n,cnt[5];
char mov[105];
int main()
{
    cin>>n;
    scanf("%s",mov+1);
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
    {
        if(mov[i]=='U') cnt[1]++;
        else if(mov[i]=='D') cnt[2]++;
        else if(mov[i]=='L') cnt[3]++;
        else if(mov[i]=='R') cnt[4]++;
    }
    int ans=2*min(cnt[1],cnt[2])+2*min(cnt[3],cnt[4]);
    cout<<ans<<endl;
}