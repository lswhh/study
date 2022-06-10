/*
 * --------------------------------------------
 *      ���׽� Ʈ���� �̿��� ����� ���      *
 * --------------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tnode {
    struct tnode *left;     /* ���� �κ� Ʈ���� ����Ű�� ������ */
    int ope;                /* �׸� */
    struct tnode *right;    /* ������ �κ� Ʈ���� ����Ű�� ������ */
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *,char *);
void postfix(struct tnode *);

int main(void)
{
    struct tnode *root;
	char exp[] = "53*64+2/-";

    root=NULL;
    root=gentree(root,exp);

    postfix(root);         /* ���׽��� ��� */
    printf("value=%d\n",root->ope);

	return 0;
}

struct tnode *gentree(struct tnode *p,char *w)  /* ���׽� Ʈ�� ���� */
{
    int n;

    n=strlen(w);
    p=talloc();                     /* ������ ���ڷ� ���ο� ��带 ����� */
    if ('0'<=w[n-1] && w[n-1]<='9')        /* �����̸� ��ġ�� ��ȯ */
        p->ope=w[n-1]-'0';
    else
        p->ope=w[n-1];
    w[n-1]='\0';                /* ������ ���� ���� */
    if (!(p->ope=='-' || p->ope=='+' || p->ope=='*' || p->ope=='/')) {
        p->left=p->right=NULL;
    }
    else {
        p->right=gentree(p->right,w);
        p->left=gentree(p->left,w);
    }
    return p;
}

void postfix(struct tnode *p)    /* ���׽� Ʈ�� ��� */
{
    if (p!=NULL) {
        postfix(p->left);
        postfix(p->right);
        switch (p->ope){
            case '+': p->ope=(p->left->ope)+(p->right->ope);break;
            case '-': p->ope=(p->left->ope)-(p->right->ope);break;
            case '*': p->ope=(p->left->ope)*(p->right->ope);break;
            case '/': p->ope=(p->left->ope)/(p->right->ope);break;
        }
    }
}

struct tnode *talloc(void)     /* �޸� �Ҵ� */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

