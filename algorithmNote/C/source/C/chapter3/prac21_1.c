/*
 * --------------------
 *     이분 탐색법    *
 * --------------------
 */

#include <stdio.h>

#define N 10       /* 데이터 수 */

int main(void)
{
    static int a[]={2,3,7,11,31,50,55,70,77,80};
    int key,low,high,mid;

    printf("탐색할 데이터는? "); scanf("%d",&key);

    low=0;high=N-1;
    while (low<=high) {
        mid=(low+high)/2;
        if (a[mid]<=key)
            low=mid+1;
        if (a[mid]>=key)
            high=mid-1;
    }
    if (low==high+2)
        printf("%d 은/는 %d 번째에 있습니다.\n",a[mid],mid);
    else
        printf("찾을 수 없습니다.\n");

	return 0;
}

