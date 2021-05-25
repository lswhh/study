#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int N) 
{
    // write your code in C99 (gcc 6.2.0)
    int * result = NULL;
    int min = 0;
    int lhs = 0;
    int rhs = 0;
    result = (int*) malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++)
    {
        rhs += A[i];
    }

    for(int i = 0; i < N; i++)
    {
        lhs = lhs + A[i];
        rhs = rhs - A[i];
        result[i+1] = abs(lhs - rhs);
    }

    min = result[1];
    for(int i = 2; i < N; i++)
    {
        if ( min > result[i] )
        {
            min = result[i];
        }
    }
    free(result);
    return min;
}

int main()
{
    int A[] = {3,1,2,4,3};

    printf("result: %d\n", solution(A, 5));
    return 0;
}