/*
 * -------------------------------------------
 *      ���� Ž�� Ʈ���� ��ȸ(traversal)     *
 * -------------------------------------------
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
struct tnode *gentree(struct tnode *,char *);
void treewalk(struct tnode *);

int main(void)
{
    char dat[12];
    struct tnode *root;

    root=NULL;
    while (scanf("%s",dat)!=EOF) {
        root=gentree(root,dat);
    }
    treewalk(root);

    return 0;
}

void treewalk(struct tnode *p)  /* Ʈ���� ��ȸ */
{
    if (p!=NULL) {
        treewalk(p->left);
        printf("%s\n",p->name);
        treewalk(p->right);
    }
}

struct tnode *gentree(struct tnode *p,char *w)
                      /* Ʈ���� �����ϴ� ��� �Լ� */
{
    if (p==NULL) {
        p=talloc();
        strcpy(p->name,w);
        p->left=p->right=NULL;
    }
    else if (strcmp(w,p->name)<0)
        p->left=gentree(p->left,w);
    else
        p->right=gentree(p->right,w);
    return p;
}

struct tnode *talloc(void)     /* �޸� �Ҵ� */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
