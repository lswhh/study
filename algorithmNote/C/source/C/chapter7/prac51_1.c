/*
 * --------------------------------------
 *      그래프의 탐색 (깊이우선) #2     *
 * --------------------------------------
 */
#include <stdio.h>

#define N 8                             /* 정점의 수 */

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0},   /* 인접행렬 */
                 {0,0,1,0,0,0,0,0,0},
                 {0,1,0,1,1,0,0,0,0},
                 {0,0,1,0,0,0,0,1,0},
                 {0,0,1,0,0,1,0,0,0},
                 {0,0,0,0,1,0,1,0,0},
                 {0,0,0,0,0,1,0,1,1},
                 {0,0,0,1,0,0,1,0,1},
                 {0,0,0,0,0,0,1,1,0}};
int v[N+1];                             /* 방문 플래그 */

void visit(int);

int main(void)
{
    int i,k;

    for (k=1;k<=N;k++) {
        for (i=1;i<=N;i++)
            v[i]=0;
        visit(k);
        printf("\n");
    }

	return 0;
}

void visit(int i)
{
    int j;

    v[i]=1;
    for (j=1;j<=N;j++) {
        if (a[i][j]==1 && v[j]==0) {
            printf("%d->%d ",i,j);
            visit(j);
        }
    }
}

