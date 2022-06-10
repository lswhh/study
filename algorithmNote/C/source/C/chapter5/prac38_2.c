/*
 * ---------------------------------------
 *      역폴란드 기법 (괄호처리 #2)      *
 * ---------------------------------------
 */

#include <stdio.h>

char stack[50],polish[50];
int pri[256];                   /* 우선순위표 */
int sp1,sp2;                    /* 스택 포인터 */

int main(void)
{
    int i;
    char *p="(a+b)*(c+d)";      /* 식 */

    for (i=0;i<=255;i++)        /* 피연산자의 우선순위 */
         pri[i]=3;
    pri['+']=pri['-']=1; pri['*']=pri['/']=2;    /* 연산자의 우선순위 */
    pri['(']=4; pri[')']=0;

    stack[0]=0;pri[0]=-1;       /* 경계값 */
    sp1=sp2=0;
    while  (*p!='\0') {
        while (pri[*p]<=pri[stack[sp1]] && stack[sp1]!='(')
            polish[++sp2]=stack[sp1--];
        if (*p!=')')
            stack[++sp1]=*p;
        else
            sp1--;
        p++;

    }
    for (i=sp1;i>0;i--)        /* 스택에 남아있는 값 추출 */
         polish[++sp2]=stack[i];

    for (i=1;i<=sp2;i++)       /* 역폴란드 기법으로 출력 */
         putchar(polish[i]);

    printf("\n");
    return 0;
}
