/*
 * ----------------------
 *      스택(stack)     *
 * ----------------------
 */

#include <stdio.h>

#define MaxSize 100     /* 스택 크기 */
int stack[MaxSize];     /* 스택 */
int sp=0;               /* 스택 포인터 */
int push(int);
int pop(int*);

int main(void)
{
    int c,n;

	printf("]");
    while ((c = getchar()) != EOF)
	{
		if (c == '\n') continue;

        if (c=='i' || c=='I') {
            printf("data--> ");
            scanf("%d",&n);
            if (push(n)==-1) {
                printf("스택이 가득 찼습니다.\n");
            }
        }
        if (c=='o' || c=='O') {
            if (pop(&n)==-1)
                printf("스택이 비었습니다.\n");
            else
                printf("stack data --> %d\n",n);
        }
		printf("]");
    }

	return 0;
}

int push(int n)        /* 스택에 데이터를 저장하는 함수 */
{
    if (sp<MaxSize) {
        stack[sp]=n;
        sp++;
        return 0;
    }
    else
        return -1;     /* 스택이 가득 찼을 때 */
}

int pop(int *n)        /* 스택에서 데이터를 추출하는 함수 */
{
    if (sp>0){
        sp--;
        *n=stack[sp];
        return 0;
    }
    else
        return -1;     /* 스택이 비었을 때 */
}

