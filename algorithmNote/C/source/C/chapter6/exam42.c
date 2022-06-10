/*
 * ---------------------------------------
 *      배열을 이용한 이진 탐색 트리     *
 * ---------------------------------------
 */

#include <stdio.h>
#include <string.h>

#define nil -1
#define MaxSize 100

struct tnode {
    int left;           /* 왼쪽 부분 트리를 가리키는 포인터 */
    char name[12];
    int right;          /* 오른쪽 부분 트리를 가리키는 포인터 */
};

int main(void)
{
    struct tnode a[MaxSize]={{  1,"Matilda",  2},{  3,"Candy",  4},
                             {  5,"Rolla"   ,nil},{nil,"Ann"  ,nil},
                             {  6,"Emy"     ,  7},{nil,"Nancy",nil},
                             {nil,"Eluza"   ,nil},{nil,"Lisa" ,nil}};
    char key[20];
    int p;

    printf("Search name --> "); scanf("%s",key);
    p=0;
    while (p!=nil){
        if (strcmp(key,a[p].name)==0) {
            printf("찾았습니다.\n");
            break;
        }
        else if (strcmp(key,a[p].name)<0)
            p=a[p].left;                    /* 왼쪽 부분 트리로 이동 */
        else
            p=a[p].right;                   /* 오른쪽 부분 트리로 이동 */
    }

    return 0;
}
