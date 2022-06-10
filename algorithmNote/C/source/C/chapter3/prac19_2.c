/*
 * --------------------------------
 *      ������ (���� ���Թ�)      *
 * --------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100   /* ������ �� */

int main(void)
{
    int a[N],i,j,gap,t;

    for(i=0;i<N;i++)        /* N���� ���� */
        a[i]=rand() % 32767;
                            /* N���� ���� �������� �ִ��� gap�� �����Ѵ�. */
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
        gap=gap/3;             /* gap�� 1/3�� ���δ�. */
    }

    for (i=0;i<N;i++) {
        printf("%8d",a[i]);
        if (i%10 == 9)
            printf("\n");
    }

    return 0;
}
