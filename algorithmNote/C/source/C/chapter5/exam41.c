/*
 * ------------------------------------------------
 *      ����Ʈ�� �̿��� �ؽ� (ù ���� �߰�)     *
 * ------------------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define TableSize 1000
#define ModSize   1000

int hash(char *);

struct tfield {
    char name[12];
    char tel[12];
    struct tfield *pointer;
} *dat[TableSize];               /* ������ ���̺� */

struct tfield *talloc(void);

int main(void)
{
    int n;
    char key[12];
    struct tfield *p;

    for (n=0;n<TableSize;n++)    /* ������ ���̺� �ʱ�ȭ */
        dat[n]=NULL;

    printf("�̸�  ��ȭ��ȣ\n");
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF) {
        n=hash(p->name);         /* �ؽ� */
        p->pointer=dat[n];       /* ù ���� �߰� */
        dat[n]=p;
    }
    
    rewind(stdin);               /* Ž�� */
    printf("\nŽ���� �����͸� �Է��Ͻñ� �ٶ��ϴ�.\n");
    while (scanf("%s",key)!=EOF) {
        n=hash(key);
        p=dat[n];
        while (p!=NULL) {
            if (strcmp(key,p->name)==0)
                printf("%15s%15s\n",p->name,p->tel);
            p=p->pointer;
        }
    }

    return 0;
}

int hash(char *s)    /* �ؽ��Լ� */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}

struct tfield *talloc(void)   /* �޸� �Ҵ� */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
