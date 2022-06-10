/*
 * -----------------------------------
 *      팩토리얼(factorial) 계산     *
 * -----------------------------------
 */

#include <stdio.h>

void ladd(short *,short *,short *);
void lsub(short *,short *,short *);
void lmul(short *,short,short *);
void printresult(short *);

#define L 64               /* 구하고자 하는 자리수      */
#define L2 ((L+3)/4)       /* 배열크기    */

int main(void)
{
    static short s[L2];
    short k;
    for (k=0;k<L2;k++)
        s[k]=0;

    s[L2-1]=1;
    for (k=1;k<=49;k++){
        lmul(s,k,s);
        printf("%2d!=",k);
        printresult(s);
    }

	return 0;
}
void lmul(short a[],short b,short c[])    /* 긴 자리수 곱셈 */
{
    short i;long d,cy=0;
    for (i=L2-1;i>=0;i--){
        d=a[i];
        c[i]=(d*b+cy)%10000;
        cy=(d*b+cy)/10000;
    }
}

void printresult(short c[])       /* 결과 출력 */
{
    short i;
    for (i=0;i<L2;i++)
        printf("%04d",c[i]);
    printf("\n");
}
void ladd(short a[],short b[],short c[])
{
    short i,cy=0;
    for (i=L2-1;i>=0;i--){
        c[i]=a[i]+b[i]+cy;
        if (c[i]<10000)
            cy=0;
        else {
            c[i]=c[i]-10000;
            cy=1;
        }
    }
}
void lsub(short a[],short b[],short c[])
{
    short i,brrw=0;
    for (i=L2-1;i>=0;i--){
        c[i]=a[i]-b[i]-brrw;
        if (c[i]>=0)
            brrw=0;
        else {
            c[i]=c[i]+10000;
            brrw=1;
        }
    }
}

