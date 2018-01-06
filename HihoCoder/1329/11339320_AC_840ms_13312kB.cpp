#include<bits/stdc++.h>
using namespace std;
set<int> S;
char op[3];
int a, b, n;
set<int>::iterator it1, it2, it;
int main(){
	while(scanf("%d", &n) != -1){
		S.clear();
		for(int q=0; q<n; ++q){
			scanf("%s", op);
			if (op[0] == 'I')
				scanf("%d", &a), S.insert(a);
			else if (op[0] == 'Q'){
				scanf("%d", &a);
				it = S.lower_bound(a);
				int tmp = *it;
				if (tmp != a) --it;
				tmp = *it;
				cout << tmp << endl;
			}
			else if (op[0] == 'D'){
				scanf("%d%d", &a, &b);
				if (a == b) S.erase(a);
				else{
					// puts("debug");
					it1 = S.lower_bound(a), it2 =S.lower_bound(b);
					if (*it2 != b) --it2;
					int last = *it2;
					vector<int> vl;
					for (it = it1; it != it2; ++it)
						vl.push_back(*it);

					// for (int i=1; i<=vl.size(); ++i)
					// 	cout << vl[i] << endl;
					for (int i=0; i<vl.size(); ++i)
						S.erase(vl[i]);
					S.erase(last);
					// puts("debug");
				}
			}
		}

	}
	return 0;
}