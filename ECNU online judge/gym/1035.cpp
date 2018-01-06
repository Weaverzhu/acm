#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char Root[1] = {20};
struct node
{
	node* ch[2], *fa;
	int w, sz;
	char* s;
	void init(const char* tmp){
		int len = strlen(tmp);
		s = (char*)malloc(sizeof(char) * (len+1));
		s[len] = 0;
		for (int i=0; i<len; ++i)
			s[i] = tmp[i];
		fa = ch[0] = ch[1] = NULL;
		w = rand(); sz = 1;
	}
};
struct Treap{
	node root;
	void insert(node* now, char* key){
		int res = strcmp(key, now->s);
		if (res == 0){
			now->sz++;
		}
		else if (res<0){
			if (now->ch[0] == NULL){
				now->ch[0] = (node*)malloc(sizeof(node));
				now->ch[0]->init(key);
				now->ch[0]->fa = now;
				return;
			}else insert(now->ch[0], key);
		}else if (res>0){
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
	void pt_all(node* now){
		if (now->ch[0] != NULL)
			pt_all(now->ch[0]);
		if (strcmp(now->s, Root) != 0){
			printf("%s %d\n", now->s, now->sz);
		}
		if (now->ch[1] != NULL)
			pt_all(now->ch[1]);
	}
	
} treap;
char tmp[500005];
int main(){
	int n;
	scanf("%d", &n);
	treap.root.init(Root);
	while(~scanf("%s", tmp)){
		treap.insert(&treap.root, tmp);
	}
	treap.pt_all(&treap.root);
	return 0;
}