/*
 * -------------------------------
 *      �ϳ����� ž (�����)     *
 * -------------------------------
 */

#include <stdio.h>

void hanoi(int,char,char,char);

int main(void)
{
    int n;
    printf("������ ����? ");
    scanf("%d",&n);

    hanoi(n,'a','b','c');

	return 0;
}

void hanoi(int n,char a,char b,char c)  /* ��� �Լ� */
{
    if (n>0) { 
        hanoi(n-1,a,c,b);    
        printf("%d�� ������ %c ���� %c �� �ű�\n",n,a,b);
        hanoi(n-1,c,b,a);
    }
}

