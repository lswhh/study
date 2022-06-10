/*
 * -----------------------------------
 *      ����Ʈ�� ������ �����ϱ�     *
 * -----------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tfield {
    char name[20];             /* �̸� */
    char tel[20];              /* ��ȭ��ȣ */
    struct tfield *pointer;    /* ���� ��带 ����Ű�� ������ */
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

void link(char *key)    /* ����Ʈ�� ������ �߰� */
{
    struct tfield *p,*n;

    n=talloc();
    printf("�߰��� ������ : ");
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
    printf("Ű �����͸� ã�� �� �����ϴ�.\n");

}

void genlist(void)        /* ����Ʈ ���� */
{
    struct tfield *p;

    head=NULL;
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF) {
        p->pointer=head;
        head=p;
    }
}

void displist(void)      /* ����Ʈ ��� */
{
    struct tfield *p;
    p=head;
    while (p!=NULL) {
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
}

struct tfield *talloc(void)     /* �޸� �Ҵ� */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

