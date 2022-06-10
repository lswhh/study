/*
 * ---------------------------------------
 *      이중 연결 리스트 데이터 작성     *
 * ---------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tfield {
    struct tfield *left;    /* 역방향 포인터 */
    char name[20];          /* 이름       */
    char tel[20];           /* 전화번호   */
    struct tfield *right;   /* 정방향 데이터 */
};

struct tfield *talloc(void);

int main(void)
{
    struct tfield *head,*tail,*p;

    tail=NULL;              /* 역방향 리스트 생성 */
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF) {
        p->left=tail;
        tail=p;
    }

    p=tail;                 /* 정방향 리스트 생성 */
    head=NULL;
    while (p!=NULL) {
        p->right=head;
        head=p;
        p=p->left;
    }

    printf("\n정방향 리스트\n");
    p=head;                 /* 정방향으로 리스트 출력 */
    while (p!=NULL) {
        printf("%15s%15s\n",p->name,p->tel);
        p=p->right;
    }

    printf("\n역방향 리스트\n");
    p=tail;                 /* 역방향으로 리스트 출력 */
    while (p!=NULL) {
        printf("%15s%15s\n",p->name,p->tel);
        p=p->left;
    }

	return 0;
}

struct tfield *talloc(void)     /* 메모리 할당 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

