/*
 * -----------------------------------------
 *    랜덤한 순열 (효율이 떨어지는 방법)   *
 * -----------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 20

int irnd(int);

int main(void)
{
    int i,j,flag,a[N+1];

    a[1]=irnd(N);                          /* ① */
    for (i=2;i<=N;i++){                    /* ② */
        do {
            a[i]=irnd(N);flag=0;           /* ③ */
            for (j=1;j<i;j++)              /* ④ */
                if (a[i]==a[j]){
                    flag=1;break;
                }
        } while (flag==1);
    }
    for (i=1;i<=N;i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}

int irnd(int n)        /* 1 ~ N의 난수 */
{
    return (int)(rand()%n + 1);
}
