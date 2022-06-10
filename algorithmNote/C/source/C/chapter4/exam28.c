/*
 * --------------------------------------
 *      ���� ���� (�� ������ ����)      *
 * --------------------------------------
 */

#include <stdio.h>

#define N 4
int p[N+1];

void perm(int);

int main(void)
{
    int i;

    for (i=1;i<=N;i++)        /* �ʱ� ���� */
        p[i]=i;
    perm(1);

	return 0;
}

void perm(int i)
{
    int j,t;

    if (i<N){
        for (j=i;j<=N;j++) {
            t=p[i]; p[i]=p[j]; p[j]=t;    /* p[i]�� p[j] ��ȯ */
            perm(i+1);                    /* ��� ȣ�� */
            t=p[i]; p[i]=p[j]; p[j]=t;    /* ������� ��ȯ */
        }
    }
    else {
        for (j=1;j<=N;j++)                /* ���� ��� */
            printf("%d ",p[j]);
        printf("\n");
    }
}

