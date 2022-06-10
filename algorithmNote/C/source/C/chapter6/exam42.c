/*
 * ---------------------------------------
 *      �迭�� �̿��� ���� Ž�� Ʈ��     *
 * ---------------------------------------
 */

#include <stdio.h>
#include <string.h>

#define nil -1
#define MaxSize 100

struct tnode {
    int left;           /* ���� �κ� Ʈ���� ����Ű�� ������ */
    char name[12];
    int right;          /* ������ �κ� Ʈ���� ����Ű�� ������ */
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
            printf("ã�ҽ��ϴ�.\n");
            break;
        }
        else if (strcmp(key,a[p].name)<0)
            p=a[p].left;                    /* ���� �κ� Ʈ���� �̵� */
        else
            p=a[p].right;                   /* ������ �κ� Ʈ���� �̵� */
    }

    return 0;
}
