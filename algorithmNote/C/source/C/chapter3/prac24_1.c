/*
 * ------------------------------
 *     ���ڿ� ġȯ (replace)    *
 * ------------------------------
 */

#include <stdio.h>
#include <string.h>

void replace(char *,char *,char *);
char *search(char *,char *);

int main(void)
{
    int k;
    static char text[][256]={"   --- ���޷��� ---",
                                "�� ���Ⱑ ���ܿ�",
                                "���� ������",
                                "������ ���� ���� �帮������.",
                                "������ ���",
                                "���޷���",
                                "�Ƹ� ���� ���� �濡 �Ѹ�������.",
                                "���ô� ��������",
                                "���� �� ����",
                                "����� ��� ��� ���ÿɼҼ�.",
                                "�� ���Ⱑ ���ܿ�",
                                "���� ������",
                                "�׾ �ƴ� ���� �긮������.",
                                ""};
    k=0;
    while (text[k][0]!='\0') {
        replace(text[k],"���޷���","����ȭ");
        replace(text[k],"��","��");
        printf("%s\n",text[k]);
        k++;
    }

    return 0;
}

void replace(char *text,char *key,char *rep)
{
    char *p,buf[256];

    p=search(text,key);
    while (p!=NULL) {
        *p='\0';
        strcpy(buf,p+strlen(key));
        strcat(text,rep);
        strcat(text,buf);
        p=search(p+strlen(rep),key);
    }
}

char *search(char *text,char *key)
{
    int m,n;
    char *p;

    m=strlen(text);
    n=strlen(key);
    for (p=text;p<=text+m-n;p++) {
         if (strncmp(p,key,n)==0)
            return p;
    }
    return NULL;
}
