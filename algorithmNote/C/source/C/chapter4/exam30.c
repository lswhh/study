/*
 * -----------------------------------------------
 *      미로 통과하기 (하나의 해만 찾아내기)     *
 * -----------------------------------------------
 */

#include <stdio.h>

int m[7][7]={{2,2,2,2,2,2,2},
             {2,0,0,0,0,0,2},
             {2,0,2,0,2,0,2},
             {2,0,0,2,0,2,2},
             {2,2,0,2,0,2,2},
             {2,0,0,0,0,0,2},
             {2,2,2,2,2,2,2}};

int Si,Sj,Ei,Ej,success;

int visit(int,int);

int main(void)
{
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
    m[i][j]=1;                /* 지나간 위치에 표시를 남김 */

    if (i==Ei && j==Ej)       /* 출구에 도달했을 때 */
        success=1;
                               /* 출구에 도달할 때까지 미로를 탐색한다. */
    if (success!=1 && m[i][j+1]==0) visit(i,j+1);
    if (success!=1 && m[i+1][j]==0) visit(i+1,j);
    if (success!=1 && m[i][j-1]==0) visit(i,j-1);
    if (success!=1 && m[i-1][j]==0) visit(i-1,j);

    if (success==1)          /* 지나온 위치를 출력한다. */
        printf("(%d,%d) ",i,j);

    return success;
}

