#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <utility>
#include <string>
#include <cmath>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

/*
 *ios::sync_with_stdio(false);
 */

typedef long long ll;
typedef unsigned long long ull;
const int dir[5][2] = {0, 1, 0, -1, 1, 0, -1, 0, 0, 0};
const ll ll_inf = 0x7fffffff;
const int inf = 0x3f3f3f;
const int mod = 1000000;
const int Max = (int) 1e6;

ll arr[Max], n, k, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%lld %lld", &n, &k);
    if (k == 1) {
        ans = 1;
    }
    else if (k == 2) {
        ans = 1 + (n * (n - 1) / 2);
    }
    else if (k == 3) {
        ans = 1 + (n * (n - 1) * (n - 2)) / 3 + (n * (n - 1) / 2);
    }
    else if (k == 4) {
        ll temp = 1, temp2 = 1;
        for (int i = 0; i < 4; ++i) {
            temp *= ((n - i));
            temp2 *= (i + 1);
        }
        temp /= temp2;
        ans = 1 + (n * (n - 1) * (n - 2)) / 3 + (n * (n - 1) / 2) + temp * 9;
    }
    printf("%lld\n", ans);
    return 0;
}