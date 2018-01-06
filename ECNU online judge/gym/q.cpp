int GCD(int m,int n);
/* PreCondition:
m,n are two positive integers
PostCondition:
return Greatest Common Divisor of m and n
*/



/***************************************************************/
/*                                                             */
/*  DON'T MODIFY main function ANYWAY!                         */
/*                                                             */
/***************************************************************/
#include <stdio.h>

//********** Specification of GCD **********
int GCD(int m,int n)
/* PreCondition:
m,n are two positive integers
PostCondition:
return Greatest Common Divisor of m and n
*/
{
	int a = m, b = n, c;
	while(b){
		c = a%b;
		a = b;
		b = c;
	}
	return a;
    //TODO: your function definition
}
/***************************************************************/
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    //********** GCD is called here ********************
    printf("GCD(%d,%d)=%d\n",m,n,GCD(m,n));
    //**************************************************
    return 0;
}
