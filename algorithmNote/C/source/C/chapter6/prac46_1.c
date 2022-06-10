/*
 * ----------------------------------------
 *      이진 탐색 트리의 레벨별 순회      *
 * ----------------------------------------
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

void treewalk(struct tnode *p)  /* 높이에 따른 순회 */
{
    struct connect {            /* 연결관계를 나타내는 구조체 */
        struct tnode *node;     /* 자식 노드 */
        char *parent;           /* 부모 노드의 이름 */
        char direct;            /* 왼쪽 자식 노드인지 오른쪽 자식 노드인지 표시 */
    } q[128],w[128];
    int i,child,n,level;

    child=1; level=0;           /* 초기값 */
    q[0].node=p; q[0].parent="root"; q[0].direct=' ';
    do {
        n=0;
        printf("level %d :\n",level);
        for (i=0;i<child;i++) {
            printf("%12s->%c:%12s\n",q[i].parent,q[i].direct,q[i].node->name);
            /* 바로 아래 레벨의 자식 노드를 가리키는 포인터를 스택에 저장 */
            if (q[i].node->left!=NULL) {
                w[n].parent=q[i].node->name;
                w[n].direct='l';
                w[n].node=q[i].node->left;
                n++;
            }
            if (q[i].node->right!=NULL) {
                w[n].parent=q[i].node->name;
                w[n].direct='r';
                w[n].node=q[i].node->right;
                n++;
            }
        }
        child=n;            /* 바로 아래 레벨의 자식 노드 수 */
        for (i=0;i<child;i++)
            q[i]=w[i];
        level++;
    } while (child!=0);
}

struct tnode *gentree(struct tnode *p,char *w)  /* 트리를 생성하는 재귀 함수 */
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

