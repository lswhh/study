/*
 * ---------------------------------------------
 *      이중 연결 원형 리스트 데이터 작성      *
 * ---------------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tfield {
    struct tfield *left;    /* 역방향 포인터 */
    char name[20];          /* 이름       */
    char tel[20];           /* 전화번호   */
    struct tfield *right;   /* 정방향 포인터 */
};

struct tfield *talloc(void);

int main(void)
{
    struct tfield *head,*p;

    head=talloc();                  /* dummy 노드 생성 */
    head->left=head->right=head;

    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF) {
        p->right=head;
        p->left=head->left;
        head->left->right=p;
        head->left=p;
    }

    printf("\n정방향 리스트\n");
    p=head->right;
    while (p!=head) {
        printf("%15s%15s\n",p->name,p->tel);
        p=p->right;
    }
    printf("\n역방향 리스트\n");
    p=head->left;
    while (p!=head) {
        printf("%15s%15s\n",p->name,p->tel);
        p=p->left;
    }

	return 0;
}

struct tfield *talloc(void)     /* 메모리 할당 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

