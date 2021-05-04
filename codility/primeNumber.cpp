#include <stdio.h>
#include <math.h>

/* A prime number return greater than 0 */
int isPrime(int N)
{
    int result = 0;

    for(int i = 2; i < (int)sqrt(N); i++ )
    {
        if ( (N % i) == 0 )
        {
            result = 0;
            break;
        }
        else
        {
            result = 1;
        }
    }

    if ( (1 < N) && (N < 4) )
    {
        /* 2, 3 is prime */
        result = 1;
    }
    return result;
}
/* get minimum prime number greater than aStartNum 
 * if not exist then return 0
 * */
int getFirstPrimeNumber(int aStartNum)
{
    int result = 0;

    for( int i = aStartNum; i < (aStartNum * aStartNum); i++ )
    {
        if ( isPrime(i) > 0 )
        {
            result = i;
            break;
        }
    }
    return result;
}

int main ()
{
    int test[] = {10, 50, 100, 2, 1, 0};
    for ( int i = 0; i< sizeof(test)/sizeof(int); i++ )
    {
        printf( " prime number %d\n", getFirstPrimeNumber(test[i]) );
    }
    return 0;
}