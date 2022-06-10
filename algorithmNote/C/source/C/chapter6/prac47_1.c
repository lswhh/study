/*
 * ---------------------------------
 *      힙의 생성 (하향 이동)      *
 * ---------------------------------
 */

#include <stdio.h>

void swap(int *,int *);

int main(void)
{
    static int heap[100];
    int i,n,p,s;

    n=1;                     /* 데이터를 트리에 할당 */
    while (scanf("%d",&heap[n])!=EOF)
        n++;
    n--;                     /* 데이터 개수 */
    for (i=n/2;i>=1;i--) {
        p=i;                 /* 부모 노드의 위치 */
        s=2*p;               /* 왼쪽 자식 노드의 위치 */
        while (s<=n) {
            if (s<n && heap[s+1]<heap[s])    /* 왼쪽, 오른쪽 자식 노드 중 작은 쪽 */
                s++;
            if (heap[p]<=heap[s])
                break;
            swap(&heap[p],&heap[s]);
            p=s; s=2*p;                      /* 부모, 자식 노드의 위치 변경 */
        }
    }
    for (i=1;i<=n;i++)
        printf("%d ",heap[i]);

	printf("\n");
	return 0;
}

void swap(int *a,int *b)
{
    int w;
    w=*a; *a=*b; *b=w;
}

