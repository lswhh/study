/*
 * -----------------------------------------
 *      ��������� ����Ʈ�� (�迭 �̿�)    *
 * -----------------------------------------
 */

#include <stdio.h>

#define Max 100
#define nil -1

int main(void)
{
    struct tnode {
        int left;           /* ������ ����Ű�� ������ */
        char node[30];
        int right;          /* �������� ����Ű�� ������ */
    };
    static struct tnode a[Max]={{1  ,"�������Դϱ�?"  ,2},
                                {3  ,"�����Դϱ�?"    ,4},
                                {nil,"�̺���"      ,nil},
                                {nil,"����"    ,nil},
                                {5  ,"������Դϱ�?"    ,6},
                                {nil,"������",nil},
                                {nil,"�����"       ,nil}};
    int p,lp=6,c;
    int flag=0;

    do {
        p=0;
        if (flag)
            while ((c=getchar()) != '\n');

        while (a[p].left!=nil)           /* Ʈ�� Ž�� */
        {
            printf("%s (y/n) ",a[p].node);
            c=getchar();
            if (c=='y' || c=='Y')
                p=a[p].left;
            else
                p=a[p].right;
            while ((c=getchar()) != '\n');
        }

        printf("���� %s �Դϴ�.\n�½��ϱ�? (y/n) ",a[p].node);
        c=getchar();

        if (c=='n' || c=='N')             /* �н���� */
        {
            a[lp+1]=a[p];                 /* ��� �̵� */
                                          /* ���ο� ��� ���� */
            printf("����� ������? ");scanf("%s",a[lp+2].node);
            a[lp+2].left=a[lp+2].right=nil;
                                          /* ���� ��� ���� */
            printf("%s �� %s �� �����ϴ� ������? ",a[lp+1].node,a[lp+2].node);
            scanf("%s",a[p].node);
            printf("yes �׸��� %s (��)�� �ϰڽ��ϱ�? (y/n) ",a[lp+1].node);
            c=getchar();

            if (c=='Y' || c=='y') {        /* �ڽ� ��� ���� */
                a[p].left=lp+1; a[p].right=lp+2;
            }
            else {
                a[p].left=lp+2; a[p].right=lp+1;
            }
            lp=lp+2;
        }
        while ((c=getchar()) != '\n');
    } while (flag=1, printf("��� �ϰڽ��ϱ�? (y/n) "), c=getchar(), c=='y' || c=='Y');

    return 0;
}
