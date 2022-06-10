/*
 * ----------------------------------
 *      순열 생성 (사전식 순서)     *
 * ----------------------------------
 */

#include <stdio.h>

#define N 4
int p[N+1];

void perm(int);

int main(void)
{
    int i;

    for (i=1;i<=N;i++)        /* 초기 설정 */
        p[i]=i;
    perm(1);

	return 0;
}

void perm(int i)
{
    int j,k,t;

    if (i<N){
        for (j=i;j<=N;j++) {
            t=p[j];                  /* p[i] ~ p[j]를 오른쪽으로 회전 */
            for (k=j;k>i;k--)
                p[k]=p[k-1];
            p[i]=t;

            perm(i+1);               /* 재귀 호출 */

            for (k=i;k<j;k++)        /* 배열의 순서를 재귀 호출 이전으로 돌려놓음 */
                p[k]=p[k+1];
            p[j]=t;
        }
    }
    else {
        for (j=1;j<=N;j++)           /* 순열 출력 */
            printf("%d ",p[j]);
        printf("\n");
    }
}

