/*
 * -----------------------
 *      다항식 트리      *
 * -----------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tnode {
    struct tnode *left;     /* 왼쪽 부분 트리를 가리키는 포인터 */
    char ope;               /* 항목 */
    struct tnode *right;    /* 오른쪽 부분 트리를 가리키는 포인터 */
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

    printf("prefix  = ");prefix(root);        /* 다항식 트리의 순회 */
    printf("\ninfix   = ");infix(root);
    printf("\npostfix = ");postfix(root);

    printf("\n");
    return 0;
}

struct tnode *gentree(struct tnode *p,char *w)  /* 다항식 트리 생성 */
{
    int n;

    n=strlen(w);
    p=talloc();
    p->ope=w[n-1];         /* 마지막 문자로 새로운 노드를 만든다 */
    w[n-1]='\0';           /* 마지막 문자 제거 */
    if (!(p->ope=='-' || p->ope=='+' || p->ope=='*' || p->ope=='/')) {
        p->left=p->right=NULL;
    }
    else {
        p->right=gentree(p->right,w);
        p->left=gentree(p->left,w);
    }
    return p;
}

void prefix(struct tnode *p)     /* 전위순회 */
{
    if (p!=NULL) {
        putchar(p->ope);
        prefix(p->left);
        prefix(p->right);
    }
}

void infix(struct tnode *p)      /* 중위순회 */
{
    if (p!=NULL) {
        infix(p->left);
        putchar(p->ope);
        infix(p->right);
    }
}

void postfix(struct tnode *p)    /* 후위순회 */
{
    if (p!=NULL) {
        postfix(p->left);
        postfix(p->right);
        putchar(p->ope);
    }
}

struct tnode *talloc(void)       /* 메모리 할당 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
