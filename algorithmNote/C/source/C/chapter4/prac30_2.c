/*
 * ------------------------------------
 *      �̷��� ��� ��� ��������     *
 * ------------------------------------
 */

#include <stdio.h>

int m[9][9]={{2,2,2,2,2,2,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,0,2,2,0,2,2,0,2},
             {2,0,2,0,0,2,0,0,2},
             {2,0,2,0,2,0,2,0,2},
             {2,0,0,0,0,0,2,0,2},
             {2,2,0,2,2,0,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,2,2,2,2,2,2,2,2}};

int Si,Sj,Ei,Ej,success,
    sp,ri[100],rj[100];         /* ������ ��ġ�� ������ ���� */

int visit(int,int);

int main(void)
{
    sp=0;                       /* ���� �������� �ʱⰪ */
    success=0;                  /* Ż�� �������θ� ��Ÿ���� �÷��� */
    Si=1; Sj=1; Ei=7; Ej=7;     /* �Ա��� �ⱸ�� ��ġ */

    printf("�̷� Ž��\n");
    if (visit(Si,Sj)==0)
        printf("�ⱸ�� ã�� �� �����ϴ�.\n");
	else
		printf("\n");

	return 0;
}
int visit(int i,int j)
{
    int k;
    static int path=1;

    m[i][j]=1;
    ri[sp]=i; rj[sp]=j; sp++;   /* ������ ��ġ�� ���ÿ� ���� */

    if (i==Ei && j==Ej) {       /* �ⱸ�� �������� �� */
        printf("path=%d\n",path++);     /* ������ ��ġ ��� */
        for (k=0;k<sp;k++)
            printf("(%d,%d) ",ri[k],rj[k]);
		printf("\n");
        success=1;
    }
                                /* �̷θ� Ž���Ѵ�. */
    if (m[i][j+1]==0) visit(i,j+1);
    if (m[i+1][j]==0) visit(i+1,j);
    if (m[i][j-1]==0) visit(i,j-1);
    if (m[i-1][j]==0) visit(i-1,j);

    sp--;                       /* ���ÿ��� ���� */
    m[i][j]=0;                  /* �ٸ� ��θ� Ž���ϱ� ���� */

    return success;
}
