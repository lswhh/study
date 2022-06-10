/*
 * -------------------------------------------
 *      리스트 데이터 작성 (dummy 노드)      *
 * -------------------------------------------
 */

#include <stdio.h>
#include <malloc.h>

struct tfield {
    char name[20];             /* 이름 */
    char tel[20];              /* 전화번호 */
    struct tfield *pointer;    /* 다음 노드를 가리키는 포인터 */
};

struct tfield *talloc(void);

int main(void)
{
    struct tfield *head,*p,*old;

    head=talloc();      /* dummy 노드 생성 */
    old=head;
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF) {
        old->pointer=p;
        old=p;
    }
    old->pointer=NULL;

    p=head->pointer;
    while (p!=NULL) {
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }

	return 0;
}

struct tfield *talloc(void)     /* 메모리 할당 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

