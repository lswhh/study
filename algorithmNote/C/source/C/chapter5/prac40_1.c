/*
 * -------------------------------------------------
 *      �ڱ����� Ž�� (�� ��� ������ �̵�)      *
 * -------------------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tfield {
    char name[20];             /* �̸� */
    char tel[20];              /* ��ȭ��ȣ */
    struct tfield *pointer;    /* ���� ��带 ����Ű�� ������ */
};

struct tfield *talloc(void);

int main(void)
{
    char key[20];
    struct tfield *head,*p,*old1,*old2,*q;

    head=NULL;                /* ����Ʈ ���� */
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF) {
        p->pointer=head;
        head=p;
    }
    p=talloc();               /* dummy ��� */
    p->pointer=head;
    head=p;
                                                       /* Ž�� */
    while (printf("\nKey Name ? "),scanf("%s",key)!=EOF) {
        p=head->pointer;
        old1=old2=head;
        while (p!=NULL) {
            if (strcmp(key,p->name)==0) {
                printf("%15s%15s\n",p->name,p->tel);
                if (p!=head->pointer) {      /* ù ��尡 �ƴ� ��� */
                    q=old1->pointer;         /* ���� ���� ��ȯ     */
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

struct tfield *talloc(void)     /* �޸� �Ҵ� */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

