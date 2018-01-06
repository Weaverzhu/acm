#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=10010;
int ans[MAXN],flot,k;
bool failed;
struct Node{
    bool h_v;
    int v;
    Node *L,*R;
    Node():h_v(false),L(NULL),R(NULL){}
}*head;
void addnode(int v,char *s){
    //printf("%s %d\n",s,v);
    Node *cur=head;
    for(int i=0;s[i];i++){
        if(s[i]=='L'){
            if(cur->L==NULL)cur->L=new Node();
            cur=cur->L;
        }
        else if(s[i]=='R'){
            if(cur->R==NULL)cur->R=new Node();
            cur=cur->R;
        }
    }
    if(cur->h_v)failed=true;//注意要加上failed判断没有出现数字的情况；
    cur->v=v;
    cur->h_v=true;
}
void print(){
    queue<Node*>q;
    Node *cur=head;
    q.push(head);
    while(!q.empty()){
        cur=q.front();
        q.pop();
        if(cur->h_v==0)flot=0;
        if(!flot)break;
        ans[k++]=cur->v;
        if(cur->L!=NULL)q.push(cur->L);
        if(cur->R!=NULL)q.push(cur->R);
    }
    if(flot&&!failed)for(int i=0;i<k;i++){
        if(i)printf(" ");
        printf("%d",ans[i]);
    }
    else printf("not complete");
    puts("");
}
void freenode(Node *cur){
    if(cur==NULL)return;
    freenode(cur->L);
    freenode(cur->R);
    free(cur);
}
int main(){
    char s[MAXN];
    head=new Node();
    failed=false;
    while(~scanf("%s",s)){
        if(!strcmp(s,"()")){
            flot=1;
            k=0;
            print();
            freenode(head);
            head=new Node();
            failed=false;
            continue;
        }
        int v;
        sscanf(&s[1],"%d",&v);
        addnode(v,strchr(s,',')+1);
    }
    return 0;
}