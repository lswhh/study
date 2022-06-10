/*
 * ----------------------
 *      ����(stack)     *
 * ----------------------
 */

#include <stdio.h>

#define MaxSize 100     /* ���� ũ�� */
int stack[MaxSize];     /* ���� */
int sp=0;               /* ���� ������ */
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
                printf("������ ���� á���ϴ�.\n");
            }
        }
        if (c=='o' || c=='O') {
            if (pop(&n)==-1)
                printf("������ ������ϴ�.\n");
            else
                printf("stack data --> %d\n",n);
        }
		printf("]");
    }

	return 0;
}

int push(int n)        /* ���ÿ� �����͸� �����ϴ� �Լ� */
{
    if (sp<MaxSize) {
        stack[sp]=n;
        sp++;
        return 0;
    }
    else
        return -1;     /* ������ ���� á�� �� */
}

int pop(int *n)        /* ���ÿ��� �����͸� �����ϴ� �Լ� */
{
    if (sp>0){
        sp--;
        *n=stack[sp];
        return 0;
    }
    else
        return -1;     /* ������ ����� �� */
}

