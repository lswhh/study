/*
 * -----------------------------------
 *      정규난수 (Box-Muller법)      *
 * -----------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void brnd(double,double,double *,double *);

int main(void)
{
    int i,j,hist[100];
    double x,y;

    for (i=0;i<100;i++)
        hist[i]=0;

    for (i=0;i<1000;i++){
        brnd(2.5,10.0,&x,&y);
        hist[(int)x]++;
        hist[(int)y]++;
    }

    for (i=0;i<=20;i++){            /* 히스토그램 표시 */
        printf("%3d : I ",i);
        for (j=1;j<=hist[i]/10;j++){
            printf("*");
        }
        printf("\n");
    }

	return 0;
}
void brnd(double sig,double m,double *x,double *y)
{
    double r1,r2;
	r1=(double)rand()/RAND_MAX; r2=(double)rand()/RAND_MAX;
    *x=sig*sqrt(-2*log(r1))*cos(2*3.14159*r2)+m;
    *y=sig*sqrt(-2*log(r1))*sin(2*3.14159*r2)+m;
}

