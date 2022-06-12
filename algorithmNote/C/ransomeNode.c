// https://www.hackerrank.com/challenges/ctci-ransom-note/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps
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
 * Complete the 'checkMagazine' function below.
 *
 * The function accepts following parameters:
 *  1. STRING_ARRAY magazine
 *  2. STRING_ARRAY note
 */
typedef struct utList utList;
typedef struct utList utListNode;

struct utList
{
    utList * mPrev;
    utList * mNext;
    void    * mObj;
};

typedef enum utBool 
{
    UT_TRUE = 1,
    UT_FALSE = 0
} utBool;

#define UT_LIST_ITERATE(aHead, aIterator)                              \
    for ((aIterator) = (aHead)->mNext;                                  \
         (aIterator) != (aHead);                                        \
         (aIterator) = (aIterator)->mNext)

#define UT_LIST_ITERATE_SAFE(aHead, aIterator, aNodeNext)              \
    for((aIterator) = (aHead)->mNext, (aNodeNext) = (aIterator)->mNext; \
        (aIterator) != (aHead);                                         \
        (aIterator) = (aNodeNext), (aNodeNext) = (aIterator)->mNext)

#define UT_LIST_INIT(aList)                                            \
    do                                                                  \
    {                                                                   \
        (aList)->mPrev = (aList);                                       \
        (aList)->mNext = (aList);                                       \
        (aList)->mObj  = NULL;                                          \
    } while (0)

#define UT_LIST_INIT_OBJ(aList, aObj)                                  \
    do                                                                  \
    {                                                                   \
        (aList)->mPrev = (aList);                                       \
        (aList)->mNext = (aList);                                       \
        (aList)->mObj  = (aObj);                                        \
    } while (0)

#define UT_LIST_ADD_AFTER(aNode1, aNode2)                              \
    do                                                                  \
    {                                                                   \
        (aNode1)->mNext->mPrev = (aNode2);                              \
        (aNode2)->mNext        = (aNode1)->mNext;                       \
        (aNode2)->mPrev        = (aNode1);                              \
        (aNode1)->mNext        = (aNode2);                              \
    } while (0)


#define UT_LIST_ADD_BEFORE(aNode1, aNode2)                             \
    do                                                                  \
    {                                                                   \
        (aNode1)->mPrev->mNext = (aNode2);                              \
        (aNode2)->mPrev        = (aNode1)->mPrev;                       \
        (aNode1)->mPrev        = (aNode2);                              \
        (aNode2)->mNext        = (aNode1);                              \
    } while (0)

#define UT_LIST_ADD_FIRST(aHead, aNode) UT_LIST_ADD_AFTER(aHead, aNode)

#define UT_LIST_ADD_LAST(aHead, aNode)  UT_LIST_ADD_BEFORE(aHead, aNode)

#define UT_LIST_REMOVE(aNode)                                          \
    do                                                                  \
    {                                                                   \
        (aNode)->mNext->mPrev = (aNode)->mPrev;                         \
        (aNode)->mPrev->mNext = (aNode)->mNext;                         \
    } while (0)

#define UT_LIST_IS_EMPTY(aList)                                        \
    ((((aList)->mPrev == (aList)) && ((aList)->mNext == (aList)))       \
     ? UT_TRUE : UT_FALSE)

#define UT_LIST_GET_FIRST(base)  ((base)->mNext)

#define UT_LIST_GET_LAST(base)  ((base)->mPrev)

#define RESULT_SUCCESS (0)
#define RESULT_FAILURE (-1)
#define EXCEPTION_END EXCEPTION_END_LABEL:
#define TEST_RAISE( a, b ) { if( a ) {  goto b; } }
#define TEST_END( a ) { if( a ) {  goto EXCEPTION_END_LABEL; } }
#define RAISE(a) {  goto a; }
#define EXCEPTION(a) goto EXCEPTION_END_LABEL; a:

void removeAll(utList *aBase)
{
    utListNode * sNode;
    utListNode * sDummy;
    UT_LIST_ITERATE_SAFE( aBase, sNode, sDummy )
    {
        UT_LIST_REMOVE( sNode );
        free(sNode->mObj);
    }
}

typedef struct hashUtil{
    int size;
    utList * hashTable;
} hashUtil;

typedef struct hashData{
    utListNode node;
    char key[20];
    int dataLen;
    char *data; //[20];
} hashData;

unsigned int hash(char* key, int len, int hashSize)
{
    unsigned int result = 0;
    int i = 0;
    for ( i = 0; i < len; i++ )
    {
        result += (int)key[i];
    }
    return result % hashSize;
}

int hashInitialize(hashUtil * hashObj, int size)
{
    int i = 0;

    hashObj->hashTable = malloc(sizeof(utList) * size);
    TEST_RAISE(hashObj->hashTable == NULL, ERR_MALLOC);

    for ( i = 0; i < size; i++ )
    {
        UT_LIST_INIT(&(hashObj->hashTable[i]));
    }
    hashObj->size = size;

    return RESULT_SUCCESS;
    EXCEPTION(ERR_MALLOC)
    {
        printf("error malloc\n");
    }
    EXCEPTION_END;
    if ( hashObj->hashTable != NULL )
    {
        free(hashObj->hashTable);
    }

    return RESULT_FAILURE;
}

void hashFinalize(hashUtil * hashObj)
{
    int i = 0;
    utList *sList = NULL;
    for( i = 0; i < hashObj->size; i++ )
    {
        removeAll(&(hashObj->hashTable[i]));
    }
    free(hashObj->hashTable);
    hashObj->size = 0;
}

int hashInsert(hashUtil * hashObj, char * key, void * data, int dataLen)
{
    int sLen = 0;
    int sHashValue = 0;
    hashData * sData;
    sLen = strlen(key);
    sHashValue = hash(key, sLen, hashObj->size);
    sData = (hashData *)calloc(1, sizeof(hashData));
    TEST_END(sData == NULL);
    memcpy(sData->key, key, 20);
    // TEST_RAISE(dataLen > 20, ERR_LEN);
    sData->dataLen = 8;
    // memcpy(sData->data, data, dataLen);
    sData->data = data;
    UT_LIST_INIT_OBJ(&sData->node, sData);
    UT_LIST_ADD_LAST(&(hashObj->hashTable[sHashValue]), &(sData->node));

    return RESULT_SUCCESS;
    EXCEPTION(ERR_LEN)
    {
        printf("length error %d", dataLen);
    }
    EXCEPTION_END;
    return RESULT_FAILURE;
}

int hashGet(hashUtil * hashObj, char * key, hashData **data)
{
    int sLen = 0;
    int sHashValue = 0;
    hashData * sData;
    utList sList;
    utListNode * sNode;
    utListNode * sDummy;
    int sIsFound = UT_FALSE;

    sLen = strlen(key);
    sHashValue = hash(key, sLen, hashObj->size);
    UT_LIST_ITERATE_SAFE( &hashObj->hashTable[sHashValue], sNode, sDummy )
    {
        sData = (hashData*)sNode->mObj;
        if (strcmp(sData->key, key) == 0)
        {
            *data = sData;
            sIsFound = UT_TRUE;
        }
    }
    TEST_RAISE(sIsFound != UT_TRUE, ERR_NOT_FOUND);

    return RESULT_SUCCESS;

    EXCEPTION(ERR_NOT_FOUND)
    {
        printf("do not exist key: %s", key);
    }
    EXCEPTION_END;
    return RESULT_FAILURE;
}

void hashGetAllWithRemove(hashUtil * aHashObj, utList * aResultList)
{
    utList * sResultList = aResultList;
    int i;
    utList sList;
    utListNode * sNode;
    utListNode * sDummy;

    for ( i = 0; i < aHashObj->size; i++ )
    {
        UT_LIST_ITERATE_SAFE( &aHashObj->hashTable[i], sNode, sDummy )
        {
            UT_LIST_REMOVE(sNode);
            UT_LIST_ADD_LAST(sResultList, sNode);
        }
    }

    return;
}

int hashDelete(hashUtil * hashObj, char * key, char * data)
{
    int sLen = 0;
    int sHashValue = 0;
    hashData * sData;
    utList sList;
    utListNode * sNode;
    utListNode * sDummy;
    int sIsFound = UT_FALSE;

    sLen = strlen(key);
    sHashValue = hash(key, sLen, hashObj->size);
    UT_LIST_ITERATE_SAFE( &hashObj->hashTable[sHashValue], sNode, sDummy )
    {
        sData = (hashData*)sNode->mObj;
        if (strcmp(sData->key, key) == 0 && strcmp(sData->data, data) == 0 )
        {
            sIsFound = UT_TRUE;
            UT_LIST_REMOVE(sNode);
            free(sData);
            break;
        }
    }
    TEST_RAISE(sIsFound != UT_TRUE, ERR_NOT_FOUND);

    return RESULT_SUCCESS;

    EXCEPTION(ERR_NOT_FOUND)
    {
        printf("do not exist key: %s\n", key);
    }
    EXCEPTION_END;
    return RESULT_FAILURE;
}

char* checkMagazine(int magazine_count, char** magazine, int note_count, char** note) {

    utListNode * sNode;
    utListNode * sDummy;
    hashUtil magazineHashObj;
    int i = 0;
    hashData * sData;
    char * sResultStr = NULL;
    int sResultCount = 0;

    TEST_END(hashInitialize(&magazineHashObj, 7029) != RESULT_SUCCESS);

    for ( i = 0; i < magazine_count; i++ )
    {
        TEST_END( hashInsert(&magazineHashObj, 
                             magazine[i], /* key */
                            (void*)magazine[i],      /* data: index */
                            strlen(magazine[i])) != RESULT_SUCCESS);
    }

    for ( i = 0; i < note_count; i ++ )
    {
        TEST_RAISE( hashDelete(&magazineHashObj, 
                               note[i], 
                               note[i]) != RESULT_SUCCESS, 
                    NOT_FOUND);
    }

    hashFinalize(&magazineHashObj);

    return (char*)"Yes";
    EXCEPTION( NOT_FOUND )
    {
        printf("no data found\n");
    }
    EXCEPTION_END;

    return (char*)"No";
}

int main()
{
    // char** first_multiple_input = split_string(rtrim(readline()));

    // int m = parse_int(*(first_multiple_input + 0));

    // int n = parse_int(*(first_multiple_input + 1));

    // char** magazine_temp = split_string(rtrim(readline()));

    // char** magazine = malloc(m * sizeof(char*));

    // for (int i = 0; i < m; i++) {
    //     char* magazine_item = *(magazine_temp + i);

    //     *(magazine + i) = magazine_item;
    // }

    // char** note_temp = split_string(rtrim(readline()));

    // char** note = malloc(n * sizeof(char*));

    // for (int i = 0; i < n; i++) {
    //     char* note_item = *(note_temp + i);

    //     *(note + i) = note_item;
    // }
    //6
    // char* magazine[] = {"two", "times", "three", "is", "not", "four"}; 
    //5
    // char* note[] ={"two", "times", "two",  "is", "four"}; 
    char* magazine[] = {"give", "me", "one", "grand", "today", "night"};
    char* note[] = {"give", "one", "grand", "today"};
    printf("%s\n", checkMagazine(6, magazine, 4, note));

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
