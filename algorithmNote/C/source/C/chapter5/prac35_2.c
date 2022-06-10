/*
 * ---------------------------------
 *      ����Ʈ���� ������ Ž��     *
 * ---------------------------------
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

int main(void)
{
    struct tfield *head,*p,
                  sentinel;        /* ��� ��� */
    char key[20];

    head=&sentinel;                /* ��� ����� ����Ű�� ������ */
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF) {
        p->pointer=head;
        head=p;
    }

    rewind(stdin);                      /* Ž�� */
    while (printf("\nkey name : "),scanf("%s",key)!=EOF) {
        strcpy(sentinel.name,key);      /* ��� ��忡 Ű�� �����Ѵ�. */
        p=head;
        while (strcmp(p->name,key)!=0)
            p=p->pointer;
        if (p!=&sentinel)
            printf("%s %s\n",p->name,p->tel);
        else
            printf("ã�� �� �����ϴ�.\n");
    }

	return 0;
}

struct tfield *talloc(void)     /* �޸� �Ҵ� */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

