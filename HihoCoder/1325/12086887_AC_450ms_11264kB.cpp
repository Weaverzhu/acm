#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
struct node
{
	node* ch[2], *fa;
	int v, w;
	void init(int v_){
		fa = ch[0] = ch[1] = NULL;
		w = rand(); v = v_;
	}
};
class Treap{
public:
	
	node root;
	void insert(node* now, int key){
		if (key < now->v){
			if (now->ch[0] == NULL){
				now->ch[0] = (node*)malloc(sizeof(node));
				now->ch[0]->init(key);
				now->ch[0]->fa = now;
				return;
			}else insert(now->ch[0], key);
		}else if (key > now->v){
			// printf("r ");
			if (now->ch[1] == NULL){
				now->ch[1] = (node*)malloc(sizeof(node));
				now->ch[1]->init(key);
				now->ch[1]->fa = now;
				// printf("%d\n", now->ch[1]->v);
				return;
			}else insert(now->ch[1], key);
		}
	}

	void l_rotate(node* a){
		node* b = a->ch[1];
		b->fa = a->fa;
		if (a->fa->ch[0] == a)
			a->fa->ch[0] = b;
		else
			a->fa->ch[1] = b;
		a->ch[1] = b->ch[0];
		b->ch[0]->fa = a;
		b->ch[0] = a;
		a->fa = b;
	}

	void r_rotate(node* a){
		node*b = a->ch[0];
		b->fa = a->fa;
		if (a->fa->ch[0] == a)
			a->fa->ch[0] = b;
		else
			a->fa->ch[1] = b;
		a->ch[0] = b->ch[1];
		b->ch[1]->fa = a;
		b->ch[1] = a;
		a->fa = b;
	}

	void rotate(node* now){
		while(now->fa != NULL){
			node* fa = now->fa;
			if (now->w < fa->w){
				if (now == fa->ch[0]){
					r_rotate(fa);
				}else l_rotate(fa);
			}else break;
		}
	}
	int ans;
	int lower_bound(node* now, int key){
		// printf("log :: %d\n", now->v);
		if (key > now->v){
			ans = max(ans, now->v);
			if (now->ch[1] != NULL)
				ans = max(ans, lower_bound(now->ch[1], key));
		}else if (key < now->v){
			if (now->ch[0] != NULL){
				ans = max(ans, lower_bound(now->ch[0], key));
			}
		}else return key;
		return ans;
	}
} treap;
int main(){
	int n;
	cin >> n;
	treap.root.init(-INF);
	node *root = &treap.root;
	for (int i=0; i<n; ++i){
		char op[2];
		int x;
		scanf("%s%d", op, &x);
		if (op[0] == 'I'){
			treap.insert(root, x);
		}else{
			treap.ans = -INF;
			printf("%d\n", treap.lower_bound(root, x));
		}
	}



	return 0;
}