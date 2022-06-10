/*
 * ----------------------------------------------
 *      유클리드(Euclid) 호제법 (재귀해 #1)     *
 * ----------------------------------------------
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
    if (m==n)
        return m;
    if (m>n)
        return gcd(m-n,n);
    else
        return gcd(m,n-m);
}

