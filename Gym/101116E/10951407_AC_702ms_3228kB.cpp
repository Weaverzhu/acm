#include<bits/stdc++.h>
using namespace std;
map <string, int> m;
int t[100010];
string a[10010];
string b[10010];
string c[10010];
vector<int> v[100010];
void dfs(int x)
{
    for(int i = 0; i < v[x].size(); i++)
        if(!t[v[x][i]])
        {
            t[v[x][i]] = 1;
            dfs(v[x][i]);
        }
}
int main()
{
    int tk,u,vv,mm,i,j,ll;
    cin>>tk;
    while(tk--)
    {
        cin>>u>>vv>>mm;
        ll = 0;
        m.clear();
        memset(t, 0, sizeof(t));
        for(i = 1; i <= u; i++)
        {
            cin>>a[i];
            if(m[a[i]] == 0)
            {
                m[a[i]] = ++ll;
                v[0].push_back(ll);
            }
        }
        for(i = 1; i <= vv; i++)
        {
            cin>>b[i];
            if(m[b[i]] == 0)
            {
                m[b[i]] = ++ll;
            }
        }
        for(i = 1; i <= mm; i++)
        {
            string s, t;
            cin>>s>>t;
            if(m[s] == 0)
            {
                m[s] = ++ll;
            }
            if(m[t] == 0)
            {
                m[t] = ++ll;
            }
            v[m[s]].push_back(m[t]);
        }
        dfs(0);
        int tt = 1;
        for(i = 0; i <= ll; i++) v[i].clear();
        ll = 0;
        for(i = 1; i <= vv; i++)
        {
            if(t[m[b[i]]])
            {
                c[++ll] = b[i];
            }
        }
        sort(c+1,c+ll+1);
        for(i = 1; i <ll; i++)
             cout<<c[i]<<' ';
        if(ll)cout<<c[ll]<<endl;
    }
    return 0;
}
