/*
 * -----------------------------------
 *     ���� ���α׷��� (�賶����)    *
 * -----------------------------------
 */

#include <stdio.h>

#define limit 8         /* �賶�� �������Ѱ� */
#define n 5             /* ���� ���� */
#define min    1        /* ���� �ּҰ� */

int main(void)
{
    static struct body {
        char *name;         /* ǰ�� */
        int size;           /* ���� */
        long price;         /* ���� */
    } a[]={{"plum",4,4500},{"apple",5,5700},{"orange",2,2250},
           {"strawberry",1,1100},{"melon",6,6700}};
    long newvalue,value[limit+1];
    int item[limit+1],
        i,s,p;

    for (s=0;s<=limit;s++) {
        value[s]=0;         /* �ʱⰪ */
    }
    for (i=0;i<n;i++)                      /* ���� ��ȣ */
	{
        for (s=a[i].size;s<=limit;s++)     /* �賶 ũ�� */
		{
            p=s-a[i].size;                  /* ���� ũ�� */
            newvalue=value[p]+a[i].price;
            if (newvalue>value[s])
			{
                value[s]=newvalue;item[s]=i;    /* ������ ���� */
            }
			printf("p=%d, s=%d, a[%d].size=%d, a[%d].price=%ld, value[%d]=%d, item[%d]=%d\n", p, s, i, a[i].size, i, a[i].price, s, value[s], s, item[s]);
        }
		printf("\n");
    }

    printf("    ǰ   ��    ����\n");
    for (s=limit;s>=min;s=s-a[item[s]].size)
        printf("%10s %8ld\n",a[item[s]].name,a[item[s]].price);
    printf("    ��   �� %7ld\n",value[limit]);

	return 0;
}

