/*
 * ---------------------------
 *      무한 자리수 계산     *
 * ---------------------------
 */

#include <stdio.h>

#define CIPHER 20             /* 자리수 */
#define N ((CIPHER-1)/4+1)    /* 배열크기 */

void lmul(short *,short,short *);
void ldiv(short *,short,short *);
void print(short *);

int main(void)
{
    static short a[N+2]={   0,3050,2508,8080,1233},
                 c[N+2];

    lmul(a,101,c); print(c);
    ldiv(a,200,c); print(c);

	return 0;
}
void lmul(short a[],short b,short c[])    /* 긴 자리수 곱셈 */
{
    short i;long d,cy=0;
    for (i=N-1;i>=0;i--){
        d=a[i];
        c[i]=(d*b+cy)%10000;
        cy=(d*b+cy)/10000;
    }
}
void ldiv(short a[],short b,short c[])    /* 긴 자리수 나눗셈 */
{
    short i;long d,rem=0;
    for (i=0;i<N;i++){
        d=a[i];
        c[i]=(d+rem)/b;
        rem=((d+rem)%b)*10000;
    }
}
void print(short c[])            /* 긴 자리수 출력 */
{
    short i;
    for (i=0;i<N;i++)
        printf("%04d ",c[i]);
    printf("\n");
}

