/*
 * --------------------------------
 *      셸정렬 (개선 삽입법)      *
 * --------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100   /* 데이터 수 */

int main(void)
{
    int a[N],i,j,gap,t;

    for(i=0;i<N;i++)        /* N개의 난수 */
        a[i]=rand() % 32767;
                            /* N보다 작은 범위에서 최대의 gap을 결정한다. */
    for (gap=1;gap<N/3;gap=3*gap+1)
        ;

    while (gap>0){
        for (i=gap;i<N;i=i++){
            for (j=i-gap;j>=0;j=j-gap){
                if (a[j]>a[j+gap]){
                    t=a[j]; a[j]=a[j+gap]; a[j+gap]=t;
                }
                else
                    break;
            }
        }
        gap=gap/3;             /* gap을 1/3로 줄인다. */
    }

    for (i=0;i<N;i++) {
        printf("%8d",a[i]);
        if (i%10 == 9)
            printf("\n");
    }

    return 0;
}
