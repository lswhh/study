/*
 * ----------------------------------------
 *      �ϳ����� ž (�ùķ��̼� ����)     *
 * ----------------------------------------
 */

#include <stdio.h>

void hanoi(int,int,int,int);
void move(int,int,int);

int pie[20][3];        /* 20 : ������ �ִ� ����, 3 : ���� �� */
int sp[3],N;           /* ���� ������ */

int main(void)
{
    int i;
    printf("������ ����? ");
    scanf("%d",&N);

    for (i=0;i<N;i++)               /* �� a�� ������ �״´�. */
         pie[i][0]=N-i;
    sp[0]=N; sp[1]=0; sp[2]=0;      /* ���� ������ �ʱⰪ ���� */

    hanoi(N,0,1,2);

    return 0;
}

void hanoi(int n,int a,int b,int c)  /* ��� �Լ� */
{
    if (n>0) {
        hanoi(n-1,a,c,b);
        move(n,a,b);
        hanoi(n-1,c,b,a);
    }
}

void move(int n,int s,int d)        /* ���� �̵� �ùķ��̼� */
{
    int i,j;

    pie[sp[d]][d]=pie[sp[s]-1][s];  /* s -> d�� ���� �̵� */
    sp[d]++;                        /* ���� ������ ���� */
    sp[s]--;

    printf("\n%d �� ������ %c-->%c �� �ű��.\n\n",n,'a'+s,'a'+d);
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
