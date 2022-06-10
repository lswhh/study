/*
 * ---------------------------
 *      무한 자리수 계산     *
 * ---------------------------
 */

#include <stdio.h>

#define CIPHER 20             /* 자리수 */
#define N ((CIPHER-1)/4+1)    /* 배열크기 */

void ladd(short *,short *,short *);
void lsub(short *,short *,short *);
void print(short *);

int main(void)
{
    static short a[N+2]={1999,4444,7777,2222,9999},
                 b[N+2]={ 111,6666,3333,8888,1111},
                 c[N+2];

    ladd(a,b,c); print(c);
    lsub(a,b,c); print(c);

	return 0;
}
void ladd(short a[],short b[],short c[])  /* 긴 자리수 덧셈 */
{
    short i,cy=0;
    for (i=N-1;i>=0;i--){
        c[i]=a[i]+b[i]+cy;
        if (c[i]<10000)
            cy=0;
        else {
            c[i]=c[i]-10000;
            cy=1;
        }
    }
}
void lsub(short a[],short b[],short c[])  /* 긴 자리수 뺄셈 */
{
    short i,brrw=0;
    for (i=N-1;i>=0;i--){
        c[i]=a[i]-b[i]-brrw;
        if (c[i]>=0)
            brrw=0;
        else {
            c[i]=c[i]+10000;
            brrw=1;
        }
    }
}
void print(short c[])        /* 긴 자리수 출력 */
{
    short i;
    for (i=0;i<N;i++)
        printf("%04d ",c[i]);
    printf("\n");
}

