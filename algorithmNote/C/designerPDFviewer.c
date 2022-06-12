// When a contiguous block of text is selected in a PDF viewer, the selection is highlighted with a blue rectangle. In this PDF viewer, each word is highlighted independently. For example:

// PDF-highighting.png

// There is a list of  character heights aligned by index to their letters. For example, 'a' is at index  and 'z' is at index . There will also be a string. Using the letter heights given, determine the area of the rectangle highlight in  assuming all letters are  wide.

// Example
 

// The heights are  and . The tallest letter is  high and there are  letters. The hightlighted area will be  so the answer is .

// Function Description

// Complete the designerPdfViewer function in the editor below.

// designerPdfViewer has the following parameter(s):

// int h[26]: the heights of each letter
// string word: a string
// Returns

// int: the size of the highlighted area
// Input Format

// The first line contains  space-separated integers describing the respective heights of each consecutive lowercase English letter, ascii[a-z].
// The second line contains a single word consisting of lowercase English alphabetic letters.

// Constraints

// , where  is an English lowercase letter.
//  contains no more than  letters.
// Sample Input 0

// 1 3 1 3 1 4 1 3 2 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
// abc
// Sample Output 0

// 9
// Explanation 0

// We are highlighting the word abc:

// Letter heights are ,  and . The tallest letter, b, is  high. The selection area for this word is .

// Note: Recall that the width of each character is .

// Sample Input 1

// 1 3 1 3 1 4 1 3 2 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 7
// zaba
// Sample Output 1

// 28
// Explanation 1

// The tallest letter in  is  at . The selection area for this word is .

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
 * https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true
 * Complete the 'designerPdfViewer' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h
 *  2. STRING word
 */
#define RESULT_SUCCESS (0)
#define RESULT_FAILURE (-1)
#define EXCEPTION_END EXCEPTION_END_LABEL:
#define TEST_RAISE( a, b ) { if( a ) {  goto b; } }
#define TEST_RAISE_END( a ) { if( a ) {  goto EXCEPTION_END_LABEL; } }
#define RAISE(a) {  goto a; }
#define EXCEPTION(a) goto EXCEPTION_END_LABEL; a:

int designerPdfViewer(int h_count, int* h, char* word) {
    int sLen = strlen(word);
    int i = 0;
    int sMaxHight = 0;
    int sCharIndex = 0;

    for ( i = 0; i < sLen; i++ )
    {
        sCharIndex = word[i] - 'a';
        TEST_RAISE_END( sCharIndex >= h_count );
        if ( sMaxHight < h[sCharIndex] )
        {
            sMaxHight = h[sCharIndex];
        }
    }

    return (sMaxHight * sLen);
    EXCEPTION_END;
    return -1;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** h_temp = split_string(rtrim(readline()));

    int* h = malloc(26 * sizeof(int));

    for (int i = 0; i < 26; i++) {
        int h_item = parse_int(*(h_temp + i));

        *(h + i) = h_item;
    }

    char* word = readline();

    int result = designerPdfViewer(26, h, word);

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
