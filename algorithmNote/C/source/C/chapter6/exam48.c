/*
 * --------------------
 *      힙 정렬 #1    *
 * --------------------
 */

#include <stdio.h>

void swap(int *,int *);

int main(void)
{
    static int heap[100];
    int n,i,s,p,m;

    n=1;                              /* 초기 힙 생성 */
    while (scanf("%d",&heap[n])!=EOF) {
        s=n;p=s/2;
        while (s>=2 && heap[p]>heap[s]) {
            swap(&heap[p],&heap[s]);
            s=p;p=s/2;
        }
        n++;
    }
    n--;                /* 데이터 개수 */
    m=n;                /* n값 저장 */
    while (n>1) {
        swap(&heap[1],&heap[n]);
        n--;               /* 트리의 마지막 노드를 분리한다. */

        p=1; s=2*p;
        while (s<=n) {
            /* 왼쪽과 오른쪽 노드 중에 작은 노드 */
            if (s<n && heap[s+1]<heap[s])
                s++;
            if (heap[p]<=heap[s])
                break;
            swap(&heap[p],&heap[s]);
            /* 부모노드와 자식노드의 위치 갱신 */
            p=s; s=2*p;
        }
    }
    for (i=1;i<=m;i++)
        printf("%d ",heap[i]);

    printf("\n");

    return 0;
}

void swap(int *a,int *b)
{
    int w;
    w=*a; *a=*b; *b=w;
}
