/*
 * -----------------------------
 *      8퀸 (8 Queens) 문제    *
 * -----------------------------
 */

#include <stdio.h>

void backtrack(int);

#define N 8
int column[N+1],    /* 동일한 열에 퀸이 놓여있는지 판단 */
    rup[2*N+1],     /* 우상방향 대각선상에 퀸이 놓여있는지 판단 */
    lup[2*N+1],     /* 좌상방향 대각선상에 퀸이 놓여있는지 판단 */
    queen[N+1];     /* 퀸의 위치 */

int main(void)
{
    int i;

    for (i=1;i<=N;i++)
        column[i]=1;
    for (i=1;i<=2*N;i++)
        rup[i]=lup[i]=1;

    backtrack(1);
	return 0;
}

void backtrack(int i)
{
    int j,x,y;
    static int num=0;

    if (i>N) {
        printf("\n해 %d \n",++num);                 /* 해 출력 */
        for (y=1;y<=N;y++) {
            for (x=1;x<=N;x++)
                if (queen[y]==x)
                    printf(" Q");
                else
                    printf(" .");
            printf("\n");
        }
    }
    else {
        for (j=1;j<=N;j++) {
            if (column[j]==1 && rup[i+j]==1 && lup[i-j+N]==1) {
                queen[i]=j;                         /* (i, j)가 퀸의 위치 */
                column[j]=rup[i+j]=lup[i-j+N]=0;    /* 국면의 변경 */
                backtrack(i+1);
                column[j]=rup[i+j]=lup[i-j+N]=1;    /* 국면의 되돌림 */
            }
        }
    }
}

