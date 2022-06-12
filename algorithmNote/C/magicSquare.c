#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * https://www.hackerrank.com/challenges/magic-square-forming/problem?isFullScreen=true
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */
typedef enum myBool {
    MY_TRUE = 1,
    MY_FALSE = 0
} myBool;
#define RESULT_SUCCESS (0)
#define RESULT_FAILURE (-1)
#define EXCEPTION_END EXCEPTION_END_LABEL:
#define TEST_RAISE( a, b ) { if( a ) {  goto b; } }
#define TEST_RAISE_END( a ) { if( a ) {  goto EXCEPTION_END_LABEL; } }
#define RAISE(a) {  goto a; }
#define EXCEPTION(a) goto EXCEPTION_END_LABEL; a:
#define MAGIC_CONSTANT (15)

myBool checkIsMagicSquare(int aRowCnt, int aColCnt, int **aSquare)
{
    int sRowSum = 0;
    int sColSum = 0;
    int sDiagonalSum1 = 0;
    int sDiagonalSum2 = 0;
    int i = 0;
    int j = 0;
    int sColIdx, sRowIdx;
    int sCount = aRowCnt; 
    myBool result = MY_FALSE;

    TEST_RAISE_END( aRowCnt != aColCnt );

    for ( i = 0; i < sCount; i++ )
    {
        sColSum = 0;
        sRowSum = 0;
        for ( j = 0; j < sCount; j++ )
        {
            sColSum += aSquare[i][j];
            sRowSum += aSquare[j][i];
        }
        TEST_RAISE_END( sColSum != MAGIC_CONSTANT );
        TEST_RAISE_END( sRowSum != MAGIC_CONSTANT );
        sRowIdx = i;
        sColIdx = i;
        sDiagonalSum1 += aSquare[sRowIdx][sColIdx];
        sRowIdx = i;
        sColIdx = aColCnt - 1 - i;
        sDiagonalSum2 += aSquare[sRowIdx][sColIdx];
    }
    TEST_RAISE_END( sDiagonalSum1 != MAGIC_CONSTANT );
    TEST_RAISE_END( sDiagonalSum2 != MAGIC_CONSTANT );

    return MY_TRUE;
    EXCEPTION_END;
    return MY_FALSE;
}

int formingMagicSquare(int s_rows, int s_columns, int** s) {
    
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int** s = malloc(3 * sizeof(int*));

    for (int i = 0; i < 3; i++) {
        *(s + i) = malloc(3 * (sizeof(int)));

        char** s_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 3; j++) {
            int s_item = parse_int(*(s_item_temp + j));

            *(*(s + i) + j) = s_item;
        }
    }

    int result = formingMagicSquare(3, 3, s);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

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

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
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

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
