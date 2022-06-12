
// https://programmers.co.kr/learn/courses/30/lessons/42576
// 완주하지 못한 선수
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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
    char data[20];
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
    TEST_RAISE(dataLen > 20, ERR_LEN);
    sData->dataLen = dataLen;
    memcpy(sData->data, data, dataLen);
    
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

int hashDelete(hashUtil * hashObj, char * key)
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
        printf("do not exist key: %s", key);
    }
    EXCEPTION_END;
    return RESULT_FAILURE;
}

char * solution(char ** participant, int participantSize, char ** completion, int completionSize)
{
    utList sResultList;
    utListNode * sNode;
    utListNode * sDummy;
    hashUtil sParticipantHashObj;
    int i = 0;
    hashData * sData;
    char * sResultStr = NULL;
    int sResultCount = 0;

    TEST_END(hashInitialize(&sParticipantHashObj, 11) != RESULT_SUCCESS);
    for ( i = 0; i < participantSize; i++ )
    {
        hashInsert(&sParticipantHashObj, 
                    participant[i], /* key */
                    (void*)&i,      /* data: index */
                    sizeof(int));
    }
    
    for ( i = 0; i < completionSize; i++ )
    {
        TEST_END( hashDelete(&sParticipantHashObj, completion[i]) != RESULT_SUCCESS );
    }

    UT_LIST_INIT(&sResultList);
    hashGetAllWithRemove(&sParticipantHashObj, &sResultList);

    UT_LIST_ITERATE_SAFE(&sResultList, sNode, sDummy)
    {
        sResultCount += 1;
        UT_LIST_REMOVE(sNode);
        sData = (hashData*)sNode->mObj;
        sResultStr = sData->key;
        TEST_END(sResultCount > 1);
    }

    hashFinalize(&sParticipantHashObj);

    return sResultStr;

    EXCEPTION_END;
    hashFinalize(&sParticipantHashObj);
    removeAll(&sResultList);
    return NULL;
}

int main()
{
    char* array1[] = {"leo", "kiki", "eden"};
    char* array2[] = {"marina", "josipa", "nikola", "vinko", "filipa"};
    char* array3[] = {"mislav", "stanko", "mislav", "ana"};
    char* completion1[] = {"eden", "kiki"};
    char* completion2[] = {"josipa", "filipa", "marina", "nikola"};
    char* completion3[] = {"stanko", "ana", "mislav"};
    printf("%s\n", solution(array1, 3, completion1, 2));              
    printf("%s\n", solution(array2, 5, completion2, 4));  
    printf("%s\n", solution(array3, 4, completion3, 3));  
    return 0;
}
// def solution(participant, completion):
//     plen = len(participant)
//     i = 0
//     participantDict = dict()
//     for person in participant:
//         if participantDict.get(person) == None:
//             participantDict[person] = 1
//         else:
//             participantDict[person] += 1

//     for compPerson in completion:
//         participantDict[compPerson] -= 1
//         if participantDict[compPerson] == 0 :
//             del participantDict[compPerson]

//     result = list(participantDict.keys())
//     answer = result[0]
//     return answer