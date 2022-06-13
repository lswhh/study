#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define EXCEPTION_END EXCEPTION_END_LABEL:
#define TEST_RAISE( a, b ) { if( a ) {  goto b; } }
#define TEST_END( a ) { if( a ) {  goto EXCEPTION_END_LABEL; } }
#define RAISE(a) {  goto a; }
#define EXCEPTION(a) goto EXCEPTION_END_LABEL; a:

typedef struct toyT
{
    int shape;
    int count;
} toyT;
int compareToyT(const void* aLhs, const void* aRhs)
{
    toyT * sLhs = (toyT*) aLhs;
    toyT * sRhs = (toyT*) aRhs;
    if ( sLhs->count < sRhs->count )
    {
        return -1;
    }
    else if ( sLhs->count > sRhs->count )
    {
        return 1;
    }
    else
    {
        if ( sLhs->shape < sRhs->shape )
        {
            return -1;
        }
        else if ( sLhs->shape > sRhs->shape )
        {
            return 1;
        }
    }
    return 0;
}
int compareInt(const void* aLhs, const void* aRhs)
{
    int *sLhs = (int*)aLhs;
    int *sRhs = (int*)aRhs;
    if ( *sLhs < *sRhs )
    {
        return -1;
    }
    else if ( *sLhs > *sRhs )
    {
        return 1;
    }
    return 0;
}
int setMultipleToy(int* arr, toyT* toys, int n, int startIdx)
{
    int lastIdx;
    int i = 0;
    int count = 1;
    int shape = arr[startIdx];

    for ( i = startIdx + 1; i < n; i++ )
    {
        if ( arr[startIdx] == arr[i] )
        {
            count++;
        }
        else
        {
            break;
        }
    }
    lastIdx = i - 1;
    for ( i = startIdx; i < lastIdx + 1; i++ )
    {
        toys[i].count = count;
        toys[i].shape = shape;
    }
    return lastIdx;
}
int *solution(int *arr, int n)
{
    // 정수 배열 arr의 각 정수가 등장한 횟수에 따라 오름차순으로 정렬된 array를 반환합니다.
    // 반환되는 array는 동적으로 할당되어야 합니다. arr의 크기는 n으로 주어집니다.
    int i = 0;
    toyT *toys = NULL;
    int prevValue = 0;
    int *result = 0;

    TEST_END( n == 0 );
    
    toys = (toyT*)malloc(sizeof(toyT) * n);
    qsort(arr, n, sizeof(int), compareInt);

    toys[0].count = 1;
    toys[0].shape = arr[i];    
    for ( i = 1; i < n; i++ )
    {
        if ( arr[i-1] == arr[i] )
        {
            i = setMultipleToy(arr, toys, n, i - 1);
        }
        else
        {
            toys[i].count = 1;
            toys[i].shape = arr[i];
        }
    }

    qsort(toys, n, sizeof(toyT), compareToyT);
    result = (int*)malloc(sizeof(int) * n);
    for ( i = 0; i < n; i++ )
    {
        result[i] = toys[i].shape;
    }
    free(toys);
    return result;
    EXCEPTION_END;

    return NULL;
}


int main()
{
    int A[] = {3,3,4,4};
    int * res;
    int i;
  	res = solution(A, 4);
	if (NULL != res) {
		for (i = 0; i < 4; i++) {
			printf( "%d\n", res[i]);
		}
	}
    return 0;
}