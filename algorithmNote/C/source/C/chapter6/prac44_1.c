/*
 * -----------------------------------------
 *      재귀를 이용한 이진 탐색 트리 #2    *
 * -----------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tnode {
    struct tnode *left;     /* 왼쪽 부분트리를 가리키는 포인터 */
    char name[12];          /* 이름 */
    struct tnode *right;    /* 오른쪽 부분트리를 가리키는 포인터 */
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *,char *);
struct tnode *search(struct tnode *,char *);

int main(void)
{
    char key[12];
    struct tnode *root,*p;

    root=NULL;                      /* 트리 생성 */
    while (scanf("%s",key)!=EOF) {
        root=gentree(root,key);
    }

    rewind(stdin);
    while (printf("Search name -->"),scanf("%s",key)!=EOF) {
        if ((p=search(root,key))!=NULL)
            printf("%s 을 찾았습니다.\n",p->name);
        else
            printf("찾지 못 했습니다.\n");
    }

    return 0;
}

struct tnode *search(struct tnode *p,char *key)  /* 트리 탐색 */
{
    if (p==NULL || strcmp(key,p->name)==0)
        return p;
    if (strcmp(key,p->name)<0)
        return search(p->left,key);
    else
        return search(p->right,key);
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
