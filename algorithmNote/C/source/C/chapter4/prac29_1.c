/*
 * --------------------------------------------
 *      �ϳ����� ž (�μ��� �ϳ� ���δ�.)     *
 * --------------------------------------------
 */

#include <stdio.h>

void hanoi(int,char,char);
#define Total 'a'+'b'+'c'

int main(void)
{
    int n;
    printf("������ ����? ");
    scanf("%d",&n);

    hanoi(n,'a','b');

	return 0;
}

void hanoi(int n,char a,char b)  /* ��� �Լ� */
{
    if (n>0) {
        hanoi(n-1,a,Total-(a+b));
        printf("%d�� ������ %c ���� %c �� �ű�\n",n,a,b);
        hanoi(n-1,Total-(a+b),b);
    }
}

