#include <stdio.h>
#include <string.h>

#define N 80
//waterbottle erbottlewat


int isRotation(char s1[],char s2[])
{
	int s,ss,z,i,j;
	s=strlen(s1);ss=strlen(s2);
	i = 0, j = 0;
	if(s!=ss)z=0;
	else{
	    while(j<ss){
	    	i = 0;
	    	
	    	while(j < ss && s2[j]!=s1[i]) ++j;
	    	int k = j;
	    	// cout << j << endl;
	    	if (j == ss) return 0;
		    while(j<ss){
		    	++j; ++i;
		    	// printf("%c %c\n", s1[i], s2[j]);
			    if(j==ss){
			    	// printf("d\n");
		        	for(j=0;s1[i]==s2[j]&&i!=s;i++,j++);
			        if(i==s) return 1;
			        if(s1[i]!=s2[j]) {z = 0; break;}
				};
			    if(s1[i]!=s2[j]){z = 0; break;}
			}
			j = k+1;
		}
	}
	return z;
}

int main()
{
	freopen("out.txt", "w", stdout);
	char s[N+1],t[N+1];
	scanf("%s%s",s,t);
	if(isRotation(s,t))printf("\"%s\" is a rotation of \"%s\"\n",s,t);
	else printf("\"%s\" is NOT a rotation of \"%s\"\n",s,t);
	return 0;
}