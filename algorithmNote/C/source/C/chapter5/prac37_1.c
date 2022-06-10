/*
 * ---------------------------------------------
 *      ���� ���� ���� ����Ʈ ������ �ۼ�      *
 * ---------------------------------------------
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
    struct tfield *head,*p;

    head=talloc();                  /* dummy ��� ���� */
    head->left=head->right=head;

    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF) {
        p->right=head;
        p->left=head->left;
        head->left->right=p;
        head->left=p;
    }

    printf("\n������ ����Ʈ\n");
    p=head->right;
    while (p!=head) {
        printf("%15s%15s\n",p->name,p->tel);
        p=p->right;
    }
    printf("\n������ ����Ʈ\n");
    p=head->left;
    while (p!=head) {
        printf("%15s%15s\n",p->name,p->tel);
        p=p->left;
    }

	return 0;
}

struct tfield *talloc(void)     /* �޸� �Ҵ� */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

