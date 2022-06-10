/*
 * ---------------------------------------------------
 *      질의응답과 결정 트리 (동적 메모리 이용)      *
 * ---------------------------------------------------
 */

#include <stdio.h>
#include <malloc.h>

struct tnode {
    struct tnode *left;        /* 왼쪽 자식노드를 가리키는 포인터 */
    char node[30];
    struct tnode *right;       /* 오른쪽 자식노드를 가리키는 포인터 */
};
struct tnode *talloc(void);

int main(void)
{
    struct tnode *root,*p,*q1,*q2;
    int c;
    int flag=0;

    root=talloc();
    printf("초기 노드는? ");scanf("%s",root->node);
    root->left=root->right=NULL;

    do {
        p=root;                             /* 트리 탐색 */
        if (flag)
            while ((c=getchar()) != '\n');

        while (p->left!=NULL)
        {
            printf("%s (y/n) ",p->node);
            c=getchar();
            if (c=='Y' || c=='y')
                p=p->left;
            else
                p=p->right;

            if (p->left!=NULL)
                while ((c=getchar()) != '\n');
        }
        while ((c=getchar()) != '\n');

        printf("답은 %s 입니다.\n맞습니까? (y/n) ",p->node);
        c=getchar();

        if (c=='n' || c=='N')           /* 학습기능 */
        {
            q1=talloc(); *q1=*p;        /* 노드 이동 */

            q2=talloc();                /* 새로운 노드 생성 */
            printf("당신의 생각은? ");scanf("%s",q2->node);
            q2->left=q2->right=NULL;    /* 질문 노드 생성 */
            printf("%s 와(과) %s 을(를) 구별하는 질문은? ",q1->node,q2->node);
            scanf("%s",p->node);
            printf("yes 항목은 %s (으)로 하겠습니까? (y/n) ",q1->node);
            c=getchar();
            if (c=='Y' || c=='y')      /* 자식 노드 연결 */
            {
                p->left=q1; p->right=q2;
            }
            else
            {
                p->left=q2; p->right=q1;
            }
        }
        while ((c=getchar()) != '\n');

    } while (flag=1, printf("계속 하겠습니까? (y/n) "), c=getchar(),c=='Y' || c=='y');

    return 0;
}

struct tnode *talloc(void)            /* 메모리 할당 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
