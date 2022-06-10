/*
 * ------------------------------------
 *     사다리꼴 공식에 의한 정적분    *
 * ------------------------------------
 */

#include <stdio.h>
#include <math.h>

#define f(x) (sqrt(4-(x)*(x)))   /* 피적분함수 */

int main(void)
{
    int k;
    double a,b,n,h,x,s,sum;

    printf("적분구간 A,B ? ");
    scanf("%lf %lf",&a,&b);

    n=50;             /* a ~ b사이의 구간수 */
    h=(b-a)/n;        /* 구간폭 */
    x=a; s=0;
    for (k=1;k<=n-1;k++)
	{
        x=x+h;
        s=s+f(x);
	}
    sum=h*((f(a)+f(b))/2+s);
    printf("   /%f\n",b);
    printf("   |  sqrt(4-x*x) =%f\n",sum);
    printf("   /%f\n",a);

    return 0;
}
