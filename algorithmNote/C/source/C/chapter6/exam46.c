/*
 * ---------------------------------------
 *      이진 탐색 트리의 레벨별 순회     *
 * ---------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tnode {
    struct tnode *left;     /* 왼쪽 부분 트리를 가리키는 포인터*/
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

void treewalk(struct tnode *p)  /* 트리의 레벨별 순회 */
{
    struct tnode *q[128],       /* 포인터 테이블 */
                 *w[128];       /* 임시작업용 */
    int i,child,n,level;

    child=1; q[0]=p; level=0;   /* 초기값 */
    do {
        n=0;
        printf("level %d :",level);
        for (i=0;i<child;i++) {
            printf("%12s",q[i]->name); /* 노드 출력 */
            /* 바로 아래 레벨의 자식노드를 가리키는 포인터를 스택에 저장 */
            if (q[i]->left!=NULL)
                w[n++]=q[i]->left;
            if (q[i]->right!=NULL)
                w[n++]=q[i]->right;
        }
        printf("\n");
        child=n;            /* 바로 아래 레벨의 자식노드 수 */
        for (i=0;i<child;i++)
            q[i]=w[i];
        level++;
    } while (child!=0);
}

struct tnode *gentree(struct tnode *p,char *w)  /* 트리를 생성하는 함수 */
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

