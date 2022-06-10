/*
 * ------------------------------
 *      이진 탐색 트리 작성     *
 * ------------------------------
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

int main(void)
{
    char dat[12];
    struct tnode *root,*p,*old;

    root=talloc();                  /* 루트 노드 */
    scanf("%s",root->name);
    root->left=root->right=NULL;

    while (scanf("%s",dat)!=EOF) {
        p=root;                     /* 트리 탐색 */
        while (p!=NULL) {
            old=p;
            if (strcmp(dat,p->name)<=0)
                p=p->left;
            else
                p=p->right;
        }
        p=talloc();                 /* 새로운 노드 연결 */
        strcpy(p->name,dat);
        p->left=p->right=NULL;
        if (strcmp(dat,old->name)<=0)
            old->left=p;
        else
            old->right=p;
    }

	p=root;                    /* 최소값 노드 탐색 */
	while (p->left!=NULL)
		p=p->left;
	printf("최소값 노드 : %s\n",p->name);

	p=root;                    /* 최대값 노드 탐색 */
	while (p->right!=NULL)
		p=p->right;
	printf("최대값 노드 : %s\n",p->name);

	return 0;
}

struct tnode *talloc(void)     /* 메모리 할당 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

