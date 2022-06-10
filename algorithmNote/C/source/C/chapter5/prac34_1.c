/*
 * --------------------------------------
 *      ����Ʈ ������ �ۼ� (�Է¼�)     *
 * --------------------------------------
 */

#include <stdio.h>
#include <malloc.h>

struct tfield {
    char name[20];             /* �̸� */
    char tel[20];              /* ��ȭ��ȣ */
    struct tfield *pointer;    /* ���� ��带 ����Ű�� ������ */
};

struct tfield *talloc(void);

int main(void)
{
    struct tfield *head,*p,*old;

    head=talloc();                                    /* ��ó�� */
    scanf("%s %s",head->name,head->tel);
    old=head;
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF) {
        old->pointer=p;
        old=p;
    }
    old->pointer=NULL;                                /* ��ó�� */

    p=head;
    while (p!=NULL) {
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }

    return 0;
}

struct tfield *talloc(void)     /* �޸� �Ҵ� */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
