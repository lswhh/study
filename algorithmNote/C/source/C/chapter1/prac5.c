/*
 * --------------------------------------
 *     몬테카를로법에 의한 면적 계산　　*
 * --------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM 1000

double rnd(void);

int main(void)
{
    double x,y,s;
    int i,in=0;

    for (i=0;i<NUM;i++) {
        x=2*rnd();
        y=rnd();
        if (x*x/4+y*y<=1)
            in++;
    }
    s=4.0*(2.0*in/NUM);
    printf("타원의 면적 = %f\n",s);

    return 0;
}

double rnd(void)
{
    return (double)rand()/RAND_MAX;
}
