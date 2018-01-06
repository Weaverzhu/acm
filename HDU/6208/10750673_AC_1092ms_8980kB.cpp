#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000+10;
int n,k;
int ran[MAXN+1],tmp[MAXN+1];
int la, lb;
int nex[MAXN];
char Tmp[MAXN];
string dat[MAXN];
bool comp_sa(int i, int j)
{
    if(ran[i] != ran[j])
        return ran[i] < ran[j];
    int ri = i+k <= n? ran[i+k] : -1;
    int rj = j+k <= n? ran[j+k] : -1;
    return ri < rj;
}

void calc_sa(string &S, int *sa)
{
    n = S.size();
    for(int i = 0; i <= n; i++)
    {
        sa[i] = i;
        ran[i] = i < n ? S[i] : -1;
    }

    for( k =1; k <= n; k *= 2)
    {
        sort(sa,sa+n+1,comp_sa);
        tmp[sa[0]] = 0;
        for(int i = 1; i <= n; i++)
        {
            tmp[sa[i]] = tmp[sa[i-1]] + (comp_sa(sa[i-1],sa[i]) ? 1: 0);
        }
        for(int i = 0; i <= n; i++)
        {
            ran[i] = tmp[i];
        }
    }
}

bool SuffixArrayMatch(string &S, int *sa, string T)
{
    int lhs = 0, rhs = S.size();
    while(rhs - lhs > 1)
    {
        int mid = (lhs + rhs)>>1;
        int res = S.compare(sa[mid],T.size(),T);
        if(res < 0)
            lhs = mid;
        else if(res == 0)
        {
            return true;
            lhs = mid;
        }
        else rhs = mid;
    }
    return false;
}
void solve()
{
    int nn,maxl=0,maxi;
    scanf("%d",&nn);
    for (int i=1;i<=nn;++i)
    {
        scanf("%s",Tmp);
        dat[i]=Tmp;
        int tl=dat[i].length();
        if (tl>maxl)
        {
            maxi=i;maxl=tl;
        }
    }
    string S = dat[maxi];
    int *sa = new int[S.size()+1];
    calc_sa(S,sa);
    bool suc=true;
    for (int i=nn;i>=1;--i)
        if (i!=maxi)
        {
            if (!SuffixArrayMatch(S,sa,dat[i]) && dat[i] != S)
            {
                if(S.find(dat[i])==string::npos)
                {
                    printf("No\n");
                    return;
                }
            }
        }
    delete [] sa;
     sa = NULL;
    cout<<S<<endl;
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}
