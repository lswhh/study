/*
 * ------------------------------
 *      ���� Ž�� Ʈ�� �ۼ�     *
 * ------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tnode {
    struct tnode *left;     /* ���� �κ� Ʈ���� ����Ű�� ������ */
    char name[12];          /* �̸� */
    struct tnode *right;    /* ������ �κ� Ʈ���� ����Ű�� ������ */
};

struct tnode *talloc(void);

int main(void)
{
    char dat[12];
    struct tnode *root,*p,*old;

    root=talloc();                  /* ��Ʈ ��� */
    scanf("%s",root->name);
    root->left=root->right=NULL;

    while (scanf("%s",dat)!=EOF) {
        p=root;                     /* Ʈ�� Ž�� */
        while (p!=NULL) {
            old=p;
            if (strcmp(dat,p->name)<=0)
                p=p->left;
            else
                p=p->right;
        }
        p=talloc();                 /* ���ο� ��� ���� */
        strcpy(p->name,dat);
        p->left=p->right=NULL;
        if (strcmp(dat,old->name)<=0)
            old->left=p;
        else
            old->right=p;
    }

	p=root;                    /* �ּҰ� ��� Ž�� */
	while (p->left!=NULL)
		p=p->left;
	printf("�ּҰ� ��� : %s\n",p->name);

	p=root;                    /* �ִ밪 ��� Ž�� */
	while (p->right!=NULL)
		p=p->right;
	printf("�ִ밪 ��� : %s\n",p->name);

	return 0;
}

struct tnode *talloc(void)     /* �޸� �Ҵ� */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

