/*
 * ----------------------------------------
 *      하노이의 탑 (시뮬레이션 포함)     *
 * ----------------------------------------
 */

#include <stdio.h>

void hanoi(int,int,int,int);
void move(int,int,int);

int pie[20][3];        /* 20 : 원반의 최대 개수, 3 : 봉의 수 */
int sp[3],N;           /* 스택 포인터 */

int main(void)
{
    int i;
    printf("원반의 개수? ");
    scanf("%d",&N);

    for (i=0;i<N;i++)               /* 봉 a에 원반을 쌓는다. */
         pie[i][0]=N-i;
    sp[0]=N; sp[1]=0; sp[2]=0;      /* 스택 포인터 초기값 설정 */

    hanoi(N,0,1,2);

    return 0;
}

void hanoi(int n,int a,int b,int c)  /* 재귀 함수 */
{
    if (n>0) {
        hanoi(n-1,a,c,b);
        move(n,a,b);
        hanoi(n-1,c,b,a);
    }
}

void move(int n,int s,int d)        /* 원반 이동 시뮬레이션 */
{
    int i,j;

    pie[sp[d]][d]=pie[sp[s]-1][s];  /* s -> d로 원반 이동 */
    sp[d]++;                        /* 스택 포인터 변경 */
    sp[s]--;

    printf("\n%d 번 원반을 %c-->%c 로 옮긴다.\n\n",n,'a'+s,'a'+d);
    for (i=N-1;i>=0;i--) {
         for (j=0;j<3;j++) {
              if (i<sp[j])
                  printf("%8d",pie[i][j]);
              else
                  printf("        ");
         }
         printf("\n");
    }
    printf("\n       a       b       c\n");
    getchar();
}
