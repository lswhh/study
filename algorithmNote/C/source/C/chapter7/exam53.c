/*
 * ---------------------------------------
 *      위상 정렬 (topological sort)     *
 * ---------------------------------------
 */
#include <stdio.h>

#define N 8                             /* 정점의 수 */

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0},   /* 인접행렬 */
                 {0,0,0,1,0,0,0,0,0},
                 {0,1,0,0,0,1,0,0,0},
                 {0,0,0,0,1,0,0,1,0},
                 {0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,1,0,1,0,0},
                 {0,0,0,0,0,0,0,1,1},
                 {0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,1,0}};
int v[N+1];                             /* 방문 플래그 */

void visit(int);

int main(void)
{
    int i;

    for (i=1;i<=N;i++)
        v[i]=0;
    for (i=1;i<=N;i++)
        if (v[i]==0)
            visit(i);

	printf("\n");
	return 0;
}

void visit(int i)
{
    int j;
    v[i]=1;
    for (j=1;j<=N;j++) {
        if (a[i][j]==1 && v[j]==0)
            visit(j);
    }
    printf("%d ",i);
}

