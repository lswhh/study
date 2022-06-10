/*
 * -------------------------------
 *     이진 탐색 트리의 순회     *
 * -------------------------------
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

void treewalk(struct tnode *p)  /* 트리의 순회 */
{
    if (p!=NULL) {
        treewalk(p->right);
        printf("%s\n",p->name);
        treewalk(p->left);
    }
}

struct tnode *gentree(struct tnode *p,char *w)  /* 트리를 생성하는 재귀 호출 */
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

struct tnode *talloc(void)     /* 메모리 할당 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

