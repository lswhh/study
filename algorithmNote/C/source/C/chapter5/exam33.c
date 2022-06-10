/*
 * ------------------------
 *      큐 (대기행렬)     *
 * ------------------------
 */

#include <stdio.h>

#define MaxSize 100     /* 큐 크기 */
int queue[MaxSize];     /* 큐 */
int head=0,             /* 첫 번째 데이터를 가리키는 포인터 */
    tail=0;             /* 마지막 데이터를 가리키는 포인터 */
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
                printf("큐가 가득 찼습니다.\n");
            }
        }
        if (c=='o' || c=='O') {
            if (queueout(&n)==-1)
                printf("큐가 비어있습니다.\n");
            else
                printf("queue data --> %d\n",n);
        }
		printf("]");
    }

	return 0;
}

int queuein(int n)       /* 큐에 데이터를 저장하는 함수 */
{
    if ((tail+1)%MaxSize !=head) {
        queue[tail]=n;
        tail++;
        tail=tail%MaxSize;
        return 0;
    }
    else
        return -1;       /* 큐가 가득 찼을 때 */
}

int queueout(int *n)     /* 큐에서 데이터를 추출하는 함수 */
{
    if (tail!=head) {
        *n=queue[head];
        head++;
        head=head%MaxSize;
        return 0;
    }
    else
        return -1;       /* 큐가 비어있을 때 */
}

