/*
 * ---------------------------------
 *      우선순위 파싱 (직접법)     *
 * ---------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

double v[50];        /* 계산용 스택 */
char ope[50];        /* 연산자용 스택 */
int pri[256];        /* 우선순위표 */
int sp1,sp2;         /* 스택 포인터 */

void calc(void);

int main(void)
{
    char *expression="(1>2|2<8|3<4)|(9<2)",*p=expression;

    pri['|']=1; pri['<']=pri['>']=2;
    pri['(']=3; pri[')']=0;

    ope[0]=0; pri[0]=-1;        /* 경계값 */
    sp1=sp2=0;
    while  (*p!='\0') {
        if ('0'<=*p && *p<='9')
            v[++sp2]=*p-'0';
        else {
            while (pri[*p]<=pri[ope[sp1]] && ope[sp1]!='(')
                calc();
            if (*p!=')')
                ope[++sp1]=*p;
            else
                sp1--;      /* (를 제거 */
        }
        p++;
    }
    while (sp1>0)           /* 연산자 스택이 빌 때까지 */
        calc();
    printf("%s=%f\n",expression,v[1]);

	return 0;
}

void calc(void)             /* 연산처리 */
{
    switch (ope[sp1]) {
        case '|' : v[sp2-1]=(v[sp2-1]+v[sp2])/2;break;
        case '>' : v[sp2-1]=MAX(v[sp2-1],v[sp2]);break;
        case '<' : v[sp2-1]=MIN(v[sp2-1],v[sp2]);break;
    }
    sp2--; sp1--;
}

