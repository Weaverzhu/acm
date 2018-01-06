#include <cstdio>  
#include <climits>  
using namespace std;  
typedef struct node {  
    node *l,*r;  
    int data;  
} Tree;  
int ans;  
void creat(Tree* &T,int data) {  
    if(T==NULL) {  
        T=new Tree;  
        T->data=data;  
        T->l=NULL;  
        T->r=NULL;  
        return;  
    }  
    if(data>T->data){ creat(T->r,data);  }  
    else {creat(T->l,data); }  
}  
void Find(Tree* &T,int key) {  
    if(T==NULL) return;  
    if(key>=T->data) {  
        ans= T->data>ans? T->data : ans;  
        Find(T->r,key);  
    } else Find(T->l,key);  
}  
int main() {  
    char c;  
    int n,t;  
    Tree *T=NULL;  
    scanf("%d%*c",&n);  
    while(n-- && scanf("%c %d%*c",&c,&t)) {  
        if(c=='I') creat(T,t);  
        else {  
            ans=INT_MIN;  
            Find(T,t);  
            printf("%d\n",ans);  
        }  
    }  
    return 0;  
}  