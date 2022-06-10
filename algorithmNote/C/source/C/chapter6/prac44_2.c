/*
 * ---------------------------------------------
 *      이진 탐색 트리  (참조에 의한 호출)     *
 * ---------------------------------------------
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

void gentree(struct tnode **p,char *w)  /* 트리를 생성하는 재귀 함수 */
{                                       /* 참조에 의한 호출     */
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

struct tnode *talloc(void)     /* 메모리 할당 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

