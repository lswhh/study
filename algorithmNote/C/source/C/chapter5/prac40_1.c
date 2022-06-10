/*
 * -------------------------------------------------
 *      자기재편성 탐색 (한 노드 앞으로 이동)      *
 * -------------------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tfield {
    char name[20];             /* 이름 */
    char tel[20];              /* 전화번호 */
    struct tfield *pointer;    /* 다음 노드를 가리키는 포인터 */
};

struct tfield *talloc(void);

int main(void)
{
    char key[20];
    struct tfield *head,*p,*old1,*old2,*q;

    head=NULL;                /* 리스트 생성 */
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF) {
        p->pointer=head;
        head=p;
    }
    p=talloc();               /* dummy 노드 */
    p->pointer=head;
    head=p;
                                                       /* 탐색 */
    while (printf("\nKey Name ? "),scanf("%s",key)!=EOF) {
        p=head->pointer;
        old1=old2=head;
        while (p!=NULL) {
            if (strcmp(key,p->name)==0) {
                printf("%15s%15s\n",p->name,p->tel);
                if (p!=head->pointer) {      /* 첫 노드가 아닌 경우 */
                    q=old1->pointer;         /* 이전 노드와 교환     */
                    old1->pointer=p;
                    old2->pointer=p->pointer;
                    p->pointer=q;
                }
                break;
            }
            old1=old2;
            old2=p;
            p=p->pointer;
        }
    }

	return 0;
}

struct tfield *talloc(void)     /* 메모리 할당 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

