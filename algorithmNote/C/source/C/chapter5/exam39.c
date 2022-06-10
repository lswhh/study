/*
 * -----------------------------------------------
 *      우선순위 파싱 (역폴란드 식으로 변환)     *
 * -----------------------------------------------
 */

#include <stdio.h>
#include <math.h>

char stack[50],polish[50];
double v[50];
int pri[256];           /* 우선순위표 */
int sp1,sp2;            /* 스택 포인터 */

int main(void)
{
    int i;
    char *p="(6+3)/(6-2)+3*2^3-1",*expression=p;  /* 식 */

    for (i=0;i<=255;i++)
         pri[i]=4;
    pri['+']=pri['-']=1; pri['*']=pri['/']=2; pri['^']=3;
    pri['(']=5; pri[')']=0;

    stack[0]=0;pri[0]=-1;        /* 경계값 */
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
    for (i=sp1;i>0;i--)        /* 스택에 남아있는 값을 추출 */
         polish[++sp2]=stack[i];

    sp1=0;                     /* 식 계산 */
    for (i=1;i<=sp2;i++) {
         if ('0'<=polish[i] && polish[i]<='9')
             v[++sp1]=polish[i]-'0';
         else {
             switch (polish[i]) {
                case '+':v[sp1-1]=v[sp1-1]+v[sp1];break;
                case '-':v[sp1-1]=v[sp1-1]-v[sp1];break;
                case '*':v[sp1-1]=v[sp1-1]*v[sp1];break;
                case '/':v[sp1-1]=v[sp1-1]/v[sp1];break;
                case '^':v[sp1-1]=pow(v[sp1-1],v[sp1]);break;
            }
            sp1--;
        }
    }
    printf("%s=%f\n",expression,v[1]);

    return 0;
}
