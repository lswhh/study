/*
 * ---------------------------------------
 *      ���� ���� ����Ʈ ������ �ۼ�     *
 * ---------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tfield {
    struct tfield *left;    /* ������ ������ */
    char name[20];          /* �̸�       */
    char tel[20];           /* ��ȭ��ȣ   */
    struct tfield *right;   /* ������ ������ */
};

struct tfield *talloc(void);

int main(void)
{
    struct tfield *head,*tail,*p;

    tail=NULL;              /* ������ ����Ʈ ���� */
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF) {
        p->left=tail;
        tail=p;
    }

    p=tail;                 /* ������ ����Ʈ ���� */
    head=NULL;
    while (p!=NULL) {
        p->right=head;
        head=p;
        p=p->left;
    }

    printf("\n������ ����Ʈ\n");
    p=head;                 /* ���������� ����Ʈ ��� */
    while (p!=NULL) {
        printf("%15s%15s\n",p->name,p->tel);
        p=p->right;
    }

    printf("\n������ ����Ʈ\n");
    p=tail;                 /* ���������� ����Ʈ ��� */
    while (p!=NULL) {
        printf("%15s%15s\n",p->name,p->tel);
        p=p->left;
    }

	return 0;
}

struct tfield *talloc(void)     /* �޸� �Ҵ� */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

