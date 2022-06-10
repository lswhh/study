/*
 * -------------------------------
 *      하노이의 탑 (재귀해)     *
 * -------------------------------
 */

#include <stdio.h>

void hanoi(int,char,char,char);

int main(void)
{
    int n;
    printf("원반의 개수? ");
    scanf("%d",&n);

    hanoi(n,'a','b','c');

	return 0;
}

void hanoi(int n,char a,char b,char c)  /* 재귀 함수 */
{
    if (n>0) { 
        hanoi(n-1,a,c,b);    
        printf("%d번 원반을 %c 에서 %c 로 옮김\n",n,a,b);
        hanoi(n-1,c,b,a);
    }
}

