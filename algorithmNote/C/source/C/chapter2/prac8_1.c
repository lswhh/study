/*
 * ----------------------
 *     �Ͼ缺�� ����    *
 * ----------------------
 */

#include <stdio.h>

#define N 1000             /* ���� �߻�ȸ�� */
#define M 10               /* ���� ������ ���� */
#define F (N/M)            /* ��밪 */
#define SCALE (40.0/F)     /* ������׷��� ���� (�ڵ� ������) */

unsigned rndnum=13;        /* ������ �ʱⰪ */

unsigned irnd(void);
double rnd(void);

int main(void)
{
    int i,j,rank,hist[M+1];
    double e=0.0;

    for (i=1;i<=M;i++)
        hist[i]=0;

    for (i=0;i<N;i++){
        rank=(int)(M*rnd()+1);         /* 1 ~ M�� ������ �ϳ� �߻� */
        hist[rank]++;
    }

    for (i=1;i<=M;i++){
        printf("%3d:%3d ",i,hist[i]);
        for (j=0;j<hist[i]*SCALE;j++)      /* ������׷� ǥ�� */
            printf("*");
        printf("\n");

        e=e+(double)(hist[i]-F)*(hist[i]-F)/F;        /*  ��� */
    }
    printf("��2=%f\n",e);

	return 0;
}
unsigned irnd(void)        /* 0 ~ 32767 ������ ���� ���� */
{
    rndnum=(rndnum*109+1021) % 32768;
    return rndnum;
}
double rnd(void)           /* 0 ~ 1 �̸��� �Ǽ� ���� */
{
    return irnd()/32767.1;
}
