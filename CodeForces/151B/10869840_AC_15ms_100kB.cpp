#include<bits/stdc++.h>
using namespace std;
int n;
void solve()
{
    string taxi[110],pizza[110],girl[110];
    int ataxi=0,apizza=0,agirl=0;
    int mtaxi=0,mpizza=0,mgirl=0;
    for (int i=1; i<=n; ++i)
    {
        int num;
        string nam;

        cin>>num>>nam;
        int npizza=0,ngirl=0,ntaxi=0;
        for (int j=1; j<=num; ++j)
        {
            string line;
            cin>>line;
            int phone[10];
            phone[1]=line[0]-'0';
            phone[2]=line[1]-'0';
            phone[3]=line[3]-'0';
            phone[4]=line[4]-'0';
            phone[5]=line[6]-'0';
            phone[6]=line[7]-'0';

            bool istaxi=true,ispizza=true;
            int top=phone[1];
            for (int k=1; k<=6; ++k)
            {
                if (phone[k]!=top&&istaxi) istaxi=false;
                if (k>=2&&(phone[k]>=phone[k-1])&&ispizza) ispizza=false;

            }
            if (istaxi) ++ntaxi;
            else if (ispizza) ++npizza;
                else ++ngirl;
        }
        if (ntaxi>mtaxi)
        {
            mtaxi=ntaxi;ataxi=0;
            taxi[++ataxi]=nam;
        }
        else if (ntaxi==mtaxi)
        {
            taxi[++ataxi]=nam;
        };
        if (ngirl>mgirl)
        {
            mgirl=ngirl;agirl=0;
            girl[++agirl]=nam;
        }
        else if (ngirl==mgirl)
        {
            girl[++agirl]=nam;
        };
        if (npizza>mpizza)
        {
            mpizza=npizza;apizza=0;
            pizza[++apizza]=nam;
        }
        else if (npizza==mpizza)
        {
            pizza[++apizza]=nam;
        };
    }
    printf("If you want to call a taxi, you should call: ");
    for (int i=1;i<ataxi;++i) cout<<taxi[i]<<", ";
    cout<<taxi[ataxi]<<".\n";
    printf("If you want to order a pizza, you should call: ");
    for (int i=1;i<apizza;++i) cout<<pizza[i]<<", ";
    cout<<pizza[apizza]<<".\n";
    printf("If you want to go to a cafe with a wonderful girl, you should call: ");
    for (int i=1;i<agirl;++i) cout<<girl[i]<<", ";
    cout<<girl[agirl]<<".\n";
}
int main()
{
    while(scanf("%d",&n)!=-1) solve();

    return 0;
}
