/*
 * --------------------------------------
 *      ���丮��(factorial)�� �����    *
 * --------------------------------------
 */

#include <stdio.h>

long factorial(int);

int main(void)
{
    int n;
    for (n=0;n<13;n++)
        printf("%2d!= %10ld\n",n, factorial (n));

	return 0;
}
long factorial (int n)   /* ����Լ� */
{
    if (n==0)
        return 1L;
    else
        return n* factorial (n-1);
}

