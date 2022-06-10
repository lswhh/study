/*
 * ------------------------
 *      �������� ���     *
 * ------------------------
 */

#include <stdio.h>

char stack[50],polish[50];
int pri[256];                   /* �켱����ǥ */
int sp1,sp2;                    /* ���� ������ */

int main(void)
{
    int i;
    char *p="a+b-c*d/e";        /* �� */

    for (i=0;i<=255;i++)        /* �켱����ǥ �ۼ� */
         pri[i]=3;
    pri['+']=pri['-']=1; pri['*']=pri['/']=2;

    stack[0]=0;pri[0]=-1;       /* ��谪 */
    sp1=sp2=0;
    while  (*p!='\0') {
        while (pri[*p]<=pri[stack[sp1]])
            polish[++sp2]=stack[sp1--];
        stack[++sp1]=*p++;
    }
    for (i=sp1;i>0;i--)         /* ���ÿ� �����ִ� ���� ���� */
         polish[++sp2]=stack[i];

    for (i=1;i<=sp2;i++)
         putchar(polish[i]);

    printf("\n");
    return 0;
}
