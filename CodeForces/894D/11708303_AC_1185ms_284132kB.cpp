#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long LL;
const int N=1000050;

vector<LL> sm[N];
vector<int> ln[N];
int len[N],n,q,a[N];
inline void merge(int x,int y){
	register int i=0,j=0,k=0,ad=len[y];
	register int lx=ln[x].size(),ly=ln[y].size();
	while(i<lx&&j<ly){
		if(ln[x][i]<ln[y][j]+ad)
			a[k++]=ln[x][i++];
		else
			a[k++]=ln[y][j++]+ad;
	}
	while(i<lx)a[k++]=ln[x][i++];
	while(j<ly)a[k++]=ln[y][j++]+ad;
	for(i=0;i<lx;i++)ln[x][i]=a[i];
	for(i=lx;i<k;i++)
		ln[x].push_back(a[i]);
}
LL cal(int nod,int lx){
	register int lb=0,rb=ln[nod].size()-1,mid;
	while(lb<=rb){
		mid=lb+rb>>1;
		if(ln[nod][mid]<=lx)
			lb=mid+1;
		else
			rb=mid-1;
	}
	if(rb<0)return 0;
	return 1ll*lx*(rb+1)-sm[nod][rb];
}

int main(){
	
	int i,j,k,las;
	scanf("%d%d",&n,&q);
	for(i=2;i<=n;i++)scanf("%d",&len[i]);
	for(i=1;i<=n;i++)
		ln[i].push_back(0);
	for(i=n;i>1;i--)merge(i/2,i);
	for(i=1;i<=n;i++){
		for(j=0,k=ln[i].size();j<k;j++){
			sm[i].push_back(ln[i][j]);
			if(j)sm[i][j]+=sm[i][j-1];
		}
	}
	for(i=1;i<=q;i++){
		scanf("%d%d",&j,&k);
		register LL cnt=0;
		for(las=0;j;k-=len[j],las=j,j>>=1){
			if(k<0)break;
			cnt+=k;
			int lch=j<<1,rch=j<<1|1;
			if(lch<=n&&las!=lch)
				cnt+=cal(lch,k-len[lch]);
			if(rch<=n&&las!=rch)
				cnt+=cal(rch,k-len[rch]);
		}
		printf("%lld\n",cnt);
	}
	
	return 0;
}
