/*
 * --------------------------------------------
 *      다항식 트리를 이용한 결과값 계산      *
 * --------------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tnode {
    struct tnode *left;     /* 왼쪽 부분 트리를 가리키는 포인터 */
    int ope;                /* 항목 */
    struct tnode *right;    /* 오른쪽 부분 트리를 가리키는 포인터 */
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

    postfix(root);         /* 다항식의 계산 */
    printf("value=%d\n",root->ope);

	return 0;
}

struct tnode *gentree(struct tnode *p,char *w)  /* 다항식 트리 생성 */
{
    int n;

    n=strlen(w);
    p=talloc();                     /* 마지막 문자로 새로운 노드를 만든다 */
    if ('0'<=w[n-1] && w[n-1]<='9')        /* 정수이면 수치로 변환 */
        p->ope=w[n-1]-'0';
    else
        p->ope=w[n-1];
    w[n-1]='\0';                /* 마지막 문자 제거 */
    if (!(p->ope=='-' || p->ope=='+' || p->ope=='*' || p->ope=='/')) {
        p->left=p->right=NULL;
    }
    else {
        p->right=gentree(p->right,w);
        p->left=gentree(p->left,w);
    }
    return p;
}

void postfix(struct tnode *p)    /* 다항식 트리 계산 */
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

struct tnode *talloc(void)     /* 메모리 할당 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

