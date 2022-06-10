/*
 * -----------------------------------
 *      축차 탐색법 (break 사용)     *
 * -----------------------------------
 */

#include <stdio.h>
#include <string.h>

#define N 10       /* 데이터 수 */

int main(void)
{
    static struct girl {
        char *name;
        int age;
    } a[]={"Ann",18,"Rolla",19,"Nancy",16,"Eluza",17,"Juliet",18,
           "Machilda",20,"Emy",15,"Candy",16,"Ema",17,"Mari",18};
    char key[20];
    int i,flag=0;

    printf("탐색할 데이터는? ");scanf("%s",key);
    for (i=0;i<N;i++) {
        if (strcmp(key,a[i].name)==0) {
            printf("%s %d\n",a[i].name,a[i].age);
            flag=1;
            break;
        }
    }
    if (flag!=1)
        printf("찾을 수 없습니다.\n");

	return 0;
}

