/*
 * -----------------------------------
 *      리스트에 데이터 삽입하기     *
 * -----------------------------------
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
void link(char *);

int main(void)
{
    char key[32];

    genlist();
    displist();

    while (printf("Key Name : "),scanf("%s",key)!=EOF) {
        link(key);
    }
    printf("\n");
    displist();

	return 0;
}

void link(char *key)         /* 리스트에 데이터 추가 */
{
    struct tfield *p,*n;

    n=talloc();
    printf("추가할 데이터 : ");
    scanf("%s %s",n->name,n->tel);

    p=head;
    while (p!=NULL) {
        if (strcmp(key,p->name)==0) {
            n->pointer=p->pointer;
            p->pointer=n;
            return;
        }
        p=p->pointer;
    }
    printf("%s 를 찾을 수 없으므로 첫 노드로 추가합니다.\n",key);
    n->pointer=head;
    head=n;
}

void genlist(void)           /* 리스트 생성 */
{
    struct tfield *p;

    head=NULL;
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF) {
        p->pointer=head;
        head=p;
    }
}

void displist(void)           /* 리스트 출력 */
{
    struct tfield *p;
    p=head;
    while (p!=NULL) {
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
}

struct tfield *talloc(void)     /* 메모리 할당 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

