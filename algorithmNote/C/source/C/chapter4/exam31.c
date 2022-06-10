/*
 * -------------------------------
 *      퀵 정렬 (quick sort)     *
 * -------------------------------
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
        s=a[left];              /* 왼쪽 끝에 있는 항을 축으로 한다. */
        i=left; j=right+1;        /* 축보다 작은 그룹과       */
        while (1){              /*       큰 그룹으로 나눈다. */
            while (a[++i]<s);
            while (a[--j]>s);
            if (i>=j) break;
            t=a[i]; a[i]=a[j]; a[j]=t;
        }
        a[left]=a[j]; a[j]=s;   /* 축을 올바른 위치에 저장한다. */

        quick(a,left,j-1);      /* 왼쪽 부분수열에 대한 재귀호출 */
        quick(a,j+1,right);     /* 오른쪽 부분수열에 대한 재귀호출 */
    }
}

