//********** Specification of i2a **********
void i2a(char p[],int n);
/* PreCondition:
n is a non-negative integer, p is a pointer to a buffer
PostCondition:
put string representation of n in a buffer pointed by p，and return p
*/
/***************************************************************/
/*                                                             */
/*  DON'T MODIFY main function ANYWAY!                         */
/*                                                             */
/***************************************************************/
#include <stdio.h>
#include <string.h>
//********** Specification of i2a **********
void i2a(char p[],int n)
/* PreCondition:
n is a non-negative integer, p is a pointer to a buffer
PostCondition:
put string representation of n in a buffer pointed by p
*/
{
    if (n == 0){
    	p[0] = '0'; p[1] = 0; return;
	}else{
		long long sz = 1;
		while(sz <= n) sz *= 10;
		sz /= 10;
		// printf("%d\n", sz);
		if (sz == 1){
			p[0] = n+'0';
			p[1] = 0;
			return;
		}else{
			p[0] = n/sz+'0';
			if (n%sz == 0){
				int now = 1;
				while(sz != 1) sz /= 10, p[now++] = '0';
				p[now] = 0;
				return;
			}else i2a(p+1, n-(n/sz)*sz);
		}
	}
}
/***************************************************************/
int main()
{
    int n; char s[20];
    // scanf("%d",&n);
    //********** i2a is called here ********************
    for (int i=0; i<1000000; ++i){
    	memset(s, 0, sizeof(s));
    	i2a(s, i);
    	int b;
    	sscanf(s, "%d", &b);
    	// printf("%d\n", b);
    	if (b!=i){
    		printf("%d\n", i);
    		break;
    	}
    }
    //**************************************************
    return 0;
}
