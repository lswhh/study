/*
 * -----------------------------------------
 *      테일러 전개 (exp(x) 개선 버전)     *
 * -----------------------------------------
 */

#include <stdio.h>
#include <math.h>

double myexp(double);

int main(void)
{
    double x;
    printf("    x       myexp(x)        exp(x)\n");
    for (x=-40;x<=40;x=x+10)
        printf("%5.1f%14.6g%14.6g\n",x,myexp(x),exp(x));

	return 0;
}
double myexp(double x)
{
    double EPS=1e-08;
    double s=1.0,e=1.0,d=1.0,a;
    int k;

    a=fabs(x);
    for (k=1;k<=200;k++){
        d=s;
        e=e*a/k;
        s=s+e;
        if (fabs(s-d)<EPS*fabs(d)){      /* 중단오차 */
            if (x>0)
                return s;
            else
                return 1.0/s;
        }
    }
    return 0.0;        /* 수렴하지 않을 때 */
}

