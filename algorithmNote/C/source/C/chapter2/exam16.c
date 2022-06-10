/*
 * -------------------------------------------
 *      선형계획법 (Linear Programming)      *
 * -------------------------------------------
 */

#include <stdio.h>
#include <math.h>

#define N1 4     /* 행 수 */
#define N2 6     /* 열 수 */
#define N3 2     /* 변수의 수 */

int main(void)
{                                   /* 계수행렬 */
    static double a[N1][N2]={{1.0,2.0,1.0,0.0,0.0,14.0  },
                             {1.0,1.0,0.0,1.0,0.0,8.0   },
                             {3.0,1.0,0.0,0.0,1.0,18.0  },
                             {-2.0,-3.0,0.0,0.0,0.0,0.0}};
    double min,p,d;
    int j,k,x,y,flag;

    while (1){
        min=9999;           /* 열 선택 */
        for (k=0;k<N2-1;k++){
            if (a[N1-1][k]<min){
                min=a[N1-1][k];
                y=k;
            }
        }

        if (min>=0)
            break;

        min=9999;           /* 행 선택 */
        for (k=0;k<N1-1;k++){
            p=a[k][N2-1]/a[k][y];
            if (a[k][y]>0 && p<min){
                min=p;
                x=k;
            }
        }
        p=a[x][y];              /* 피벗 계수 */
        for (k=0;k<N2;k++)      /* 피벗행을 p로 나눈다. */
            a[x][k]=a[x][k]/p;
        for (k=0;k<N1;k++){     /* 피벗열을 소거 */
            if (k!=x){
                d=a[k][y];
                for (j=0;j<N2;j++)
                    a[k][j]=a[k][j]-d*a[x][j];
            }
        }
    }

    for (k=0;k<N3;k++){
        flag=-1;
        for (j=0;j<N1;j++){
            if (a[j][k]==1)
                flag=j;
        }
        if (flag!=-1)
            printf("x%d = %f\n",k,a[flag][N2-1]);
        else
            printf("x%d = %f\n",k,0);
    }
    printf("z= %f\n",a[N1-1][N2-1]);

	return 0;
}

