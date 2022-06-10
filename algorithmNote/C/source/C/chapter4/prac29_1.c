/*
 * --------------------------------------------
 *      하노이의 탑 (인수를 하나 줄인다.)     *
 * --------------------------------------------
 */

#include <stdio.h>

void hanoi(int,char,char);
#define Total 'a'+'b'+'c'

int main(void)
{
    int n;
    printf("원반의 개수? ");
    scanf("%d",&n);

    hanoi(n,'a','b');

	return 0;
}

void hanoi(int n,char a,char b)  /* 재귀 함수 */
{
    if (n>0) {
        hanoi(n-1,a,Total-(a+b));
        printf("%d번 원반을 %c 에서 %c 로 옮김\n",n,a,b);
        hanoi(n-1,Total-(a+b),b);
    }
}

