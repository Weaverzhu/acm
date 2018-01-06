/***************************************************************/
/*                                                             */
/*  DON'T MODIFY main function ANYWAY!                         */
/*                                                             */
/***************************************************************/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//********** Specification of i2a **********
void i2a(char p[],int n)
/* PreCondition:
n is a non-negative integer, p is a pointer to a buffer
PostCondition:
put string representation of n in a buffer pointed by p
*/
{
	char s[100];
	int i,j,sign;
	if((sign=n)<0)//记录符号
	n=-n;//使n成为正数
	i=0;
	do{
	       s[i++]=n%10+'0';//取下一个数字
	}
	while ((n/=10)>0);//删除该数字
	if(sign<0)
	s[i++]='-';
	s[i]='\0';
	i = 0;
	for(j=i;j>=0;j--)//生成的数字是逆序的，所以要逆序输出
	 	p[i++] = s[j];
}
    //TODO: your function definition
/***************************************************************/
int main()
{
    int n; char s[20];
    scanf("%d",&n);
    //********** i2a is called here ********************
    i2a(s,n);
    printf("%s\n",s);
    //**************************************************
    return 0;
}