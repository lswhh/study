/*
 * ------------------------------------
 *      미로의 모든 경로 지나가기     *
 * ------------------------------------
 */

#include <stdio.h>

int m[9][9]={{2,2,2,2,2,2,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,0,2,2,0,2,2,0,2},
             {2,0,2,0,0,2,0,0,2},
             {2,0,2,0,2,0,2,0,2},
             {2,0,0,0,0,0,2,0,2},
             {2,2,0,2,2,0,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,2,2,2,2,2,2,2,2}};

int Si,Sj,Ei,Ej,success,
    sp,ri[100],rj[100];         /* 지나간 위치를 저장할 스택 */

int visit(int,int);

int main(void)
{
    sp=0;                       /* 스택 포인터의 초기값 */
    success=0;                  /* 탈출 성공여부를 나타내는 플래그 */
    Si=1; Sj=1; Ei=7; Ej=7;     /* 입구와 출구의 위치 */

    printf("미로 탐색\n");
    if (visit(Si,Sj)==0)
        printf("출구를 찾을 수 없습니다.\n");
	else
		printf("\n");

	return 0;
}
int visit(int i,int j)
{
    int k;
    static int path=1;

    m[i][j]=1;
    ri[sp]=i; rj[sp]=j; sp++;   /* 지나간 위치를 스택에 저장 */

    if (i==Ei && j==Ej) {       /* 출구에 도달했을 때 */
        printf("path=%d\n",path++);     /* 지나간 위치 출력 */
        for (k=0;k<sp;k++)
            printf("(%d,%d) ",ri[k],rj[k]);
		printf("\n");
        success=1;
    }
                                /* 미로를 탐색한다. */
    if (m[i][j+1]==0) visit(i,j+1);
    if (m[i+1][j]==0) visit(i+1,j);
    if (m[i][j-1]==0) visit(i,j-1);
    if (m[i-1][j]==0) visit(i-1,j);

    sp--;                       /* 스택에서 추출 */
    m[i][j]=0;                  /* 다른 경로를 탐색하기 위해 */

    return success;
}

