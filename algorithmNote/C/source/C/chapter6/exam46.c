/*
 * ---------------------------------------
 *      ���� Ž�� Ʈ���� ������ ��ȸ     *
 * ---------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tnode {
    struct tnode *left;     /* ���� �κ� Ʈ���� ����Ű�� ������*/
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

void treewalk(struct tnode *p)  /* Ʈ���� ������ ��ȸ */
{
    struct tnode *q[128],       /* ������ ���̺� */
                 *w[128];       /* �ӽ��۾��� */
    int i,child,n,level;

    child=1; q[0]=p; level=0;   /* �ʱⰪ */
    do {
        n=0;
        printf("level %d :",level);
        for (i=0;i<child;i++) {
            printf("%12s",q[i]->name); /* ��� ��� */
            /* �ٷ� �Ʒ� ������ �ڽĳ�带 ����Ű�� �����͸� ���ÿ� ���� */
            if (q[i]->left!=NULL)
                w[n++]=q[i]->left;
            if (q[i]->right!=NULL)
                w[n++]=q[i]->right;
        }
        printf("\n");
        child=n;            /* �ٷ� �Ʒ� ������ �ڽĳ�� �� */
        for (i=0;i<child;i++)
            q[i]=w[i];
        level++;
    } while (child!=0);
}

struct tnode *gentree(struct tnode *p,char *w)  /* Ʈ���� �����ϴ� �Լ� */
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

