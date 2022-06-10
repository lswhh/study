/*
 * -----------------------
 *      Newton 보간      *
 * -----------------------
 */

#include <stdio.h>

double newton(double *,double *,int,double);

int main(void)
{
    static double x[]={0.0,1.0,3.0,6.0,7.0},
                  y[]={0.8,3.1,4.5,3.9,2.8};

    double t;

    printf("      x      y\n");
    for (t=0.0;t<=7.0;t=t+.5)
        printf("%7.2f%7.2f\n",t,newton(x,y,5,t));

	return 0;
}
double newton(double x[],double y[],int n,double t)
{
    static int flag=1; 
    static double a[100];      /* 계수행렬 */
    double        w[100],      /* 작업용   */
           s;      
    int i,j;

    if (flag==1){    /* 처음 호출했을 때만 a[]에 계수를 저장한다. */
        for (i=0;i<n;i++){
            w[i]=y[i];
            for (j=i-1;j>=0;j--)
                w[j]=(w[j+1]-w[j])/(x[i]-x[j]);
            a[i]=w[0];
        }       
        flag=-1;
    }

    s=a[n-1];               /* x = t에 의한 보간 */
    for (i=n-2;i>=0;i--)
        s=s*(t-x[i])+a[i];
    return s;
}

