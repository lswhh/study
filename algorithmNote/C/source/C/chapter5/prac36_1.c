/*
 * -------------------------------------
 *      리스트에서 데이터 삭제하기     *
 * -------------------------------------
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
void genlist(void);
void displist(void);
void del(char *);

int main(void)
{
    char key[32];

    genlist();
    displist();

    while (printf("Key Name : "),scanf("%s",key)!=EOF) {
        del(key);
    }
    printf("\n");
    displist();

	return 0;
}

void del(char *key)            /* 리스트에서 데이터 삭제 */
{
    struct tfield *p;

    p=head;
    while (p->pointer!=NULL) {
        if (strcmp(key,p->pointer->name)==0) {
            p->pointer=p->pointer->pointer;
            return;
        }
        p=p->pointer;
    }
    printf("키 데이터를 찾을 수 없습니다.\n");
}

void genlist(void)      /* dummy 노드를 추가한 리스트 */
{
    struct tfield *p;

    head=NULL;
    do {
        p=talloc();
        p->pointer=head;
        head=p;
    } while (scanf("%s %s",p->name,p->tel)!=EOF);
}

void displist(void)           /* 리스트 출력 */
{
    struct tfield *p;
    p=head->pointer;
    while (p!=NULL) {
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
}

struct tfield *talloc(void)     /* 메모리 할당 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

