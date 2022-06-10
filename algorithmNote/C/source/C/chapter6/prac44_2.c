/*
 * ---------------------------------------------
 *      ���� Ž�� Ʈ��  (������ ���� ȣ��)     *
 * ---------------------------------------------
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
void gentree(struct tnode **,char *);

int main(void)
{
    char dat[12];
    struct tnode *root,*p;

    root=NULL;
    while (scanf("%s",dat)!=EOF) {
        gentree(&root,dat);
    }
    p=root;
    while (p!=NULL) {
        printf("%s\n",p->name);
        p=p->left;
    }

	return 0;
}

void gentree(struct tnode **p,char *w)  /* Ʈ���� �����ϴ� ��� �Լ� */
{                                       /* ������ ���� ȣ��     */
    if ((*p)==NULL) {
        (*p)=talloc();
        strcpy((*p)->name,w);
        (*p)->left=(*p)->right=NULL;
    }
    else if(strcmp(w,(*p)->name)<0)
        gentree(&((*p)->left),w);
    else
        gentree(&((*p)->right),w);
}

struct tnode *talloc(void)     /* �޸� �Ҵ� */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

