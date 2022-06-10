/*
 * ---------------------------------
 *      리스트에서 데이터 탐색     *
 * ---------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tfield {
    char name[20];             /* 이름 */
    char tel[20];              /* 전화번호 */
    struct tfield *pointer;    /* 다음 노드를 가리키는 포인터 */
} *head;

struct tfield *talloc(void);

int main(void)
{
    struct tfield *head,*p,
                  sentinel;        /* 경계 노드 */
    char key[20];

    head=&sentinel;                /* 경계 노드을 가리키는 포인터 */
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF) {
        p->pointer=head;
        head=p;
    }

    rewind(stdin);                      /* 탐색 */
    while (printf("\nkey name : "),scanf("%s",key)!=EOF) {
        strcpy(sentinel.name,key);      /* 경계 노드에 키를 저장한다. */
        p=head;
        while (strcmp(p->name,key)!=0)
            p=p->pointer;
        if (p!=&sentinel)
            printf("%s %s\n",p->name,p->tel);
        else
            printf("찾을 수 없습니다.\n");
    }

	return 0;
}

struct tfield *talloc(void)     /* 메모리 할당 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

