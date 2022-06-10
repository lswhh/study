/*
 * -------------------------------------
 *      이분탐색트리에 데이터 추가     *
 * -------------------------------------
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

int sp=8;               /* 새로운 노드를 저장할 위치 */

int main(void)
{
    struct tnode a[MaxSize]={{  1,"Matilda",  2},{  3,"Candy",  4},
                             {  5,"Rolla"   ,nil},{nil,"Ann"  ,nil},
                             {  6,"Emy"     ,  7},{nil,"Nancy",nil},
                             {nil,"Eluza"   ,nil},{nil,"Lisa" ,nil}};
    char key[12];
    int p,old,i;

    printf("New name --> "); scanf("%s",key);
    p=0;                                /* 트리 탐색 */
    while (p!=nil) {
        old=p;
        if (strcmp(key,a[p].name)<=0)
            p=a[p].left;
        else
            p=a[p].right;
    }

    a[sp].left=a[sp].right=nil;         /* 새로운 데이터 연결 */
    strcpy(a[sp].name,key);
    if (strcmp(key,a[old].name)<=0)
        a[old].left=sp;
    else
        a[old].right=sp;
    sp++;

    for (i=0;i<sp;i++)                  /* 트리 출력 */
        printf("%4d%12s%4d\n",a[i].left,a[i].name,a[i].right);

	return 0;
}

