/*
 * ----------------------
 *      �⺻ ���Թ�     *
 * ----------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100     /* ������ �� */

int main(void)
{
    int a[N],i,j,t;

    for(i=0;i<N;i++)       /* n���� ���� */
        a[i]=rand() % 32767;

    for (i=1;i<N;i++) {
         for (j=i-1;j>=0;j--) {                /* �� */
             if (a[j]>a[j+1]) {
                 t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
            else
                break;
        }
    }

    for (i=0;i<N;i++)
    {
         printf("%8d",a[i]);
         if (i%10==9)
             printf("\n");
    }

    return 0;
}
