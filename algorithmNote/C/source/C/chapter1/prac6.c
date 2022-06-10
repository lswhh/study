/*
 * ---------------------------
 *     유클리드 호제법 #2    *
 * ---------------------------
 */

#include <stdio.h>

int main(void)
{
    int a,b,m,n,k;

    printf("두 정수를 입력하세요. : ");
    scanf("%d %d",&a,&b);

    m=a; n=b;
    do {
        k=m % n;
        m=n; n=k;
    } while(k!=0);
    printf("최대공약수 = %d\n",m);

    return 0;
}
