/*
 * --------------------------------------------------------
 *      ���� �޸𸮸� �̿��� Ʈ���� ��ũ�� �����ϱ�     *
 * --------------------------------------------------------
 */

#include <stdio.h>
#include <malloc.h>

#define Rec 34L         /* ���ڵ� ũ�� */
#define Leaf -1         /* �ٳ�� */
FILE *fp;

struct tnode {
    struct tnode *left;     /* ���� �ڽ� ��带 ����Ű�� ������ */
    char node[30];
    struct tnode *right;    /* ������ �ڽ� ��带 ����Ű�� ������ */
};

struct tnode *talloc(void);
struct tnode *readtree(struct tnode *);
void writetree(struct tnode *);

int main(void)
{
    struct tnode *root=NULL,*p,*q1,*q2;
    int c;
    int flag=0;

    if ((fp=fopen("dbase.dat","r"))==NULL) {
        root=talloc();
        printf("�ʱ� ����? ");scanf("%s",root->node);
        root->left=root->right=NULL;
    }
    else {
        root=readtree(root);
        fclose(fp);
    }
    do {
        p=root;                   /* Ʈ�� Ž�� */
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
            if (c=='Y' || c=='y') {      /* �ڽ� ��� ���� */
                p->left=q1; p->right=q2;
            }
            else {
                p->left=q2; p->right=q1;
            }
        }
        while ((c=getchar()) != '\n');
    } while (flag=1, printf("��� �ϰڽ��ϱ�? (y/n) "), c=getchar(),c=='Y' || c=='y');

    if ((fp=fopen("dbase.dat","w"))!=NULL)
    {
        writetree(root);
        fclose(fp);
    }

    return 0;
}

struct tnode *readtree(struct tnode *p)    /* ���Ͽ��� Ʈ�� �б� */
{
    int flag;

    p=talloc();
    fscanf(fp,"%30s%4d",p->node,&flag);
    if (flag==Leaf)
        p->left=p->right=NULL;
    else{
        p->left=readtree(p->left);
        p->right=readtree(p->right);
    }
    return p;
}

void writetree(struct tnode *p)      /* ���Ͽ� Ʈ�� ���� */
{
    if (p!=NULL) {
        if (p->left==NULL)
            fprintf(fp,"%30s%4d",p->node,Leaf);
        else
            fprintf(fp,"%30s%4d",p->node,!Leaf);
        writetree(p->left);
        writetree(p->right);
    }
}

struct tnode *talloc(void)           /* �޸� �Ҵ� */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
