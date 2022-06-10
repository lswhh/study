/*
 * ----------------------
 *      기본 삽입법     *
 * ----------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100   /* 데이터 수 */

int main(void)
{
    int a[N+1],i,j,t;

    for(i=1;i<=N;i++)        /* N개의 난수 */
        a[i]=rand() % 32767;

    a[0]=-9999;              /* 경계값 */
    for (i=2;i<=N;i++) {
        t=a[i];
        for (j=i-1;a[j]>t;j--)
             a[j+1]=a[j];
        a[j+1]=t;
    }

    for (i=1;i<=N;i++) {
        printf("%8d",a[i]);
        if (i%10 == 0)
            printf("\n");
    }

    return 0;
}
