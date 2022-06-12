// https://www.hackerrank.com/challenges/minimum-swaps-2/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> 

char* readline();
char** split_string(char*);
void swap(int *lhs, int *rhs)
{
    int tmp;
    tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}
int* getSwapTarget(int* arr, int arrSize, int swapTarget)
{
    int i = 0;
    int targetIdx = INT_MAX;
    for ( i = swapTarget -1 ; i < arrSize; i++ )
    {
        if ( arr[i] == swapTarget )
        {
            targetIdx = i;
            break;
        }
    }
    
    if ( targetIdx == INT_MAX ) 
    {
        targetIdx = arrSize - 1;
    }
    return &arr[targetIdx];
}
// Complete the minimumSwaps function below.
int minimumSwaps(int arr_count, int* arr) {
    int i = 0;
    int result = 0;
    for ( i = 0; i < arr_count - 1; i++ )
    {
        if ( arr[i] != i + 1 )
        {
            swap( &arr[i], getSwapTarget(arr, arr_count, i + 1));
            i = i - 1;
            result += 1;
        }
    }
    return result;
}

int main()
{
    int arr[]= {4,3,1,2};
    printf("%d\n", minimumSwaps(4, arr));
    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
