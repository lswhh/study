/*
 * ----------------------------
 *     ∆—≈‰∏ÆæÛ¿« ∫Ò¿Á±Õ«ÿ    *
 * ----------------------------
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

long factorial (int n)   /* ∆—≈‰∏ÆæÛ */
{
    int k;
    long p=1L;

    for (k=n;k>=1;k--)
        p=p*k;
    return p;
}

