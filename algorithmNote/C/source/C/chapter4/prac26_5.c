/*
 * --------------------------------------
 *      유클리드 호제법 (재귀해 #2)     *
 * --------------------------------------
 */

#include <stdio.h>

int gcd(int,int);

int main(void)
{
    int a,b;

    printf("두 정수를 입력하세요. : ");
    scanf("%d %d",&a,&b);

    printf("최대공약수=%d\n",gcd(a,b));

	return 0;
}

int gcd(int m,int n)
{
    if (n==0)
        return m;
    else
        return gcd(n,m % n);
}

