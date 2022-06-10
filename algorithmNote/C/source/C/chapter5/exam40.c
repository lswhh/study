/*
 * ---------------------------------------------
 *      자기재편성 탐색(첫 노드로 옮기기)      *
 * ---------------------------------------------
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
    struct tfield *head,*p,*old;

    head=NULL;                  /* 리스트 생성 */
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF){
        p->pointer=head;
        head=p;
    }
                                                        /* 탐색 */
    while (printf("\nKey Name ? "),scanf("%s",key)!=EOF) {
        p=old=head;
        while (p!=NULL) {
            if (strcmp(key,p->name)==0) {
                printf("%15s%15s\n",p->name,p->tel);
                if (p!=head) {
                    old->pointer=p->pointer;    /* 맨 앞으로 옮기기 */
                    p->pointer=head;
                    head=p;
                }
                break;
            }
            old=p;
            p=p->pointer;
        }
    }

    return 0;
}

struct tfield *talloc(void)     /* 메모리 할당 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
