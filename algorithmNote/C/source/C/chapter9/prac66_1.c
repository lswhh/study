/*
 * -------------------------
 *      ����Ʈ ��ȸ����    *
 * -------------------------
 */

#include <stdio.h>

void backtrack(int,int);

#define N 5

int m[N+4][N+4],                    /* ü���� */
    dx[8]={2,1,-1,-2,-2,-1,1,2},    /* ����Ʈ�� �̵� x���� */
    dy[8]={1,2,2,1,-1,-2,-2,-1};    /* ����Ʈ�� �̵� y���� */

int main(void)
{
    int i,j;

    for (i=0;i<=N+3;i++)
        for (j=0;j<=N+3;j++)
            if (2<=i && i<=N+1 && 2<=j && j<=N+1)
                m[i][j]=0;      /* ü���� */
            else
                m[i][j]=1;      /* �� */

    backtrack(2,2);
	return 0;
}

void backtrack(int x,int y)
{
    int i,j,k;
    static int count=0,num=0;

    if (m[x][y]==0) {
        m[x][y]=++count;                  /* �湮��ȣ�� ��� */
        if (count==N*N) {
            printf("\n�� %d\n",++num);    /* �� ��� */
            for (i=2;i<=N+1;i++) {
                for (j=2;j<=N+1;j++)
                    printf("%4d",m[i][j]);
                printf("\n");
            }
        }
        else
            for (k=0;k<8;k++)           /* �̵��� ��ġ�� �����Ѵ� */
                backtrack(x+dx[k],y+dy[k]);
        m[x][y]=0;                      /* �������� ���ư��� */
        count--;
    }
}

