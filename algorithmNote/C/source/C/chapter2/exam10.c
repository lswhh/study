/*
 * -------------------------------
 *      테일러 전개 (exp(x))     *
 * -------------------------------
 */

#include <stdio.h>
#include <math.h>

double myexp(double);

int main(void)
{
    double x;
    printf("    x      myexp(x)        exp(x)\n");
    for (x=0;x<=40;x=x+10)
        printf("%5.1f%14.6g%14.6g\n",x,myexp(x),exp(x));

	return 0;
}
double myexp(double x)
{
    double EPS=1e-08;
    double s=1.0,e=1.0,d=1.0;
    int k;

    for (k=1;k<=200;k++) {
        d=s;
        e=e*x/k;
        s=s+e;
        if (fabs(s-d)<EPS*fabs(d))      /* 중단오차 */
            return s;
    }
    return 0.0;    /* 수렴하지 않을 때 */
}

