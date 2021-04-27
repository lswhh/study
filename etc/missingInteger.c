// This is a demo task.

// Write a function:

// int solution(int A[], int N);

// that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

// For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

// Given A = [1, 2, 3], the function should return 4.

// Given A = [−1, −3], the function should return 1.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..100,000];
// each element of array A is an integer within the range [−1,000,000..1,000,000].
// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdlib.h>

int compare( const void * aLhs, const void * aRhs )
{
    int sLhs = *(int*) aLhs;
    int sRhs = *(int*) aRhs;
    if ( sLhs < sRhs )
    {
        return -1;
    }
    else if ( sLhs > sRhs )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int result = 0;
    int i = 0;
    qsort(A, N, sizeof(int), compare);

    for ( i = 0; i < N - 1; i++ )
    {
        //printf("%d ",A[i]);
        if ( A[i] == A[i+1] )
        {
            /* next */
        }
        else
        {
            if ( ( (A[i] + 1) != A[i+1] ) && 
                ( (A[i] + 1) > 0 ) )
            {
                result = A[i] + 1;    
                break;   
            }
        }
    }
    if ( i == (N - 1) )
    {
        if( A[i] < 0 )
        {
            result = 1;
        }
        else
        {
            if ( (N == 1) && (A[i] != 1) )
            {
                result = 1;
            }
            else
            {
                result = A[i] + 1;
            } 
        }
    }
    return result;
}