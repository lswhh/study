/*
 * -------------------------------
 *      셸정렬 (개선 삽입법)     *
 * -------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100   /* 데이터 수 */

int main(void)
{
    int a[N],i,j,k,gap,t;

    for(i=0;i<N;i++)        /* n개의 난수 */
        a[i]=rand() % 32767;

    gap=N/2;                /* gap의 초기값 */
    while (gap>0) {
        for (k=0;k<gap;k++) {    /* gap간격의 부분 데이터의 정렬 */
            for (i=k+gap;i<N;i=i+gap) {
                for (j=i-gap;j>=k;j=j-gap) {
                     if (a[j]>a[j+gap]) {
                        t=a[j]; a[j]=a[j+gap]; a[j+gap]=t;
                    }
                    else
                        break;
                }
            }
        }
        gap=gap/2;             /* gap을 반으로 줄임 */
    }

    for (i=0;i<N;i++) {
         printf("%8d",a[i]);
         if (i%10 == 9)
             printf("\n");
    }

    return 0;
}
