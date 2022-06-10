/*
 * --------------------------------------------------
 *      재귀를 이용하지 않은 이진 탐색 트리 순회    *
 * --------------------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tnode {
    struct tnode *left;     /* 왼쪽 부분 트리를 가리키는 포인터 */
    char name[12];          /* 이름 */
    struct tnode *right;    /* 오른쪽 부분 트리를 가리키는 포인터 */
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

void treewalk(struct tnode *p)   /* 재귀를 이용하지 않은 트리의 순회 */
{
    struct tnode *q,*w[128];
    int sp=0;

    q=p;
    while (!(sp==0 && q==NULL)) {
        while (q!=NULL) {         /* 최대한 왼쪽 노드로 이동 */
            w[sp++]=q;           /* 부모노드의 위치를 스택에 저장 */
            q=q->left;
        }
        sp--;                    /* 바로 이전 부모노드로 돌아감 */
        printf("%s\n",w[sp]->name);
        q=w[sp]->right;          /* 오른쪽 노드로 이동 */
    }
}

struct tnode *gentree(struct tnode *p,char *w)  /* 트리를 생성하는 재귀 호출 */
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

struct tnode *talloc(void)     /* 메모리 할당 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

