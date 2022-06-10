/*
 * --------------------
 *      힙 정렬 #2    *
 * --------------------
 */

#include <stdio.h>

void swap(int *,int *);
void shiftdown(int,int,int *);

int main(void)
{
    static int heap[100];
    int i,n,m;

    n=1;                        /* 트리에 데이터를 할당한다 */
    while (scanf("%d",&heap[n])!=EOF)
        n++;
    n--;                        /* 데이터 개수 */
    for (i=n/2;i>=1;i--)        /* 초기 힙 생성 */
        shiftdown(i,n,heap);
    m=n;                        /* n값 저장 */
    while (n>1) {
        swap(&heap[1],&heap[n]);
        n--;                        /* 트리의 마지막 노드 분리 */
        shiftdown(1,n,heap);
    }
    for (i=1;i<=m;i++)
        printf("%d ",heap[i]);

	printf("\n");
	return 0;
}

void shiftdown(int p,int n,int heap[])   /* 하향 이동 */
{
    int s;
    s=2*p;
    while (s<=n) {
        if( s<n && heap[s+1]<heap[s])    /* 왼쪽과 오른쪽 노드 중에 작은 노드 */
            s++;
        if (heap[p]<=heap[s])
            break;
        swap(&heap[p],&heap[s]);
        p=s; s=2*p;                      /* 부모 노드와 자식 노드의 위치 갱신 */
    }
}

void swap(int *a,int *b)
{
    int w;
    w=*a; *a=*b; *b=w;
}

