/*
 * -------------------------------------
 *     몬테카를로법에 의한 π 계산  　 *
 * -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM 1000

double rnd(void);

int main(void)
{
    double x,y,pai;
    int i,in=0;

    for (i=1;i<=NUM;i++){
        x=rnd();
        y=rnd();
        if (x*x+y*y<=1)
            in++;
    }
    pai=(double)4*in/NUM;
    printf("π값 = %f\n",pai);

    return 0;
}

double rnd(void)        /* 0 ~ 1 사이의 난수 */
{
    return (double)rand()/RAND_MAX;
}
