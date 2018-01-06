#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX_SIZE = 1e5+10;
char text[MAX_SIZE];
int main()
{

    char a = 0;
    char b = 0;
    int K;
    int ans = 0;
    gets(text);
    int lent = strlen(text);

    scanf("%d\n",&K);
    for(int k = 0 ; k < K ; k++)
    {
        cin >> a;
        cin >> b;
       for(int i = 0 ; i < lent ; i++)
       {
           int left = 0 ,right = 0;
           while( text[i] == a || text[i] == b )
           {
               if( text[i] == a )
                    left++;
               if( text[i] == b )
                    right++;
               i++;
           }
           ans += min(left,right);
       }
    }
    printf("%d\n",ans);
    return 0;
}
