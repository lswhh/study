/*
 * --------------------
 *     �̺� Ž����    *
 * --------------------
 */

#include <stdio.h>

#define N 10       /* ������ �� */

int main(void)
{
    static int a[]={2,3,7,11,31,50,55,70,77,80};
    int key,low,high,mid;

    printf("Ž���� �����ʹ�? "); scanf("%d",&key);

    low=0;high=N-1;
    while (low<=high) {
        mid=(low+high)/2;
        if (a[mid]<=key)
            low=mid+1;
        if (a[mid]>=key)
            high=mid-1;
    }
    if (low==high+2)
        printf("%d ��/�� %d ��°�� �ֽ��ϴ�.\n",a[mid],mid);
    else
        printf("ã�� �� �����ϴ�.\n");

	return 0;
}

