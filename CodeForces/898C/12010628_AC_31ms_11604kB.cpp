#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int Magic = 131;
map<string, int> mp;
set<ull> has[25];
char nam[25][20];
char ans[25][10000][15];
string nums[25][10000];
int cnt[25], c0[25];
int n;
char str[15];
set<string> dic;
bool cmp(string a, string b){
    if (a.length() != b.length()) return a.length() > b.length();
    return a > b;
}
int main(){
//    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    int id = 0;
    for (int i=0; i<n; ++i){
        int x;
        string tname;
        cin >> tname >> x;
        int ii;
        if (!dic.count(tname)){
            mp[tname] = id; ii = id;
            int len = tname.length();
            for (int j=0; j<len; ++j)
                nam[id][j] = tname[j];
            dic.insert(tname);
            id++;
        }else{
            ii = mp[tname];
        }
        for (int j=0; j<x; ++j){
            scanf("%s", str); int len = strlen(str);
            nums[ii][c0[ii]].resize(len);
            for (int k=0; k<len; ++k)
                nums[ii][c0[ii]][k] = str[k];
            c0[ii]++;
        }
    }
    for (int i=0; i<id; ++i)
        sort(nums[i], nums[i]+c0[i], cmp);
//    for (int i=0; i<id; ++i){
//        printf("%s %d", nam[i], c0[i]);
//        for (int j=0; j<c0[i]; ++j)
//            cout << " " << nums[i][j];
//        printf("\n");
//    }
    for (int i=0; i<id; ++i){
        ull tmp = 0;
        for (int j=0; j<c0[i]; ++j){
            int len = nums[i][j].length();
            ull tmp = 0;
            for (int k=len-1; k>0; --k){
                tmp = tmp*Magic+nums[i][j][k];
                if (!has[i].count(tmp)) has[i].insert(tmp);
            }
            tmp = tmp*Magic + nums[i][j][0];
            if (!has[i].count(tmp)){
                for (int k=0; k<len; ++k)
                    ans[i][cnt[i]][k] = nums[i][j][k];
                ans[i][cnt[i]++][len] = 0;
                has[i].insert(tmp);
            }
        }
    }
    printf("%d\n", id);
    for (int i=0; i<id; ++i){
        printf("%s %d", nam[i], cnt[i]);
        for (int j=0; j<cnt[i]; ++j){
            printf(" %s", ans[i][j]);
        }
        printf("\n");
    }
}