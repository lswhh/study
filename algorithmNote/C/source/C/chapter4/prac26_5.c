/*
 * --------------------------------------
 *      ��Ŭ���� ȣ���� (����� #2)     *
 * --------------------------------------
 */

#include <stdio.h>

int gcd(int,int);

int main(void)
{
    int a,b;

    printf("�� ������ �Է��ϼ���. : ");
    scanf("%d %d",&a,&b);

    printf("�ִ�����=%d\n",gcd(a,b));

	return 0;
}

int gcd(int m,int n)
{
    if (n==0)
        return m;
    else
        return gcd(n,m % n);
}

