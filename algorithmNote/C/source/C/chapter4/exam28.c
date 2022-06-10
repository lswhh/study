/*
 * --------------------------------------
 *      순열 생성 (비 사전식 순서)      *
 * --------------------------------------
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
    int j,t;

    if (i<N){
        for (j=i;j<=N;j++) {
            t=p[i]; p[i]=p[j]; p[j]=t;    /* p[i]와 p[j] 교환 */
            perm(i+1);                    /* 재귀 호출 */
            t=p[i]; p[i]=p[j]; p[j]=t;    /* 원래대로 교환 */
        }
    }
    else {
        for (j=1;j<=N;j++)                /* 순열 출력 */
            printf("%d ",p[j]);
        printf("\n");
    }
}

