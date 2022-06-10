/*
 * --------------------------------------------------
 *      ��͸� �̿����� ���� ���� Ž�� Ʈ�� ��ȸ    *
 * --------------------------------------------------
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

void treewalk(struct tnode *p)   /* ��͸� �̿����� ���� Ʈ���� ��ȸ */
{
    struct tnode *q,*w[128];
    int sp=0;

    q=p;
    while (!(sp==0 && q==NULL)) {
        while (q!=NULL) {         /* �ִ��� ���� ���� �̵� */
            w[sp++]=q;           /* �θ����� ��ġ�� ���ÿ� ���� */
            q=q->left;
        }
        sp--;                    /* �ٷ� ���� �θ���� ���ư� */
        printf("%s\n",w[sp]->name);
        q=w[sp]->right;          /* ������ ���� �̵� */
    }
}

struct tnode *gentree(struct tnode *p,char *w)  /* Ʈ���� �����ϴ� ��� ȣ�� */
{
    if (p==NULL) {
        p=talloc();
        strcpy(p->name,w);
        p->left=p->right=NULL;
    }
    else if (strcmp(p->name,w)<0)
        p->right=gentree(p->right,w);
    else
        p->left=gentree(p->left,w);
    return p;
}

struct tnode *talloc(void)     /* �޸� �Ҵ� */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

