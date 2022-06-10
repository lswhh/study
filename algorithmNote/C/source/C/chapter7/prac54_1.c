/*
 * --------------------------------------------
 *      오일러의 한붓그리기 (방향 그래프)     *
 * --------------------------------------------
 */

#include <stdio.h>

#define Node 4        /* 정점의 수 */
#define Root 6        /* 간선의 수 */
#define Start 1       /* 시작점 */

int a[Node+1][Node+1]={{0,0,0,0,0},
                       {0,0,1,0,0},
                       {0,0,0,1,1},
                       {0,0,0,0,1},
                       {0,1,1,0,0}};
int success,
    v[Root+1],      /* 경로를 저장할 스택 */
    n;              /* 통과한 간선의 수 */

void visit(int);

int main(void)
{
    success=0; n=Root;
    visit(Start);
    if (success==0)
        printf("해가 없음\n");

	return 0;
}

void visit(int i)
{
    int j;
    v[n]=i;
    if (n==0 && i==Start) {     /* 간선의 수만큼 통과한 후 원위치로 돌아오면 */
        printf("해 %d:",++success);
        for (i=0;i<=Root;i++)
            printf("%d",v[i]);
        printf("\n");
    }
    else {
        for (j=1;j<=Node;j++)
            if (a[i][j]!=0) {
                a[i][j]--;     /* 지나온 간선을 제거한다 */
                n--;
                visit(j);
                a[i][j]++;     /* 간선을 되살린다 */
                n++;
            }
    }
}

