#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int dsum(int a)
{
    int now = 1e9, res = 0;
    while(now)
    {
        res += a/now % 10;
        now /= 10;
    }
    return res;
}

int main()
{
    int n;
    while(scanf("%d", &n) != -1)
    {
        vector<int> ou;
        for (int i=n; i>=max(n-100, 1); --i)
        {
            if (dsum(i)+i == n) ou.push_back(i);
        }
        printf("%d\n", ou.size());
        for (int i=ou.size()-1; i>=0; --i) printf("%d\n", ou[i]);

    }

}