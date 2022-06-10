/*
 * ------------------------
 *      ť (������)     *
 * ------------------------
 */

#include <stdio.h>

#define MaxSize 100     /* ť ũ�� */
int queue[MaxSize];     /* ť */
int head=0,             /* ù ��° �����͸� ����Ű�� ������ */
    tail=0;             /* ������ �����͸� ����Ű�� ������ */
int queuein(int);
int queueout(int *);

int main(void)
{
    int c,n;

	printf("]");
    while ((c=getchar())!=EOF) {
		if (c == '\n') continue;
        if (c=='i' || c=='I') {
            printf("data--> ");
            scanf("%d",&n);
            if (queuein(n)==-1) {
                printf("ť�� ���� á���ϴ�.\n");
            }
        }
        if (c=='o' || c=='O') {
            if (queueout(&n)==-1)
                printf("ť�� ����ֽ��ϴ�.\n");
            else
                printf("queue data --> %d\n",n);
        }
		printf("]");
    }

	return 0;
}

int queuein(int n)       /* ť�� �����͸� �����ϴ� �Լ� */
{
    if ((tail+1)%MaxSize !=head) {
        queue[tail]=n;
        tail++;
        tail=tail%MaxSize;
        return 0;
    }
    else
        return -1;       /* ť�� ���� á�� �� */
}

int queueout(int *n)     /* ť���� �����͸� �����ϴ� �Լ� */
{
    if (tail!=head) {
        *n=queue[head];
        head++;
        head=head%MaxSize;
        return 0;
    }
    else
        return -1;       /* ť�� ������� �� */
}

