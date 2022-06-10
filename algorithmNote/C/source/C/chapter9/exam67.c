/*
 * -----------------------------------
 *     동적 프로그래밍 (배낭문제)    *
 * -----------------------------------
 */

#include <stdio.h>

#define limit 8         /* 배낭의 무게제한값 */
#define n 5             /* 물건 종류 */
#define min    1        /* 무게 최소값 */

int main(void)
{
    static struct body {
        char *name;         /* 품명 */
        int size;           /* 무게 */
        long price;         /* 가격 */
    } a[]={{"plum",4,4500},{"apple",5,5700},{"orange",2,2250},
           {"strawberry",1,1100},{"melon",6,6700}};
    long newvalue,value[limit+1];
    int item[limit+1],
        i,s,p;

    for (s=0;s<=limit;s++) {
        value[s]=0;         /* 초기값 */
    }
    for (i=0;i<n;i++)                      /* 물건 번호 */
	{
        for (s=a[i].size;s<=limit;s++)     /* 배낭 크기 */
		{
            p=s-a[i].size;                  /* 남은 크기 */
            newvalue=value[p]+a[i].price;
            if (newvalue>value[s])
			{
                value[s]=newvalue;item[s]=i;    /* 최적해 갱신 */
            }
			printf("p=%d, s=%d, a[%d].size=%d, a[%d].price=%ld, value[%d]=%d, item[%d]=%d\n", p, s, i, a[i].size, i, a[i].price, s, value[s], s, item[s]);
        }
		printf("\n");
    }

    printf("    품   명    가격\n");
    for (s=limit;s>=min;s=s-a[item[s]].size)
        printf("%10s %8ld\n",a[item[s]].name,a[item[s]].price);
    printf("    합   계 %7ld\n",value[limit]);

	return 0;
}

