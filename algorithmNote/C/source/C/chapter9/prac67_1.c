/*
 * ------------------------------------------------------
 *     동적 프로그래밍 (거스름돈 개수를 최소화한다.)    *
 * ------------------------------------------------------
 */

#include <stdio.h>

#define limit 42    /* 거스름돈 금액 */
#define n 3         /* 동전 종류 */

int main(void)
{
    static int size[]={1,10,25};
    int value[limit+1],     /* 개수 */
        item[limit+1],      /* 동전 번호 */
        i,s,p,newvalue;

    for (s=0;s<=limit;s++) {
        value[s]=s;          /* 초기값 -- ① */
    }
    for (i=0;i<n;i++) {                   /* 동전 번호 */
        for (s=size[i];s<=limit;s++) {    /* 배낭의 크기 */
            p=s-size[i];
            newvalue=value[p]+1;
            if (newvalue<=value[s]) {
                value[s]=newvalue;item[s]=i;     /* 최적해 갱신 */
            }
        }
    }

    printf("동전 개수 = %3d : ",value[limit]);
    for (s=limit;s>0;s=s-size[item[s]])
        printf("%3d,",size[item[s]]);

	printf("\n");
	return 0;
}

