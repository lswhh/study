/*
 * ---------------------------------------
 *      Simpson 적분법에 의한 정적분     *
 * ---------------------------------------
 */

#include <stdio.h>
#include <math.h>

#define f(x) (sqrt(4-(x)*(x)))   /* 피적분함수 */

int main(void)
{
    int k;
    double a,b,n,h,fo,fe,sum;

    printf("적분구간 A,B ? ");
    scanf("%lf %lf",&a,&b);

    n=50;              /* a ~ b 사이의 구간수 */
    h=(b-a)/(2*n);     /* 구간폭 */
    fo=0; fe=0;
    for (k=1;k<=2*n-3;k=k+2){
        fo=fo+f(a+h*k);         /* 홀수항 */
        fe=fe+f(a+h*(k+1));     /* 짝수항 */
    }
    sum=(f(a)+f(b)+4*(fo+f(b-h))+2*fe)*h/3;
    printf("   /%f\n",b);
    printf("   |  sqrt(4-x*x) =%f\n",sum);
    printf("   /%f\n",a);

	return 0;
}

