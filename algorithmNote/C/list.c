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
/*
 * Example :
 *      struct { utList mList; int a; } sBar;
 *      utList * sIterator;
 *      UT_LIST_ITERATE(&sBar.mList, sIterator)
 *      {
 *          ..... whatever you want to do
 *          단지, 리스트의 구성 멤버중 하나를 삭제하는 일을 해서는 안된다.
 *          리스트의 멤버를 삭제하고자 할 때에는
 *          UT_LIST_ITERATE_SAFE() 를 쓰도록 해야 한다.
 *      }
 */

#define UT_LIST_ITERATE(aHead, aIterator)                              \
    for ((aIterator) = (aHead)->mNext;                                  \
         (aIterator) != (aHead);                                        \
         (aIterator) = (aIterator)->mNext)

#define UT_LIST_ITERATE_BACK(aHead, aIterator)                         \
    for ((aIterator) = (aHead)->mPrev;                                  \
         (aIterator) != (aHead);                                        \
         (aIterator) = (aIterator)->mPrev)
/***********************************************************************
*
* Description :
*  aHead를 갖는 리스트에서 aNode 다음 노드부터 마지막 노드까지 aIterator에 
*  반환해 준다.
*  aHead          - [IN]  리스트 헤더 포인터
*  aNode          - [IN]  Iterator를 통해 검색을 원하는 노드의 Previous 노드
*  aIterator      - [OUT] 반환되는 노드
*
**********************************************************************/
#define UT_LIST_ITERATE_AFTER2LAST(aHead, aNode, aIterator)            \
    for ((aIterator) = (aNode)->mNext;                                  \
         (aIterator) != (aHead);                                        \
         (aIterator) = (aIterator)->mNext)
/*
 * Example :
 *      struct { utList mList; int a; } sBar;
 *      utList * sIterator;
 *      utList * sNodeNext;
 *      UT_LIST_ITERATE_SAFE(&sBar.mList, sIterator, sNodeNext)
 *      {
 *          ..... whatever you want to do
 *      }
 */

#define UT_LIST_ITERATE_SAFE(aHead, aIterator, aNodeNext)              \
    for((aIterator) = (aHead)->mNext, (aNodeNext) = (aIterator)->mNext; \
        (aIterator) != (aHead);                                         \
        (aIterator) = (aNodeNext), (aNodeNext) = (aIterator)->mNext)

#define UT_LIST_ITERATE_BACK_SAFE(aHead, aIterator, aNodeNext)         \
    for((aIterator) = (aHead)->mPrev, (aNodeNext) = (aIterator)->mPrev; \
        (aIterator) != (aHead);                                         \
        (aIterator) = (aNodeNext), (aNodeNext) = (aIterator)->mPrev)

//fix PROJ-1596
#define UT_LIST_ITERATE_SAFE2(aHead, aList, aIterator, aNodeNext)      \
    for((aIterator) = aList, (aNodeNext) = (aIterator)->mNext;          \
        (aIterator) != (aHead);                                         \
        (aIterator) = (aNodeNext), (aNodeNext) = (aIterator)->mNext)

/*
 * Head List 초기화
 */

#define UT_LIST_INIT(aList)                                            \
    do                                                                  \
    {                                                                   \
        (aList)->mPrev = (aList);                                       \
        (aList)->mNext = (aList);                                       \
        (aList)->mObj  = NULL;                                          \
    } while (0)

/*
 * List Node 초기화
 */

#define UT_LIST_INIT_OBJ(aList, aObj)                                  \
    do                                                                  \
    {                                                                   \
        (aList)->mPrev = (aList);                                       \
        (aList)->mNext = (aList);                                       \
        (aList)->mObj  = (aObj);                                        \
    } while (0)

/*
 * =====================================
 * List 에 item 추가하는 루틴들
 * =====================================
 *
 * 1. UT_LIST_ADD_AFTER(aNode1, aNode2)
 *    aNode1 앞에 aNode2 추가
 *
 * 2. UT_LIST_ADD_BEFORE(aNode1, aNode2)
 *    aNode1 뒤에 aNode2 추가
 *
 * 3. UT_LIST_ADD_FIRST
 *    List 처음에 aNode 추가
 *
 *    삽입 전
 *     +------------------------------------------------+
 *     |                                                |
 *     +--> head <---> item1 <---> item2 <---> item3 <--+
 *                 ^
 *                 |
 *                 +-----삽입 포인트
 *    삽입 후
 *     +----------------------------------------------------------+
 *     |                                                          |
 *     +--> head <---> NEW <---> item1 <---> item2 <---> item3 <--+
 *
 *
 * 4. UT_LIST_ADD_LAST
 *    List 마지막에 aNode 추가
 *
 *    삽입 전
 *     +--------------------------------------------------+
 *     |                                                  |
 *     +---> head <---> item1 <---> item2 <---> item3 <---+
 *                                                      ^
 *                                                      |
 *                        삽입 포인트-------------------+
 *    삽입 후
 *     +----------------------------------------------------------+
 *     |                                                          |
 *     +--> head <---> item1 <---> item2 <---> item3 <---> NEW <--+
 */

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

/*
 * ===================
 * List에서 aNode 삭제
 * ===================
 */

#define UT_LIST_REMOVE(aNode)                                          \
    do                                                                  \
    {                                                                   \
        (aNode)->mNext->mPrev = (aNode)->mPrev;                         \
        (aNode)->mPrev->mNext = (aNode)->mNext;                         \
    } while (0)

/*
 * ======================
 * List가 비어있는지 검사
 * ======================
 */

#define UT_LIST_IS_EMPTY(aList)                                        \
    ((((aList)->mPrev == (aList)) && ((aList)->mNext == (aList)))       \
     ? UT_TRUE : UT_FALSE)

/*
 * ==============================
 *
 * List에 다른 List의 Node를 합침
 *
 * ==============================
 *
 * ---------------------
 * 1. UT_LIST_JOIN_NODE
 * ---------------------
 *
 *      Join 전
 *       +------------------------------------+
 *       |                                    |
 *       +--> List <---> item1 <---> item2 <--+
 *
 *                  +-------------------+
 *                  |                   |
 *       aNode --> ITEMA <---> ITEMB <--+
 *
 *      Join 후
 *       +------------------------------------------------------------+
 *       |                                                            |
 *       +--> List <---> item1 <---> item2 <---> ITEMA <---> ITEMB <--+
 *                                                 ^
 *                                                 |
 *             aNode ------------------------------+
 *
 * ---------------------
 * 2. UT_LIST_JOIN_LIST
 * ---------------------
 *      - aList2가 비어있으면 아무 일도 없음
 *      - 합쳐진 후 aList2는 초기화됨
 *
 *      Join 전
 *       +------------------------------------+
 *       |                                    |
 *       +--> List1 <--> item1 <---> item2 <--+
 *
 *       +------------------------------------------------+
 *       |                                                |
 *       +--> List2 <--> ITEMA <---> ITEMB <---> ITEMC <--+
 *
 *      Join 후
 *       +------------------------------------------------------------------------+
 *       |                                                                        |
 *       +--> List1 <--> item1 <---> item2 <---> ITEMA <---> ITEMB <---> ITEMC <--+
 *
 *       +--> List2 <--+
 *       |             |
 *       +-------------+
 */

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

/*
 * ==============================
 *
 * List 를 두개의 List 로 나누기
 *
 * ==============================
 *
 * ----------------------
 * 1. UT_LIST_SPLIT_LIST
 * ----------------------
 *   aSourceList 에서 aNode 부터 끝까지 뚝 떼어서 aNewList 를 만든다
 *
 *   a. aSourceList 와 aNode 가 같거나, aSourceList 가 비어 있는 경우
 *      아무일도 안일어난다.
 *
 *   b. aSourceList 에 노드가 하나밖에 없는 경우
 *
 *      Split 전
 *       +-------------------------------+
 *       |                               |
 *       +--> aSourceList <---> item1 <--+
 *                                ^
 *       +----------------+       |
 *       |                |       |
 *       +--> aNewList <--+       +-- aNode
 *
 *      Split 후
 *       +-------------------+
 *       |                   |
 *       +--> aSourceList <--+
 *
 *       +----------------------------+
 *       |                            |
 *       +--> aNewList <---> item1 <--+
 *                             ^
 *                             |
 *                             +------- aNode
 *   c. 일반적인 경우
 *
 *      Split 전
 *       +-------------------------------------------------------------------+
 *       |                                                                   |
 *       +--> aSourceList <---> item1 <---> item2 <---> item3 <---> item4 <--+
 *                                                        ^
 *       +----------------+                               |
 *       |                |                               |
 *       +--> aNewList <--+          aNode ---------------+
 *
 *      Split 후
 *       +-------------------------------------------+
 *       |                                           |
 *       +--> aSourceList <---> item1 <---> item2 <--+
 *
 *       +----------------------------------------+
 *       |                                        |
 *       +--> aNewList <---> item3 <---> item4 <--+
 *                             ^
 *                             |
 *                             +------- aNode
 *
 */

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

typedef struct dNode {
    utListNode mNode;
    int mStrLen;
    char mString[1];
} dNode;

typedef struct myData {
    utListNode mNode;
    void * mData;
} myData;

#include <stddef.h>
#include <string.h>

int main()
{
    utList sList;
    utListNode * sNode;
    utListNode * sDummy;
    dNode * sData = NULL;
    int sSize = 0;

    char * sStaticData[5] = {"안녕하세요", "테스트 입니다 길이를 구해주세요", "delete", "abcdefghijklmn",  NULL}; 
    char * sStaticData2[3][2] = {{"안녕하세요", "첫째행"},
                              {"테스트 입니다 길이를 구해주세요", "둘째행"}, 
                              {"abcdefghijklmn", "셋째행"}}; 
    int i = 0;

    UT_LIST_INIT(&sList);

    for( i = 0; sStaticData[i] != NULL; i++ ) 
    {
        sSize = offsetof(dNode, mString) + strlen(sStaticData[i]);
        printf("offsetof size: %d\n", sSize);
        // sSize = sizeof(dNode) + strlen(sStaticData[i]) - 1;
        // printf("sizeof size: %d\n", sSize);

        sData = malloc(sSize);
        sData->mStrLen = strlen(sStaticData[i]);
        sprintf(sData->mString,"%s", sStaticData[i]);
        UT_LIST_INIT_OBJ( &(sData->mNode), sData );
        UT_LIST_ADD_LAST(&sList, &(sData->mNode));
    }

    UT_LIST_ITERATE(&sList, sNode)
    {
        sData = (dNode*)sNode->mObj;
        printf("len:%d, string: %s \n", sData->mStrLen, sData->mString );
    }

    UT_LIST_ITERATE_BACK(&sList, sNode)
    {
        sData = (dNode*)sNode->mObj;
        printf("len:%d, string: %s \n", sData->mStrLen, sData->mString );
    }
    UT_LIST_ITERATE_SAFE( &sList, sNode, sDummy )
    {
        sData = (dNode*)sNode->mObj;
        //if (strncmp(sData->mString, "delete", sData->mStrLen) == 0)
        if (strcmp(sData->mString, "delete") == 0)
        {
            printf("remove delete node \n");
            UT_LIST_REMOVE( sNode );
            free( sData );
        }
    }
    usleep(500000);
    UT_LIST_ITERATE_SAFE( &sList, sNode, sDummy )
    {
        sData = (dNode*)sNode->mObj;
        printf("len:%d, string: %s \n", sData->mStrLen, sData->mString);
        UT_LIST_REMOVE( sNode );
        free( sData );
    }

    if ( UT_LIST_IS_EMPTY(&sList) == UT_TRUE )
    {
        printf("list empty ok \n");
    }
    return 0;
}