/*
 * ----------------------------------------
 *      역폴란드 기법 (괄호처리 포함)     *
 * ----------------------------------------
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
    pri['+']=pri['-']=1; pri['*']=pri['/']=2;
    pri['(']=0;

    stack[0]=0;pri[0]=-1;       /* 경계값 */
    sp1=sp2=0;
    while  (*p!='\0') {
        if (*p=='(')            /* ( 처리 */
            stack[++sp1]=*p;
        else if(*p==')') {      /* ) 처리 */
            while (stack[sp1]!='(')
                polish[++sp2]=stack[sp1--];
            sp1--;
        }
        else {                  /* 피연산자와 연산자 처리 */
            while (pri[*p]<=pri[stack[sp1]])
                polish[++sp2]=stack[sp1--];
            stack[++sp1]=*p;
        }
        p++;
    }
    for (i=sp1;i>0;i--)        /* 스택에 남아있는 값 추출 */
         polish[++sp2]=stack[i];

    for (i=1;i<=sp2;i++)       /* 역폴란드 기법으로 출력 */
         putchar(polish[i]);

    printf("\n");

    return 0;

}
