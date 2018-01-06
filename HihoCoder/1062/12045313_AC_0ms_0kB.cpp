#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

map<string, string> fa;
set<string> st;

int main()
{
    int n, m;
    while(cin>>n)
    {
        fa.clear();
        while(n--)
        {
            string s1, s2;
            cin>>s1>>s2;
            fa[s2] = s1;
        }
        cin>>m;
        while(m--)
        {
            string name1, name2;
            cin>>name1>>name2;
            st.clear();
            while(fa.find(name1)!=fa.end())
            {
                st.insert(name1);
                name1 = fa[name1];
            }
            st.insert(name1);
            int sz = st.size();
            bool flag = false;
            st.insert(name2);
            if(sz==st.size())
            {
                cout<<name2<<endl;
                flag = true;
                continue;
            }
            else
            {
                sz = st.size();
                while(fa.find(name2)!=fa.end())
                {
                    name2 = fa[name2];
                    st.insert(name2);
                    if(sz==st.size())
                    {
                        cout<<name2<<endl;
                        flag = true;
                        break;
                    }
                    else
                    {
                        sz = st.size();
                    }
                }
            }
            if(!flag) cout<<-1<<endl;
        }
    }

    return 0;
}