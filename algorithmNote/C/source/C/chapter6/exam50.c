/*
 * -----------------------------------------
 *      질의응답과 결정트리 (배열 이용)    *
 * -----------------------------------------
 */

#include <stdio.h>

#define Max 100
#define nil -1

int main(void)
{
    struct tnode {
        int left;           /* 왼쪽을 가리키는 포인터 */
        char node[30];
        int right;          /* 오른쪽을 가리키는 포인터 */
    };
    static struct tnode a[Max]={{1  ,"연예인입니까?"  ,2},
                                {3  ,"가수입니까?"    ,4},
                                {nil,"이봉주"      ,nil},
                                {nil,"보아"    ,nil},
                                {5  ,"여배우입니까?"    ,6},
                                {nil,"최지우",nil},
                                {nil,"배용준"       ,nil}};
    int p,lp=6,c;
    int flag=0;

    do {
        p=0;
        if (flag)
            while ((c=getchar()) != '\n');

        while (a[p].left!=nil)           /* 트리 탐색 */
        {
            printf("%s (y/n) ",a[p].node);
            c=getchar();
            if (c=='y' || c=='Y')
                p=a[p].left;
            else
                p=a[p].right;
            while ((c=getchar()) != '\n');
        }

        printf("답은 %s 입니다.\n맞습니까? (y/n) ",a[p].node);
        c=getchar();

        if (c=='n' || c=='N')             /* 학습기능 */
        {
            a[lp+1]=a[p];                 /* 노드 이동 */
                                          /* 새로운 노드 생성 */
            printf("당신의 생각은? ");scanf("%s",a[lp+2].node);
            a[lp+2].left=a[lp+2].right=nil;
                                          /* 질문 노드 생성 */
            printf("%s 와 %s 을 구별하는 질문은? ",a[lp+1].node,a[lp+2].node);
            scanf("%s",a[p].node);
            printf("yes 항목은 %s (으)로 하겠습니까? (y/n) ",a[lp+1].node);
            c=getchar();

            if (c=='Y' || c=='y') {        /* 자식 노드 연결 */
                a[p].left=lp+1; a[p].right=lp+2;
            }
            else {
                a[p].left=lp+2; a[p].right=lp+1;
            }
            lp=lp+2;
        }
        while ((c=getchar()) != '\n');
    } while (flag=1, printf("계속 하겠습니까? (y/n) "), c=getchar(), c=='y' || c=='Y');

    return 0;
}
