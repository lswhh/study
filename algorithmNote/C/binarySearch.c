#include <stdio.h>
#include <limits.h>
#define N 10 

#define BIN_SEARCH_NOT_FOUND (INT_MAX)

int binarySearch(int * array, int arraySize, int key)
{
    int low = 0;
    int high = 0;
    int mid = 0;
    int result = BIN_SEARCH_NOT_FOUND;
    
    low = 0;
    high = arraySize - 1;
    while ( low <= high ) 
    {
        mid = ( low + high ) / 2;
        if ( array[mid] == key ) 
        {
            // printf("%d 는  %d 번째 있습니다.\n", array[mid], mid);
            result = mid;
            break;
        }
        if ( array[mid] < key )
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return result;
}
int bisectLeft(int * array, int arraySize, int key)
{
    int low = 0;
    int high = 0;
    int mid = 0;
    int result = BIN_SEARCH_NOT_FOUND;
    
    low = 0;
    high = arraySize - 1;
    while ( low <= high ) 
    {
        mid = ( low + high ) / 2;
        if ( array[mid] == key ) 
        {
            result = mid;
            break;
        }
        if ( array[mid] < key )
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if ( result == BIN_SEARCH_NOT_FOUND )
    {
        result = mid;
    }
    return result;
}
int bisectRight(int * array, int arraySize, int key)
{
    int low = 0;
    int high = 0;
    int mid = 0;
    int result = BIN_SEARCH_NOT_FOUND;
    
    low = 0;
    high = arraySize - 1;
    while ( low <= high ) 
    {
        mid = ( low + high ) / 2;
        if ( array[mid] == key ) 
        {
            result = mid;
            break;
        }
        if ( array[mid] < key )
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (result == BIN_SEARCH_NOT_FOUND)
    {
        result = mid;
    }
    else
    {
        result = mid + 1;
    }
    return result;
}
int main(void)
{
    static int a[]={2,3,7,11,31,50,55,70,77,80};
    int result;
    int data;
    data = 31;
    result = binarySearch(a, sizeof(a)/sizeof(int), data);
    if ( result == BIN_SEARCH_NOT_FOUND )
    {
        printf("(%d)를 찾을 수 없습니다. \n", data);
    }
    else
    {
        printf("data(%d)가 %d 번째 Index에 있습니다. \n", data, result);
    }
    data = 80;
    result = binarySearch(a, sizeof(a)/sizeof(int), data);
    if ( result == BIN_SEARCH_NOT_FOUND )
    {
        printf("(%d)를 찾을 수 없습니다. \n", data);
    }
    else
    {
        printf("data(%d)가 %d 번째 Index에 있습니다. \n", data, result);
    }

    data = 3;
    result = binarySearch(a, sizeof(a)/sizeof(int), data);
    if ( result == BIN_SEARCH_NOT_FOUND )
    {
        printf("(%d)를 찾을 수 없습니다. \n", data);
    }
    else
    {
        printf("data(%d)가 %d 번째 Index에 있습니다. \n", data, result);
    }

    data = 9;
    result = binarySearch(a, sizeof(a)/sizeof(int), data);
    if ( result == BIN_SEARCH_NOT_FOUND )
    {
        printf("(%d)를 찾을 수 없습니다. \n", data);
    }
    else
    {
        printf("data(%d)가 %d 번째 Index에 있습니다. \n", data, result);
    }

    data = 9;
    result = bisectLeft(a, sizeof(a)/sizeof(int), data);
    printf("data(%d)가 %d 번째 Index에 삽입됩니다. \n", data, result);
    data = 31;
    result = bisectLeft(a, sizeof(a)/sizeof(int), data);
    printf("data(%d)가 %d 번째 Index에 삽입됩니다. \n", data, result);

    data = 55;
    result = bisectLeft(a, sizeof(a)/sizeof(int), data);
    printf("data(%d)가 %d 번째 Index에 삽입됩니다. \n", data, result);

    data = 9;
    result = bisectRight(a, sizeof(a)/sizeof(int), data);
    printf("data(%d)가 %d 번째 Index에 삽입됩니다. \n", data, result);
    data = 31;
    result = bisectRight(a, sizeof(a)/sizeof(int), data);
    printf("data(%d)가 %d 번째 Index에 삽입됩니다. \n", data, result);

    data = 55;
    result = bisectRight(a, sizeof(a)/sizeof(int), data);
    printf("data(%d)가 %d 번째 Index에 삽입됩니다. \n", data, result);

    return 0;
}