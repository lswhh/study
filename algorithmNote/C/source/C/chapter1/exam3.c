/*
 * --------------------
 *      순위 매김     *
 * --------------------
 */

#include <stdio.h>

#define Num 10

int main(void)     /* 순위 매김 */
{
    static int a[]={56,25,67,88,100,61,55,67,76,56};
    int rank[Num];
    int i,j;

    for (i=0;i<Num;i++) {
        rank[i]=1;
        for (j=0;j<Num;j++) {
            if (a[j]>a[i])
                rank[i]++;
        }
    }

    printf("   점수  순위\n");
    for (i=0;i<Num;i++){
        printf("%6d%6d\n",a[i],rank[i]);
    }

    return 0;
}
