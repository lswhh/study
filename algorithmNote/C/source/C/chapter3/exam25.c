/*
 * ----------------------
 *      해시 (hash)     *
 * ----------------------
 */

#include <stdio.h>
#include <string.h>

#define TableSize 1000
#define ModSize   1000

int hash(char *);

struct tel {             /* 데이터 테이블 */
    char name[12];
    char telnum[12];
}dat[TableSize];

int main(void)
{
    int n;
    char a[12],b[12];

    printf("이름 전화번호\n");
    while (scanf("%s %s",a,b)!=EOF) {
        n=hash(a);
        strcpy(dat[n].name,a);
        strcpy(dat[n].telnum,b);

    }

    rewind(stdin);
    printf("검색할 데이터를 입력하세요.\n");              /* 데이터 검색 */
    while (scanf("%s",a)!=EOF) {
        n=hash(a);
        printf("%15s%15s\n",dat[n].name,dat[n].telnum);
    }

    return 0;
}
int hash(char *s)    /* 해시함수 */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}
