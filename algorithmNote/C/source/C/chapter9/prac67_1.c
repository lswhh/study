/*
 * ------------------------------------------------------
 *     ���� ���α׷��� (�Ž����� ������ �ּ�ȭ�Ѵ�.)    *
 * ------------------------------------------------------
 */

#include <stdio.h>

#define limit 42    /* �Ž����� �ݾ� */
#define n 3         /* ���� ���� */

int main(void)
{
    static int size[]={1,10,25};
    int value[limit+1],     /* ���� */
        item[limit+1],      /* ���� ��ȣ */
        i,s,p,newvalue;

    for (s=0;s<=limit;s++) {
        value[s]=s;          /* �ʱⰪ -- �� */
    }
    for (i=0;i<n;i++) {                   /* ���� ��ȣ */
        for (s=size[i];s<=limit;s++) {    /* �賶�� ũ�� */
            p=s-size[i];
            newvalue=value[p]+1;
            if (newvalue<=value[s]) {
                value[s]=newvalue;item[s]=i;     /* ������ ���� */
            }
        }
    }

    printf("���� ���� = %3d : ",value[limit]);
    for (s=limit;s>0;s=s-size[item[s]])
        printf("%3d,",size[item[s]]);

	printf("\n");
	return 0;
}

