// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdlib.h>
#include <stdio.h>

typedef struct leaf
{
    int idx;
    int value;
} leaf;
int compare(const void* aLhs, const void* aRhs)
{
    leaf * sLhs = (leaf*) aLhs;
    leaf * sRhs = (leaf*) aRhs;
    if ( sLhs->value < sRhs->value )
    {
        return -1;
    }
    else if ( sLhs->value > sRhs->value )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int solution(int X, int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    leaf * sLeaves;
    int i = 0;
    int * sResult = NULL;
    int j = 0;
    int sResultSecond = -1;
    sLeaves = malloc(N * sizeof(leaf));
    sResult = calloc(X, sizeof(char));
    for (i = 0; i < N; i++)
    {
        sLeaves[i].idx = i;
        sLeaves[i].value = A[i];
    }
    qsort(sLeaves, N, sizeof(leaf), compare);
    for (i = 0; i < N; i++)
    {
        if(sLeaves[i].value < X)
        {
            sResult[sLeaves[i].value] = 1;
        }
        if(sLeaves[i].value == X)
        {
            for(j = 1; j < X ; j++)
            {
                if(sResult[j] != 1)
                {
                    sResultSecond = -1;
                    //printf("sResult[%d] = %d",j,sResult[j]);
                    return sResultSecond;
                }
            }
            sResultSecond = sLeaves[i].idx;
            break;
        }
       // printf("sLeaves[%d] = %d\n", sLeaves[i].idx, sLeaves[i].value);
    }
    free(sResult);
    free(sLeaves);

    return sResultSecond;
}

int main()
{
    int A[] = {2,2,2,2,2};
    printf("result: %d ", solution(2,A,5));
    return 0;
}