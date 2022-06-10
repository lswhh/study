/*
 * ---------------------------------------------------
 *      ��������� ���� Ʈ�� (���� �޸� �̿�)      *
 * ---------------------------------------------------
 */

#include <stdio.h>
#include <malloc.h>

struct tnode {
    struct tnode *left;        /* ���� �ڽĳ�带 ����Ű�� ������ */
    char node[30];
    struct tnode *right;       /* ������ �ڽĳ�带 ����Ű�� ������ */
};
struct tnode *talloc(void);

int main(void)
{
    struct tnode *root,*p,*q1,*q2;
    int c;
    int flag=0;

    root=talloc();
    printf("�ʱ� ����? ");scanf("%s",root->node);
    root->left=root->right=NULL;

    do {
        p=root;                             /* Ʈ�� Ž�� */
        if (flag)
            while ((c=getchar()) != '\n');

        while (p->left!=NULL)
        {
            printf("%s (y/n) ",p->node);
            c=getchar();
            if (c=='Y' || c=='y')
                p=p->left;
            else
                p=p->right;

            if (p->left!=NULL)
                while ((c=getchar()) != '\n');
        }
        while ((c=getchar()) != '\n');

        printf("���� %s �Դϴ�.\n�½��ϱ�? (y/n) ",p->node);
        c=getchar();

        if (c=='n' || c=='N')           /* �н���� */
        {
            q1=talloc(); *q1=*p;        /* ��� �̵� */

            q2=talloc();                /* ���ο� ��� ���� */
            printf("����� ������? ");scanf("%s",q2->node);
            q2->left=q2->right=NULL;    /* ���� ��� ���� */
            printf("%s ��(��) %s ��(��) �����ϴ� ������? ",q1->node,q2->node);
            scanf("%s",p->node);
            printf("yes �׸��� %s (��)�� �ϰڽ��ϱ�? (y/n) ",q1->node);
            c=getchar();
            if (c=='Y' || c=='y')      /* �ڽ� ��� ���� */
            {
                p->left=q1; p->right=q2;
            }
            else
            {
                p->left=q2; p->right=q1;
            }
        }
        while ((c=getchar()) != '\n');

    } while (flag=1, printf("��� �ϰڽ��ϱ�? (y/n) "), c=getchar(),c=='Y' || c=='y');

    return 0;
}

struct tnode *talloc(void)            /* �޸� �Ҵ� */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
