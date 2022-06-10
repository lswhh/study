/*
 * -----------------------
 *      ���׽� Ʈ��      *
 * -----------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tnode {
    struct tnode *left;     /* ���� �κ� Ʈ���� ����Ű�� ������ */
    char ope;               /* �׸� */
    struct tnode *right;    /* ������ �κ� Ʈ���� ����Ű�� ������ */
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *,char *);
void prefix(struct tnode *);
void infix(struct tnode *);
void postfix(struct tnode *);

int main(void)
{
    struct tnode *root;
    char exp[] = "ab*cd+e/-";

    root=NULL;
    root=gentree(root,exp);

    printf("prefix  = ");prefix(root);        /* ���׽� Ʈ���� ��ȸ */
    printf("\ninfix   = ");infix(root);
    printf("\npostfix = ");postfix(root);

    printf("\n");
    return 0;
}

struct tnode *gentree(struct tnode *p,char *w)  /* ���׽� Ʈ�� ���� */
{
    int n;

    n=strlen(w);
    p=talloc();
    p->ope=w[n-1];         /* ������ ���ڷ� ���ο� ��带 ����� */
    w[n-1]='\0';           /* ������ ���� ���� */
    if (!(p->ope=='-' || p->ope=='+' || p->ope=='*' || p->ope=='/')) {
        p->left=p->right=NULL;
    }
    else {
        p->right=gentree(p->right,w);
        p->left=gentree(p->left,w);
    }
    return p;
}

void prefix(struct tnode *p)     /* ������ȸ */
{
    if (p!=NULL) {
        putchar(p->ope);
        prefix(p->left);
        prefix(p->right);
    }
}

void infix(struct tnode *p)      /* ������ȸ */
{
    if (p!=NULL) {
        infix(p->left);
        putchar(p->ope);
        infix(p->right);
    }
}

void postfix(struct tnode *p)    /* ������ȸ */
{
    if (p!=NULL) {
        postfix(p->left);
        postfix(p->right);
        putchar(p->ope);
    }
}

struct tnode *talloc(void)       /* �޸� �Ҵ� */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
