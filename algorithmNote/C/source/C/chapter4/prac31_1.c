/*
 * --------------------
 *      퀵 정렬 #2    *
 * --------------------
 */

#include <stdio.h>

void quick(int *,int,int);

#define N 10

int main(void)
{
    static int a[]={41,24,76,11,45,64,21,69,19,36};
    int k;

    quick(a,0,N-1);

    for (k=0;k<N;k++)
        printf("%4d",a[k]);

	printf("\n");
	return 0;
}

void quick(int a[],int left,int right)
{
    int s,t,i,j;
    if (left<right) {
        s=a[(left+right)/2];    /* 중앙에 있는 값을 축으로 한다. */
        i=left-1; j=right+1;    /* 축보다 작은 그룹과       */
        while (1) {             /*       큰 그룹으로 나눈다. */
            while (a[++i]<s);
            while (a[--j]>s);
            if (i>=j) break;
            t=a[i]; a[i]=a[j]; a[j]=t;
        }

        quick(a,left,i-1);        /* 왼쪽 부분수열에 대한 재귀호출 */
        quick(a,j+1,right);       /* 오른쪽 부분수열에 대한 재귀호출 */
    }
}

