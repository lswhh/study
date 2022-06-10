/*
 * ------------------------------------------------
 *      리스트를 이용한 해시 (마지막에 추가)      *
 * ------------------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define TableSize 1000
#define ModSize   1000

int hash(char *);

struct tfield {
    char name[12];
    char tel[12];
    struct tfield *pointer;
} *dat[TableSize];             /* 포인터 테이블 */

struct tfield *talloc(void);

int main(void)
{
    int n;  
    char key[12];
    struct tfield *p,*q;

    for (n=0;n<TableSize;n++)    /* 포인터 테이블 초기화 */
        dat[n]=NULL;

    printf("이름  전화번호\n");
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF) {
        n=hash(p->name);
        if (dat[n]==NULL) {            /* 비어있을 경우 */
            dat[n]=p;
            p->pointer=NULL;
        }       
        else {                        /* 충돌한 경우 */
            q=dat[n];
            while (q->pointer!=NULL)  /* 마지막에 추가 */
                q=q->pointer;
            q->pointer=p;
            p->pointer=NULL;
        }
    }

    rewind(stdin);                               /* 탐색 */
    printf("\n탐색할 데이터를 입력하시기 바랍니다.\n");
    while (scanf("%s",key)!=EOF) {
        n=hash(key);
        p=dat[n];
        while (p!=NULL) {
            if (strcmp(key,p->name)==0)
                printf("%15s%15s\n",p->name,p->tel);
            p=p->pointer;
        }
    }

	return 0;
}

int hash(char *s)         /* 해시함수 */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}

struct tfield *talloc(void)        /* 메모리 할당 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

