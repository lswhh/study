/*
 * ---------------------------------------------
 *      연립방정식의 해법 (가우스 소거법)      *
 * ---------------------------------------------
 */

#include <stdio.h>

#define N 3     /* 원의 수 */

int main(void)
{                                   /* 계수행렬 */
    static double a[N][N+1]={{2.0  ,3.0  ,1.0  ,4.0  },
                             {4.0  ,1.0  ,-3.0 ,-2.0 },
                             {-1.0 ,2.0  ,2.0  ,2.0  }};
    double d;
    int i,j,k;

    for (k=0;k<N-1;k++){            /* 전진소거 */
        for (i=k+1;i<N;i++){
            d=a[i][k]/a[k][k];
            for (j=k+1;j<=N;j++)
                a[i][j]=a[i][j]-a[k][j]*d;
        }
    }
    for (i=N-1;i>=0;i--){            /* 후퇴대입 */
        d=a[i][N];
        for (j=i+1;j<N;j++)
            d=d-a[i][j]*a[j][N];
        a[i][N]=d/a[i][i];
    }

    for (k=0;k<N;k++)
        printf("x%d=%f\n",k+1,a[k][N]);

	return 0;
}

