/*
 * -------------------------------
 *      ���� ���� (���� �̵�)    *
 * -------------------------------
 */

#include <stdio.h>

int main(void)
{
    static int heap[100];
    int n,i,s,p,w;

    n=1;
    while (scanf("%d",&heap[n])!=EOF) {
        /* ���� ������ ��ҿ� ���� */
        s=n;
        p=s/2;          /* �θ� ����� ��ġ */
        while (s>=2 && heap[p]>heap[s]) {    /* ���� �̵� */
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
