#include <stdio.h>
#include <stdlib.h>
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

#define UT_LIST_ITERATE_BACK(aHead, aIterator)                         \
    for ((aIterator) = (aHead)->mPrev;                                  \
         (aIterator) != (aHead);                                        \
         (aIterator) = (aIterator)->mPrev)

#define UT_LIST_ITERATE_AFTER2LAST(aHead, aNode, aIterator)            \
    for ((aIterator) = (aNode)->mNext;                                  \
         (aIterator) != (aHead);                                        \
         (aIterator) = (aIterator)->mNext)

#define UT_LIST_ITERATE_SAFE(aHead, aIterator, aNodeNext)              \
    for((aIterator) = (aHead)->mNext, (aNodeNext) = (aIterator)->mNext; \
        (aIterator) != (aHead);                                         \
        (aIterator) = (aNodeNext), (aNodeNext) = (aIterator)->mNext)

#define UT_LIST_ITERATE_BACK_SAFE(aHead, aIterator, aNodeNext)         \
    for((aIterator) = (aHead)->mPrev, (aNodeNext) = (aIterator)->mPrev; \
        (aIterator) != (aHead);                                         \
        (aIterator) = (aNodeNext), (aNodeNext) = (aIterator)->mPrev)

#define UT_LIST_ITERATE_SAFE2(aHead, aList, aIterator, aNodeNext)      \
    for((aIterator) = aList, (aNodeNext) = (aIterator)->mNext;          \
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


#define UT_LIST_JOIN_NODE(aList, aNode)                                \
    do                                                                  \
    {                                                                   \
        utList *sTmpNod;                                               \
                                                                        \
        (aList)->mPrev->mNext = (aNode);                                \
        (aNode)->mPrev->mNext = (aList);                                \
                                                                        \
        sTmpNod               = (aList)->mPrev;                         \
        (aList)->mPrev        = (aNode)->mPrev;                         \
        (aNode)->mPrev        = sTmpNod;                                \
    } while (0)

#define UT_LIST_JOIN_LIST(aList1, aList2)                              \
    do                                                                  \
    {                                                                   \
        if (UT_LIST_IS_EMPTY(aList2) != UT_TRUE)                       \
        {                                                               \
            UT_LIST_REMOVE(aList2);                                    \
            UT_LIST_JOIN_NODE(aList1, (aList2)->mNext);                \
            UT_LIST_INIT(aList2);                                      \
        }                                                               \
    } while (0)

#define UT_LIST_SPLIT_LIST(aSourceList, aNode, aNewList)           \
    do                                                              \
    {                                                               \
        if ((aNode) != (aSourceList))                               \
        {                                                           \
            if (UT_LIST_IS_EMPTY((aSourceList)) != UT_TRUE)        \
            {                                                       \
                (aNewList)->mPrev           = (aSourceList)->mPrev; \
                (aNewList)->mNext           = (aNode);              \
                                                                    \
                (aSourceList)->mPrev        = (aNode)->mPrev;       \
                (aSourceList)->mPrev->mNext = (aSourceList);        \
                                                                    \
                (aNode)->mPrev              = (aNewList);           \
                (aNewList)->mPrev->mNext    = (aNewList);           \
            }                                                       \
        }                                                           \
    } while (0)

// Previous 얻기
#define UT_LIST_GET_PREV(node)  (node)->mPrev

// Next 얻기
#define UT_LIST_GET_NEXT(node)  (node)->mNext


// 처음 노드로 가기
#define UT_LIST_GET_FIRST(base)  (base)->mNext

// 마지막 노드로 가기
#define UT_LIST_GET_LAST(base)  (base)->mPrev
/**************************************************/
#define log(fmt, ...) printf("[%s: %d][%s] " fmt , __FILE__, __LINE__, __func__, ##__VA_ARGS__);
/**************************************************/



typedef struct myData {
    utListNode mNode;
    void * mData;
} myData;

#include <stddef.h>
#include <string.h>

#define RESULT_SUCCESS (0)
#define RESULT_FAILURE (-1)
#define EXCEPTION_END EXCEPTION_END_LABEL:
#define TEST_RAISE( a, b ) { if( a ) {  goto b; } }
#define TEST_END( a ) { if( a ) {  goto EXCEPTION_END_LABEL; } }
#define RAISE(a) {  goto a; }
#define EXCEPTION(a) goto EXCEPTION_END_LABEL; a:
#define HANDLE_ERROR(en, msg) \
        do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)
#define THREAD_ID_NULL (0)
#define LIST_IS_EMPTY (-1)

typedef struct dNode {
    utListNode mNode;
    void * data;
} dNode;

/* stack */
int push(utList *aBase, void * aData)
{
    utListNode * sNode = NULL;
    sNode = malloc(sizeof(utListNode));

    TEST_END(sNode == NULL);
    UT_LIST_INIT_OBJ(sNode, aData);
    UT_LIST_ADD_LAST(aBase, sNode);

    return RESULT_SUCCESS;
    EXCEPTION_END;
    return RESULT_FAILURE;
}

int pop(utList *aBase, void ** aData)
{
    utListNode * sNode = NULL;

    TEST_END( UT_LIST_IS_EMPTY(aBase) == UT_TRUE );
    sNode = UT_LIST_GET_LAST(aBase);
    UT_LIST_REMOVE(sNode);
    *aData = sNode->mObj;
    free(sNode);

    return RESULT_SUCCESS;
    EXCEPTION_END;
    return RESULT_FAILURE;
}

void removeAll(utList *aBase, int aIsDataFree)
{
    utListNode * sNode;
    utListNode * sDummy;
    UT_LIST_ITERATE_SAFE( aBase, sNode, sDummy )
    {
        UT_LIST_REMOVE( sNode );
        if ( aIsDataFree == UT_TRUE )
        {
            free(sNode->mObj);
        }
        free(sNode);
    }
}

char* solution(char * aString)
{
    utList sList;
    int i = 0;
    char * sStrCharAt = NULL;
    char sNeed;
    int result = UT_FALSE;

    UT_LIST_INIT(&sList);

    int len = strlen(aString);
    for( i = 0; i < len; i++ )
    {
        switch (aString[i])
        {
            case '(':
            case '{':
            case '[':
                TEST_END(push(&sList, &(aString[i])) != RESULT_SUCCESS);
                break;

            case ')':
                sNeed = '(';
                TEST_END(pop(&sList, (void**)(&sStrCharAt)) != RESULT_SUCCESS);
                TEST_RAISE( sNeed != *sStrCharAt, DO_NOT_MATCH );
                break;
            case '}':
                sNeed = '{';
                TEST_END(pop(&sList, (void**)(&sStrCharAt)) != RESULT_SUCCESS);
                TEST_RAISE(sNeed != *sStrCharAt, DO_NOT_MATCH );
                break;
            case ']':
                sNeed = '[';
                TEST_END(pop(&sList, (void**)(&sStrCharAt)) != RESULT_SUCCESS);
                TEST_RAISE(sNeed != *sStrCharAt, DO_NOT_MATCH );
                break;
            default:
                RAISE(ERR_INPUT_STR);
                break;
        }
    }

    TEST_RAISE ( UT_LIST_IS_EMPTY(&sList) != UT_TRUE, DO_NOT_MATCH );

    removeAll(&sList, UT_FALSE);

    return (char*)"true\n";
    EXCEPTION(ERR_INPUT_STR) 
    {
        printf("input string error\n");
    }
    EXCEPTION(DO_NOT_MATCH) 
    {
        // printf("The parentheses do not match.\n");
    }
    EXCEPTION_END;

    removeAll(&sList, UT_FALSE);
    return (char*)"false\n";
}

int main()
{
    printf(solution("(){}[]"));             //true 
    printf(solution("{(})}){)}{(}{)})("));  //false
    printf(solution("{([])}"));             //true
    printf(solution("{[}]"));               //false
    return 0;
}