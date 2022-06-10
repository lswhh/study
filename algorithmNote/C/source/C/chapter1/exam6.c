/*
 * -------------------------
 *     유클리드 호제법     *
 * -------------------------
 */

#include <stdio.h>

int main(void)
{
    int a,b,m,n;

    printf("두 정수를 입력하세요. : ");
    scanf("%d %d",&a,&b);

    m=a; n=b;
    while (m!=n){
        if (m>n)
            m=m-n;
        else
            n=n-m;
    }
    printf("최대공약수 = %d\n",m);

    return 0;
}
