/*
 * ----------------------
 *     일양성의 검정    *
 * ----------------------
 */

#include <stdio.h>

#define N 1000             /* 난수 발생회수 */
#define M 10               /* 정수 난수의 범위 */
#define F (N/M)            /* 기대값 */
#define SCALE (40.0/F)     /* 히스토그램의 높이 (자동 스케일) */

unsigned rndnum=13;        /* 난수의 초기값 */

unsigned irnd(void);
double rnd(void);

int main(void)
{
    int i,j,rank,hist[M+1];
    double e=0.0;

    for (i=1;i<=M;i++)
        hist[i]=0;

    for (i=0;i<N;i++){
        rank=(int)(M*rnd()+1);         /* 1 ~ M의 난수를 하나 발생 */
        hist[rank]++;
    }

    for (i=1;i<=M;i++){
        printf("%3d:%3d ",i,hist[i]);
        for (j=0;j<hist[i]*SCALE;j++)      /* 히스토그램 표시 */
            printf("*");
        printf("\n");

        e=e+(double)(hist[i]-F)*(hist[i]-F)/F;        /*  계산 */
    }
    printf("χ2=%f\n",e);

	return 0;
}
unsigned irnd(void)        /* 0 ~ 32767 사이의 정수 난수 */
{
    rndnum=(rndnum*109+1021) % 32768;
    return rndnum;
}
double rnd(void)           /* 0 ~ 1 미만의 실수 난수 */
{
    return irnd()/32767.1;
}

