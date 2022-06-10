/*
 * ----------------------
 *      기본 삽입법     *
 * ----------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100     /* 데이터 수 */

int main(void)
{
    int a[N],i,j,t;

    for(i=0;i<N;i++)       /* n개의 난수 */
        a[i]=rand() % 32767;

    for (i=1;i<N;i++) {
         for (j=i-1;j>=0;j--) {                /* ① */
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
