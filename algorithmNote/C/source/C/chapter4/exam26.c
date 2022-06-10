/*
 * --------------------------------------
 *      ÆÑÅä¸®¾ó(factorial)ÀÇ Àç±ÍÇØ    *
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
long factorial (int n)   /* Àç±ÍÇÔ¼ö */
{
    if (n==0)
        return 1L;
    else
        return n* factorial (n-1);
}

