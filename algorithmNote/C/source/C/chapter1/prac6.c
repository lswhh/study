/*
 * ---------------------------
 *     ��Ŭ���� ȣ���� #2    *
 * ---------------------------
 */

#include <stdio.h>

int main(void)
{
    int a,b,m,n,k;

    printf("�� ������ �Է��ϼ���. : ");
    scanf("%d %d",&a,&b);

    m=a; n=b;
    do {
        k=m % n;
        m=n; n=k;
    } while(k!=0);
    printf("�ִ����� = %d\n",m);

    return 0;
}
