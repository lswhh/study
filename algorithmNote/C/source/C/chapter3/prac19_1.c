/*
 * -------------------------------
 *      ������ (���� ���Թ�)     *
 * -------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100   /* ������ �� */

int main(void)
{
    int a[N],i,j,k,gap,t;

    for(i=0;i<N;i++)        /* n���� ���� */
        a[i]=rand() % 32767;

    gap=N/2;                /* gap�� �ʱⰪ */
    while (gap>0) {
        for (k=0;k<gap;k++) {    /* gap������ �κ� �������� ���� */
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
        gap=gap/2;             /* gap�� ������ ���� */
    }

    for (i=0;i<N;i++) {
         printf("%8d",a[i]);
         if (i%10 == 9)
             printf("\n");
    }

    return 0;
}
