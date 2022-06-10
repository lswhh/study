/*
 * -----------------------------
 *      ������ ���� �ű�       *
 * -----------------------------
 */

#include <stdio.h>

#define Num 10
#define Max 100
#define Min 0

int main(void)
{
    static int a[]={56,25,67,88,100,61,55,67,76,56};
    int i,rank[Max+2];

    for (i=Min;i<=Max;i++)             /* 0���� �ʱ�ȭ */
        rank[i]=0;

    for (i=0;i<Num;i++)                /* �� ������ ÷�ڷ� �ϴ� �迭 ��ҿ� +1 */
        rank[a[i]]++;

    rank[Max+1]=1;                     /* �ٷ� ������ ����� ���� ���Ѵ�. */
    for (i=Max;i>=Min;i--)
        rank[i]=rank[i]+rank[i+1];

    printf("   ����  ����\n");
    for (i=0;i<Num;i++){
        printf("%6d%6d\n",a[i],rank[a[i]+1]);  /* ����+1�� ��ġ�� ������ �����. */
    }

    return 0;
}
