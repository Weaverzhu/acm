 /***************************************************************/
/*                                                             */
/*  DON'T MODIFY main function ANYWAY!                         */
/*                                                             */
/***************************************************************/
#include <stdio.h>

//********** Specification of i2a **********
void i2a(char p[],long long n)
/* PreCondition:
n is a non-negative integer, p is a pointer to a buffer
PostCondition:
put string representation of n in a buffer pointed by p
*/
{
	sprintf(p, "%lld", n);

    //TODO: your function definition
}
/***************************************************************/
int main()
{
    long long n; char s[20];
    scanf("%lld",&n);
    //********** i2a is called here ********************
    printf("%lld", n);
    //**************************************************
    return 0;
}