/*
 * -----------------
 *      호너법     *
 * -----------------
 */

#include <stdio.h>

double fn(double, double *, int);

int main(void)
{
    static double a[] = {1, 2, 3, 4, 5};     /* 계수 : f(x)=5x4+4x3+3x2+2x+1 */
    double x;

    for (x=1; x<=5; x++)
        printf("fn(%f)=%f\n", x, fn(x, a, 4));

	return 0;
}

double fn(double x, double a[], int n)
{
    double p;
    int i;

    p = a[n];
    for (i=n-1; i>=0; i--)
        p=p*x+a[i];
    return p;
}

