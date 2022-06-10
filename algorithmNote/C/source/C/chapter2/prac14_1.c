/*
 * ------------------------------
 *      소수점 1000자리의 e     *
 * ------------------------------
 */

#include <stdio.h>

void ladd(short *,short *,short *);
void lsub(short *,short *,short *);
void ldiv(short *,short,short *);
void printresult(short *);

#define L 1000          /* 구하고자 하는 자리수      */
#define L1 ((L/4)+1)    /* 배열크기    */
#define L2 (L1+1)       /* 배열크기 + 1  */
#define N 451           /* 계산하려는 항의 수    */

int main(void)
{
    static short s[L2+2],w[L2+2];
    short k;
    for (k=0;k<=L2;k++)
        s[k]=w[k]=0;

    s[0]=w[0]=1;
    for (k=1;k<=N;k++){
        ldiv(w,k,w);
        ladd(s,w,s);
    }
    printresult(s);

	return 0;
}
void printresult(short c[])       /* 결과 출력 */
{
    short i;
    printf("%3d. ",c[0]);         /* 최상위 자리 출력 */
    for (i=1;i<L1;i++)
        printf("%04d ",c[i]);
    printf("\n");
}
void ladd(short a[],short b[],short c[])
{
    short i,cy=0;
    for (i=L2;i>=0;i--){
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
    for (i=L2;i>=0;i--){
        c[i]=a[i]-b[i]-brrw;
        if (c[i]>=0)
            brrw=0;
        else {
            c[i]=c[i]+10000;
            brrw=1;
        }
    }
}
void ldiv(short a[],short b,short c[])
{
    short i;long d,rem=0;
    for (i=0;i<=L2;i++){
        d=a[i];
        c[i]=(d+rem)/b;
        rem=((d+rem)%b)*10000;
    }
}

