/*
 * -------------------------------
 *      힙의 생성 (상향 이동)    *
 * -------------------------------
 */

#include <stdio.h>

int main(void)
{
    static int heap[100];
    int n,i,s,p,w;

    n=1;
    while (scanf("%d",&heap[n])!=EOF) {
        /* 힙의 마지막 요소에 저장 */
        s=n;
        p=s/2;          /* 부모 노드의 위치 */
        while (s>=2 && heap[p]>heap[s]) {    /* 상향 이동 */
            w=heap[p];heap[p]=heap[s];heap[s]=w;
            s=p;p=s/2;
        }
        n++;
     }
     for (i=1;i<n;i++)
        printf("%d ",heap[i]);

     printf("\n");
     return 0;
}
