/*
 * -------------------------
 *      나이트 순회문제    *
 * -------------------------
 */

#include <stdio.h>

void backtrack(int,int);

#define N 5

int m[N+4][N+4],                    /* 체스판 */
    dx[8]={2,1,-1,-2,-2,-1,1,2},    /* 나이트의 이동 x성분 */
    dy[8]={1,2,2,1,-1,-2,-2,-1};    /* 나이트의 이동 y성분 */

int main(void)
{
    int i,j;

    for (i=0;i<=N+3;i++)
        for (j=0;j<=N+3;j++)
            if (2<=i && i<=N+1 && 2<=j && j<=N+1)
                m[i][j]=0;      /* 체스판 */
            else
                m[i][j]=1;      /* 벽 */

    backtrack(2,2);
	return 0;
}

void backtrack(int x,int y)
{
    int i,j,k;
    static int count=0,num=0;

    if (m[x][y]==0) {
        m[x][y]=++count;                  /* 방문번호를 기록 */
        if (count==N*N) {
            printf("\n해 %d\n",++num);    /* 해 출력 */
            for (i=2;i<=N+1;i++) {
                for (j=2;j<=N+1;j++)
                    printf("%4d",m[i][j]);
                printf("\n");
            }
        }
        else
            for (k=0;k<8;k++)           /* 이동할 위치를 선택한다 */
                backtrack(x+dx[k],y+dy[k]);
        m[x][y]=0;                      /* 이전으로 돌아간다 */
        count--;
    }
}

