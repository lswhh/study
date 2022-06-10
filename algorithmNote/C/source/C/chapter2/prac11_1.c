/*
 * -------------------
 *      Newton법     *
 * -------------------
 */

#include <stdio.h>
#include <math.h>

#define f(x) ((x)*(x)*(x)-(x)+1)
#define g(x) (3*(x)*(x)-1)
#define EPS  1e-8               /* 중단오차 */
#define LIMIT 50                /* 중단회수 */

int main(void)
{
    double x=-2.0,dx;
    int k;

    for (k=1;k<=LIMIT;k++) {
        dx=x;
        x=x-f(x)/g(x);
        if (fabs(x-dx)<fabs(dx)*EPS) {
            printf("x=%f\n",x);
            break;
        }
    }
    if (k>LIMIT)
        printf("수렴하지 않음\n");

	return 0;
}

