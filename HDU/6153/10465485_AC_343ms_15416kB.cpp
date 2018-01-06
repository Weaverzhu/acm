#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int lenga, lengb;
typedef long long ll;
const ll M=1000000007;
const int maxn=1e6+10;
ll s[maxn+10];
int pre[maxn];
char a[maxn],b[maxn];
ll ans;
void kmp(){
    memset(pre,0,sizeof(pre));
    for (int i=1;i<=lengb;++i) 
        if (b[i]==b[pre[i-1]]) pre[i]=pre[i-1]+1;
    int now=0,j=0;
    while(now+j-1<=lenga){
        
        if (a[now+j]==b[j]){
            j++;
            ans=(ans+j)%M;
            if (now+j-1>lenga) break;
        }
        else{
            ans=(ans+s[pre[j-1]]) % M;
            if (pre[j-1]==0) now++;else now+=j-pre[j-1];
            j=pre[j-1];
        }
        if (j>lengb){
            ans=(ans+s[pre[j-1]]) % M;
            if (pre[j-1]==0) now++;else now+=j-pre[j-1];
            j=pre[j-1];
            
        }
        if (now+j-1>lenga && now<lenga){
            ans=(ans+s[lenga-now])%M;
            break;
        }
    }
    return;
}
int main(){

    for (int i=1;i<=maxn;++i)
        s[i]=(s[i-1]+i) %M;
        
    int t;
    cin>>t;
    
    while(t--){
        ans=0;
        scanf("%s%s",a,b);
        lenga=strlen(a),lengb=strlen(b);
        char ch;
        for (int i=0;i<lenga/2;++i){
            ch=a[i];a[i]=a[lenga-i-1];a[lenga-i-1]=ch;
        }
        for (int i=0;i<lengb/2;++i){
            ch=b[i];b[i]=b[lengb-i-1];b[lengb-i-1]=ch;
        }
        lenga--;lengb--;
        kmp();
//        printf("%lld\n",ans);
        ans=ans%M;
        cout<<ans<<endl;
    }
    return 0;
}