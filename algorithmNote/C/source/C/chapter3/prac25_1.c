/*
 * ----------------------
 *      �ؽ� (hash)     *
 * ----------------------
 */

#include <stdio.h>
#include <string.h>

#define TableSize 1050
#define ModSize      1000

int hash(char *);

struct tel{             /* ������ ���̺� */
    char name[12];
    char telnum[12];
    int empty;
}dat[TableSize];

int main(void)
{
    int n;
    char a[12],b[12];

    printf("�̸� ��ȭ��ȣ\n");
    while (scanf("%s %s",a,b)!=EOF) {
        n=hash(a);
        while (dat[n].empty==1 && n<TableSize)
            n++;
        if (n<TableSize) {
            strcpy(dat[n].name,a);
            strcpy(dat[n].telnum,b);
            dat[n].empty=1;
        }
        else
            printf("���̺��� ���� á���ϴ�.\n");
    }

    rewind(stdin);
    printf("�˻��� �����͸� �Է��ϼ���.\n");
    while (scanf("%s",a)!=EOF) {
        n=hash(a);
        while (strcmp(a,dat[n].name)!=0 && n<TableSize)
            n++;
        if (n<TableSize)
            printf("%15s%15s\n",dat[n].name,dat[n].telnum);
        else
            printf("�����͸� ã�� �� �����ϴ�.\n");
    }

    return 0;
}
int hash(char *s)        /* �ؽ��Լ� */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}
