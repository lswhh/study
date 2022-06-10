/*
 * ------------------
 *      이분법      *
 * ------------------
 */

#include <stdio.h>
#include <math.h>

#define f(x) ((x)*(x)*(x)-(x)+1)
#define EPS 1e-8                /* 중단오차 */
#define LIMIT 50                /* 중단회수 */

int main(void)
{
    double low,high,x;
    int k=1;

    low=-2.0; high=2.0;
    for (k=1;k<=LIMIT;k++) {
        x=(low+high)/2;
        if (f(x)>0)
            high=x;
        else
            low=x;                // 수렴조건으로 Abs(f(x))<EPS를 사용해도 된다.
        if (f(x)==0 || fabs(high-low)<fabs(low)*EPS){
            printf("x=%f\n",x);
            break;
        }
    }
    if (k>LIMIT)
        printf("수렴하지 않는다.\n");

	return 0;
}

