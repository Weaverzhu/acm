#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5, M = 1e9+7;

struct node
{
	int ret[N];
	int alpha, len, num;

	bool operator < (node b){
		if (len != b.len) return len > b.len;
		for (int i=len-1; i>=0; --i){
			if (ret[i] != b.ret[i]) return ret[i] > b.ret[i];
		}
		return true;
	}
} dat[26];
bool cmp(int a, int b){
    if (dat[a].len != dat[b].len) return dat[a].len > dat[b].len;
    for (int i=dat[a].len-1; i>=0; --i){
        if (dat[a].ret[i] != dat[b].ret[i]) return dat[a].ret[i] > dat[b].ret[i];
    }
    return false;
}
int n, kk=1;
char s[N];
long long len[N+100];
int id[26];
int vis[26];
int main(){
//	freopen("in.txt", "r", stdin);

	len[0] = 1;
	for (int i=1; i<=100010; ++i){
		len[i] = (len[i-1]*26) % M;
	}
	while(scanf("%d", &n)!=-1){
		printf("Case #%d: ", kk++);
		memset(dat, 0, sizeof(dat));
		memset(vis, 0, sizeof(vis));
		for (int i=0; i<26; ++i){
			dat[i].alpha = i;
			id[i] = i;
			dat[i].len = 1;
		}
		for (int i=0; i<n; ++i){
			scanf("%s", s);
			int lens = strlen(s);
			vis[s[0]-'a'] = 1;
			int pos = 0;
			for (int i=lens-1; i>=0; --i){
				int now = s[i] - 'a';
				++dat[now].ret[pos++];
				if (pos > dat[now].len) dat[now].len = pos;
			}
		}
//		puts("fuck");
		for (int i=0; i<26; ++i){
			int jin = 0;
			for (int j=0; j<dat[i].len; ++j){
				dat[i].ret[j] += jin;
				jin = dat[i].ret[j] / 26;
				dat[i].ret[j] = dat[i].ret[j] % 26;
			}
			while(jin){
				dat[i].ret[dat[i].len++] = jin%26;
				jin /= 26;
			}
		}
//		puts("fuck");

		sort(id, id+26, cmp);
//		puts("fuck");

		for (int i=0; i<26; ++i){
			dat[id[i]].num = -1;
		}
		for (int i=25; i>=0; --i)
        if (!vis[id[i]]){
            dat[id[i]].num = 0;
            break;
        }
        int now = 1;
        for (int i=25; i>=0; --i){
            if (dat[id[i]].num == -1)
                dat[id[i]].num = now++;
        }
		long long ans = 0;

		for (int i=0; i<26; ++i){
			for (int j=0; j<dat[id[i]].len; ++j){
				ans = (ans + 1LL*dat[id[i]].num*dat[id[i]].ret[j]*len[j]%M) % M;
			}
		}
		cout << ans << endl;
	}



	return 0;
}
