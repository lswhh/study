/*
 * ------------------
 *      �̺й�      *
 * ------------------
 */

#include <stdio.h>
#include <math.h>

#define f(x) ((x)*(x)*(x)-(x)+1)
#define EPS 1e-8                /* �ߴܿ��� */
#define LIMIT 50                /* �ߴ�ȸ�� */

int main(void)
{
    double low,high,x;
    int k=1;

    low=-2.0; high=2.0;
    for (k=1;k<=LIMIT;k++) {
        x=(low+high)/2;
        if (f(x)>0)
            high=x;
        else
            low=x;                // ������������ Abs(f(x))<EPS�� ����ص� �ȴ�.
        if (f(x)==0 || fabs(high-low)<fabs(low)*EPS){
            printf("x=%f\n",x);
            break;
        }
    }
    if (k>LIMIT)
        printf("�������� �ʴ´�.\n");

	return 0;
}

