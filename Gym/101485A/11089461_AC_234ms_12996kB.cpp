#include<bits/stdc++.h>
using namespace std;  
const int MAXM=300010;  
const int bit=4;  
const long long INF=0x3f3f3f3f3f3f3f3f;  
const int maxm=60*30;  
const long long MOD=998244353;  
struct person  
{  
    int a,s,ed;  
};  
  
int n,m;  
struct person p[MAXM];  
  
bool cmp(person p1,person p2)  
{  
    return p1.a<p2.a;  
}  
int main()  
{  
    while( scanf("%d%d",&n,&m)!=EOF)  
    {  
    for (int i=0;i<n;i++)  
        scanf("%d%d",&p[i].a,&p[i].s),p[i].ed=p[i].a+p[i].s;  
    sort(p,p+n,cmp);  
    multiset<int > st;  
    multiset<int >::iterator it;  
    st.clear();  
    int ans=0;  
    for (int i=0;i<n;i++)  
    {  
        int tmp=p[i].a-m;  
        int ed=p[i].ed;  
        if (st.size()==0)  
        {  
            st.insert(ed);  
            ans++;  
            continue;  
        }  
        it=st.lower_bound(tmp);  
        if (it==st.end())  
        {  
            st.insert(ed);  
            ans++;  
        }  
        else  
        {  
            if ((*it)>p[i].a)  
            {  
                st.insert(ed);  
                ans++;  
            }  
            else  
            {  
                st.erase(it);  
                st.insert(ed);  
            }  
        }  
        //cout<<ans<<endl;  
    }  
    ans=n-ans;  
    printf("%d\n",ans);  
    }  
    return 0;  
}  