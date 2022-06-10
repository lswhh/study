/*
 * ----------------------
 *      �ּ� ������     *
 * ----------------------
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "glib.h"

#define N 7             /* �ڷ�� */
#define M 5             /* �������� */

double x[]={-3,-2,-1, 0,1,2,3},
       y[]={ 5,-2,-3,-1,1,4,5},
       a[M+1][M+2],s[2*M+1],t[M+1];

double ipow(double,int);
void graph(void);

int main(void)
{
    int i,j,k;
    double p,d;

    for (i=0;i<=2*M;i++)
        s[i]=0;
    for (i=0;i<=M;i++)
        t[i]=0;

    for (i=0;i<N;i++){
        for (j=0;j<=2*M;j++)               /* s0 ~ s2m ��� */
            s[j]=s[j]+ipow(x[i],j);
        for (j=0;j<=M;j++)                 /* t0 ~ tm ��� */
            t[j]=t[j]+ipow(x[i],j)*y[i];
    }

    for (i=0;i<=M;i++){               /* a[][] �� s[],t[] ���� �ִ´�. */
        for (j=0;j<=M;j++)
            a[i][j]=s[i+j];
        a[i][M+1]=t[i];
    }

    for (k=0;k<=M;k++){             /* �Ұ� */
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
    graph();
    for (k=0;k<=M;k++)                    /* ��� ��� */
        printf("a%d=%f\n",k,a[k][M+1]);

	return 0;
}
double ipow(double p,int n)
{
    int k;
    double s=1;
    for (k=1;k<=n;k++)
        s=s*p;
    return s;
}
void graph(void)
{
    double px,py,xmax,ymax,xmin,ymin,sx,sy,dx,dy,step;
    int k,l;

    ginit();cls();

    xmax=xmin=x[0];ymax=ymin=y[0];
    for (k=1;k<N;k++){
        if (x[k]<xmin) xmin=x[k];
        if (y[k]<ymin) ymin=y[k];
        if (x[k]>xmax) xmax=x[k];
        if (y[k]>ymax) ymax=y[k];
    }
    sx=1.2*max(fabs(xmin),fabs(xmax));  /* x�� ũ�� */
    sy=1.2*max(fabs(ymin),fabs(ymax));  /* y�� ũ�� */
    dx=sx/100;dy=sy/100;                /* +ǥ�� ũ�� */
    step=(xmax-xmin)/100;               /* ���� */

    window(-sx,-sy,sx,sy);

    line (-sx,0,sx,0);line(0,-sy,0,sy);     /* �� */

    for (l=0;l<N;l++){                      /* +ǥ�� */
        line(x[l]-dx,y[l],x[l]+dx,y[l]);
        line(x[l],y[l]-dy,x[l],y[l]+dy);
    }

    for (px=xmin;px<=xmax;px=px+step){      /* �׷��� ǥ�� */
        py=0;
        for (k=0;k<=M;k++)
            py=py+a[k][M+1]*ipow(px,k);
        if (px==xmin)
            setpoint(px,py);
        else
            moveto(px,py);
    }
}
