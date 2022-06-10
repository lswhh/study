/*
 * ---------------------------------------------
 *      미로 통과하기 (경로를 스택에 저장)     *
 * ---------------------------------------------
 */

#include <stdio.h>

int m[7][7]={{2,2,2,2,2,2,2},
             {2,0,0,0,0,0,2},
             {2,0,2,0,2,0,2},
             {2,0,0,2,0,2,2},
             {2,2,0,2,0,2,2},
             {2,0,0,0,0,0,2},
             {2,2,2,2,2,2,2}};

int Si,Sj,Ei,Ej,success,
    sp,ri[100],rj[100];         /* 지나간 위치를 저장할 스택 */

int visit(int,int);

int main(void)
{
    sp=0;                       /* 스택 포인터의 초기값 */
    success=0;                  /* 탈출 성공여부를 나타내는 플래그 */
    Si=1; Sj=1; Ei=5; Ej=5;     /* 입구와 출구의 위치 */

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

    m[i][j]=1;
    ri[sp]=i; rj[sp]=j; sp++;       /* 지나간 위치를 스택에 저장 */

    if (i==Ei && j==Ej) {           /* 출구에 도달했을 때 */
        for (k=0;k<sp;k++)          /* 지나간 위치 출력 */
            printf("(%d,%d) ",ri[k],rj[k]);
        success=1;
    }
                            /* 출구에 도달할 때까지 미로를 탐색한다. */
    if (success!=1 && m[i][j+1]==0) visit(i,j+1);
    if (success!=1 && m[i+1][j]==0) visit(i+1,j);
    if (success!=1 && m[i][j-1]==0) visit(i,j-1);
    if (success!=1 && m[i-1][j]==0) visit(i-1,j);

    sp--;                            /* 스택에서 추출 */
    return success;
}

