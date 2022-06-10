/*
 * -----------------------------------------------
 *      �̷� ����ϱ� (�ϳ��� �ظ� ã�Ƴ���)     *
 * -----------------------------------------------
 */

#include <stdio.h>

int m[7][7]={{2,2,2,2,2,2,2},
             {2,0,0,0,0,0,2},
             {2,0,2,0,2,0,2},
             {2,0,0,2,0,2,2},
             {2,2,0,2,0,2,2},
             {2,0,0,0,0,0,2},
             {2,2,2,2,2,2,2}};

int Si,Sj,Ei,Ej,success;

int visit(int,int);

int main(void)
{
    success=0;                  /* Ż�� �������θ� ��Ÿ���� �÷��� */
    Si=1; Sj=1; Ei=5; Ej=5;     /* �Ա��� �ⱸ�� ��ġ */

    printf("�̷� Ž��\n");
    if (visit(Si,Sj)==0)
        printf("�ⱸ�� ã�� �� �����ϴ�.\n");
	else
		printf("\n");

	return 0;
}

int visit(int i,int j)
{
    m[i][j]=1;                /* ������ ��ġ�� ǥ�ø� ���� */

    if (i==Ei && j==Ej)       /* �ⱸ�� �������� �� */
        success=1;
                               /* �ⱸ�� ������ ������ �̷θ� Ž���Ѵ�. */
    if (success!=1 && m[i][j+1]==0) visit(i,j+1);
    if (success!=1 && m[i+1][j]==0) visit(i+1,j);
    if (success!=1 && m[i][j-1]==0) visit(i,j-1);
    if (success!=1 && m[i-1][j]==0) visit(i-1,j);

    if (success==1)          /* ������ ��ġ�� ����Ѵ�. */
        printf("(%d,%d) ",i,j);

    return success;
}

