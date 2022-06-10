/*
 * ----------------------
 *      최소 제곱법     *
 * ----------------------
 */

#include <stdio.h>

#define N 7             /* 자료수 */
#define M 5             /* 맞춤지수 */

double x[]={-3,-2,-1, 0,1,2,3},
       y[]={ 5,-2,-3,-1,1,4,5},
       a[M+1][M+2],s[2*M+1],t[M+1];

double ipow(double,int);

int main(void)
{
    int i,j,k;
    double p,d,px;

    for (i=0;i<=2*M;i++)
        s[i]=0;
    for (i=0;i<=M;i++)
        t[i]=0;

    for (i=0;i<N;i++){
        for (j=0;j<=2*M;j++)                /* s0 ~ s2m 계산 */
            s[j]=s[j]+ipow(x[i],j);
        for (j=0;j<=M;j++)                  /* t0 ~ tm 계산 */
            t[j]=t[j]+ipow(x[i],j)*y[i];
    }

    for (i=0;i<=M;i++){               /* a[][] 에 s[],t[] 값을 넣는다. */
        for (j=0;j<=M;j++)
            a[i][j]=s[i+j];
        a[i][M+1]=t[i];
    }

    for (k=0;k<=M;k++){             /* 소거 */
        p=a[k][k];
        for (j=k;j<=M+1;j++)
            a[k][j]=a[k][j]/p;
        for (i=0;i<=M;i++){
            if (i!=k){
                d=a[i][k];
                for (j=k;j<=M+1;j++)
                    a[i][j]=a[i][j]-d*a[k][j];
            }
        }
    }

    printf("    x    y\n");        /* 보간다항식에 의한 y값 계산 */
    for (px=-3;px<=3;px=px+.5){
        p=0;
        for (k=0;k<=M;k++)
            p=p+a[k][M+1]*ipow(px,k);

        printf("%5.1f%5.1f\n",px,p);
    }

	return 0;
}
double ipow(double p,int n)        /* p^n을 구하는 함수 */
{
    int k;
    double s=1;
    for (k=1;k<=n;k++)
        s=s*p;
    return s;
}

