/*
 * ------------------------------------------
 *      연립방정식의 해법 (피벗선택법)      *
 * ------------------------------------------
 */

#include <stdio.h>
#include <math.h>

#define N 3     /* 원의 수 */

int main(void)
{                                   /* 계수행렬 */
    static double a[N][N+1]={{2.0  ,3.0  ,1.0  ,4.0  },
                             {4.0  ,1.0  ,-3.0 ,-2.0 },
                             {-1.0 ,2.0  ,2.0  ,2.0  }};
    double p,d,max,dumy;
    int i,j,k,s;

    for (k=0;k<N;k++){
        max=0;s=k;
        for(j=k;j<N;j++){
            if (fabs(a[j][k])>max){
                max=fabs(a[j][k]);s=j;
            }       
        }       
        if (max==0){
            printf("풀 수 없음");
            exit(1);
        }       
        for (j=0;j<=N;j++){
            dumy=a[k][j];
            a[k][j]=a[s][j];
            a[s][j]=dumy;
        }       

        p=a[k][k];              /* 피벗 계수 */
        for (j=k;j<N+1;j++)        /* 피벗행을 p로 나눔 */
            a[k][j]=a[k][j]/p;
        for (i=0;i<N;i++){      /* 피벗열 소거 */
            if (i!=k){ 
                d=a[i][k];
                for (j=k;j<N+1;j++)
                    a[i][j]=a[i][j]-d*a[k][j];
            }
        }
    }

    for (k=0;k<N;k++)
        printf("x%d=%f\n",k+1,a[k][N]);

	return 0;
}

