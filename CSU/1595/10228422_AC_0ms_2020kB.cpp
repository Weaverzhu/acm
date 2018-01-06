#include<iostream>  
#include<algorithm>  
#include <cstdio>  
const int INF =1e9;  
using namespace std;  
int t[50],cnt=0;  
struct node{  
    int a, b;  
}s[100+10];  
int cmp(node n1,node n2){  
    return n1.a<n2.a;  
}  
bool judge(node s){  
    for(int i=0;i<cnt;i++)  
      if(s.a>t[i]){  
        t[i]=s.b;  
        return true;  
      }  
    return false;  
}  
int main(){  
	int  kase;  
	cin>>kase;  
	while(kase--){  
	    int n,a,b;  
	    cnt=0;  
	    cin>>n;  
	    for(int i=0;i<n;i++){  
	        cin>>s[i].a>>s[i].b;  
	    }  
	    sort(s,s+n,cmp);  
	    int count = 1;  
	    t[cnt++]=s[0].b;  
	    for(int i=1;i<n;i++){  
	       if(s[i].a<=s[i-1].b)   
	           if(judge(s[i]))  
	            continue;   
	            else{  
	               count++;  
	               t[cnt++]=s[i].b;  
	            }  
	       else  
	          t[0]=s[i].b;   
	    }  
	    if(n==0) cout<<0<<endl;  
	    else  
	    cout<<count<<endl;  
	}  
	return 0;  
}  