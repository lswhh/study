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

#define UT_LIST_GET_FIRST(base)  (base)->mNext

#define UT_LIST_GET_LAST(base)  (base)->mPrev

#define RESULT_SUCCESS (0)
#define RESULT_FAILURE (-1)
#define EXCEPTION_END EXCEPTION_END_LABEL:
#define TEST_RAISE( a, b ) { if( a ) {  goto b; } }
#define TEST_END( a ) { if( a ) {  goto EXCEPTION_END_LABEL; } }
#define RAISE(a) {  goto a; }
#define EXCEPTION(a) goto EXCEPTION_END_LABEL; a:

/* queue */
int queueIn(utList *aBase, void * aData)
{
    utListNode * sNode = NULL;
    sNode = malloc(sizeof(utListNode));

    UT_LIST_INIT_OBJ(sNode, aData);
    UT_LIST_ADD_LAST(aBase, sNode);

    return RESULT_SUCCESS;
}

int queueOut(utList *aBase, void ** aData)
{
    utListNode * sNode = NULL;

    TEST_END( UT_LIST_IS_EMPTY(aBase) == UT_TRUE );
    
    sNode = UT_LIST_GET_FIRST(aBase);
    UT_LIST_REMOVE(sNode);
    *aData = sNode->mObj;
    free(sNode);

    return RESULT_SUCCESS;
    EXCEPTION_END;
    return RESULT_FAILURE;
}
void removeAll(utList *aBase, int isDataFree)
{
    utListNode * sNode;
    utListNode * sDummy;
    UT_LIST_ITERATE_SAFE( aBase, sNode, sDummy )
    {
        UT_LIST_REMOVE( sNode );
        if ( isDataFree == UT_TRUE )
        {
            free(sNode->mObj);
        }
        free(sNode);
    }
}

int compareReverse(const void* aLhs, const void* aRhs)
{
    if ( *(int*)aLhs < *(int*)aRhs )
    {
        return 1;
    }
    else if ( *(int*)aLhs > *(int*)aRhs )
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
// https://programmers.co.kr/learn/courses/30/lessons/42587
// 1. 인쇄 대기목록의 가장 앞에 있는 문서(J)를 대기목록에서 꺼냅니다.
// 2. 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣습니다.
// 3. 그렇지 않으면 J를 인쇄합니다.
typedef struct printData {
    int location;
    int data;
} printData;
int solution(int * priority, int size, int location)
{
    utList sWaitList;
    int i = 0;
    int * sortedPriority = NULL;
    int   maxPriorityIdx = 0;
    printData * data;
    int sequence = 0;

    UT_LIST_INIT(&sWaitList);

    sortedPriority = malloc(sizeof(int) * size);
    memcpy(sortedPriority, priority, sizeof(int) * size);
    qsort(sortedPriority, size, sizeof(int), compareReverse);

    for ( i = 0; i < size; i++ ) 
    {
        data = malloc(sizeof(printData));
        data->location = i;
        data->data = priority[i];
        TEST_END(queueIn(&sWaitList, data) != RESULT_SUCCESS);
    }

    while ( UT_LIST_IS_EMPTY(&sWaitList) != UT_TRUE )
    {
        TEST_END(queueOut(&sWaitList,(void**)(&data)) != RESULT_SUCCESS);
        if ( data->data >= sortedPriority[maxPriorityIdx] )
        {
            // print
            sequence += 1;
            maxPriorityIdx += 1;

            if ( data->location == location )
            {
                break;
            }
            free(data);
        }
        else
        {
            TEST_END(queueIn(&sWaitList, (void*)data) != RESULT_SUCCESS);
        }
    }


    if ( UT_LIST_IS_EMPTY(&sWaitList) != UT_TRUE )
    {
        removeAll(&sWaitList, UT_TRUE);
    }

    return sequence;

    EXCEPTION_END;

    removeAll(&sWaitList, UT_TRUE);
    return -1;
}

int main()
{
    int array1[] = {2,1,3,2};
    int array2[] = {1,1,9,1,1,1};
    printf("%d\n", solution(array1, 4, 2));              
    printf("%d\n", solution(array2, 6, 0));  

    return 0;
}
//
// [2, 1, 3, 2]	2	1
// [1, 1, 9, 1, 1, 1]	0	5 
// def solution(priorities, location):
//     sequence = 0
//     while True:
//         job = priorities.pop(0)
//         if len(priorities) > 0 and job < max(priorities):
//             priorities.append(job)
//         else:
//             if location == 0:
//                 sequence += 1
//                 break
//             else:
//                 sequence += 1
//         if location == 0:
//             location = len(priorities) -1
//         else: 
//             location -= 1
//     answer = sequence
//     return answer
// #include <stdio.h>
// #include <stdlib.h>
// #include <stddef.h>
// #include <string.h>
// #include <string>
// #include <vector>
// using namespace std;    
// typedef struct utList utList;
// typedef struct utList utListNode;


// struct utList
// {
//     utList * mPrev;
//     utList * mNext;
//     void    * mObj;
// };

// typedef enum utBool 
// {
//     UT_TRUE = 1,
//     UT_FALSE = 0
// } utBool;

// #define UT_LIST_ITERATE(aHead, aIterator)                              \
//     for ((aIterator) = (aHead)->mNext;                                  \
//          (aIterator) != (aHead);                                        \
//          (aIterator) = (aIterator)->mNext)

// #define UT_LIST_ITERATE_SAFE(aHead, aIterator, aNodeNext)              \
//     for((aIterator) = (aHead)->mNext, (aNodeNext) = (aIterator)->mNext; \
//         (aIterator) != (aHead);                                         \
//         (aIterator) = (aNodeNext), (aNodeNext) = (aIterator)->mNext)

// #define UT_LIST_INIT(aList)                                            \
//     do                                                                  \
//     {                                                                   \
//         (aList)->mPrev = (aList);                                       \
//         (aList)->mNext = (aList);                                       \
//         (aList)->mObj  = NULL;                                          \
//     } while (0)

// #define UT_LIST_INIT_OBJ(aList, aObj)                                  \
//     do                                                                  \
//     {                                                                   \
//         (aList)->mPrev = (aList);                                       \
//         (aList)->mNext = (aList);                                       \
//         (aList)->mObj  = (aObj);                                        \
//     } while (0)

// #define UT_LIST_ADD_AFTER(aNode1, aNode2)                              \
//     do                                                                  \
//     {                                                                   \
//         (aNode1)->mNext->mPrev = (aNode2);                              \
//         (aNode2)->mNext        = (aNode1)->mNext;                       \
//         (aNode2)->mPrev        = (aNode1);                              \
//         (aNode1)->mNext        = (aNode2);                              \
//     } while (0)


// #define UT_LIST_ADD_BEFORE(aNode1, aNode2)                             \
//     do                                                                  \
//     {                                                                   \
//         (aNode1)->mPrev->mNext = (aNode2);                              \
//         (aNode2)->mPrev        = (aNode1)->mPrev;                       \
//         (aNode1)->mPrev        = (aNode2);                              \
//         (aNode2)->mNext        = (aNode1);                              \
//     } while (0)

// #define UT_LIST_ADD_FIRST(aHead, aNode) UT_LIST_ADD_AFTER(aHead, aNode)

// #define UT_LIST_ADD_LAST(aHead, aNode)  UT_LIST_ADD_BEFORE(aHead, aNode)

// #define UT_LIST_REMOVE(aNode)                                          \
//     do                                                                  \
//     {                                                                   \
//         (aNode)->mNext->mPrev = (aNode)->mPrev;                         \
//         (aNode)->mPrev->mNext = (aNode)->mNext;                         \
//     } while (0)

// #define UT_LIST_IS_EMPTY(aList)                                        \
//     ((((aList)->mPrev == (aList)) && ((aList)->mNext == (aList)))       \
//      ? UT_TRUE : UT_FALSE)

// #define UT_LIST_GET_FIRST(base)  (base)->mNext

// #define UT_LIST_GET_LAST(base)  (base)->mPrev

// #define RESULT_SUCCESS (0)
// #define RESULT_FAILURE (-1)
// #define EXCEPTION_END EXCEPTION_END_LABEL:
// #define TEST_RAISE( a, b ) { if( a ) {  goto b; } }
// #define TEST_END( a ) { if( a ) {  goto EXCEPTION_END_LABEL; } }
// #define RAISE(a) {  goto a; }
// #define EXCEPTION(a) goto EXCEPTION_END_LABEL; a:

// /* queue */
// int queueIn(utList *aBase, void * aData)
// {
//     utListNode * sNode = NULL;
//     sNode = (utListNode*)malloc(sizeof(utListNode));

//     UT_LIST_INIT_OBJ(sNode, aData);
//     UT_LIST_ADD_LAST(aBase, sNode);

//     return RESULT_SUCCESS;
// }

// int queueOut(utList *aBase, void ** aData)
// {
//     utListNode * sNode = NULL;

//     TEST_END( UT_LIST_IS_EMPTY(aBase) == UT_TRUE );
    
//     sNode = UT_LIST_GET_FIRST(aBase);
//     UT_LIST_REMOVE(sNode);
//     *aData = sNode->mObj;
//     free(sNode);

//     return RESULT_SUCCESS;
//     EXCEPTION_END;
//     return RESULT_FAILURE;
// }
// void removeAll(utList *aBase, int isDataFree)
// {
//     utListNode * sNode;
//     utListNode * sDummy;
//     UT_LIST_ITERATE_SAFE( aBase, sNode, sDummy )
//     {
//         UT_LIST_REMOVE( sNode );
//         if ( isDataFree == UT_TRUE )
//         {
//             free(sNode->mObj);
//         }
//         free(sNode);
//     }
// }

// int compareReverse(const void* aLhs, const void* aRhs)
// {
//     if ( *(int*)aLhs < *(int*)aRhs )
//     {
//         return 1;
//     }
//     else if ( *(int*)aLhs > *(int*)aRhs )
//     {
//         return -1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// // https://programmers.co.kr/learn/courses/30/lessons/42587
// // 1. 인쇄 대기목록의 가장 앞에 있는 문서(J)를 대기목록에서 꺼냅니다.
// // 2. 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣습니다.
// // 3. 그렇지 않으면 J를 인쇄합니다.
// typedef struct printData {
//     int location;
//     int data;
// } printData;
// int solution(vector<int> priorities, int location)
// {
//     utList sWaitList;
//     int i = 0;
//     int * sortedPriority = NULL;
//     int   maxPriorityIdx = 0;
//     printData * data;
//     int sequence = 0;
//     int *priority = priorities.data();
//     int size = priorities.size();
    
//     UT_LIST_INIT(&sWaitList);

//     sortedPriority = (int*)malloc(sizeof(int) * size);
//     memcpy(sortedPriority, priority, sizeof(int) * size);
//     qsort(sortedPriority, size, sizeof(int), compareReverse);

//     for ( i = 0; i < size; i++ ) 
//     {
//         data = (printData*)malloc(sizeof(printData));
//         data->location = i;
//         data->data = priority[i];
//         TEST_END(queueIn(&sWaitList, data) != RESULT_SUCCESS);
//     }

//     while ( UT_LIST_IS_EMPTY(&sWaitList) != UT_TRUE )
//     {
//         TEST_END(queueOut(&sWaitList,(void**)(&data)) != RESULT_SUCCESS);
//         if ( data->data >= sortedPriority[maxPriorityIdx] )
//         {
//             // print
//             sequence += 1;
//             maxPriorityIdx += 1;
//             if ( data->location == location )
//             {
//                 break;
//             }
//         }
//         else
//         {
//             TEST_END(queueIn(&sWaitList, (void*)data) != RESULT_SUCCESS);
//         }
//     }


//     if ( UT_LIST_IS_EMPTY(&sWaitList) != UT_TRUE )
//     {
//         removeAll(&sWaitList, UT_FALSE);
//     }

//     return sequence;

//     EXCEPTION_END;

//     removeAll(&sWaitList, UT_FALSE);
//     return -1;
// }