/*
 * ----------------------
 *      ���� Ž����     *
 * ----------------------
 */

#include <stdio.h>
#include <string.h>

#define N 10       /* ������ �� */

int main(void)
{
    static struct girl{
        char *name;
        int age;
    } a[]={"Ann",18,"Rolla",19,"Nancy",16,"Eluza",17,"Juliet",
            18,"Machilda",20,"Emy",15,"Candy",16,"Ema",17,
            "Mari",18};
    char key[20];
    int i;

    printf("Ž���� �����ʹ�? ");scanf("%s",key);

    i=0;
    while (i<N && strcmp(key,a[i].name)!=0)
        i++;

    if (i<N)
        printf("%s %d\n",a[i].name,a[i].age);
    else
        printf("ã�� �� �����ϴ�.\n");

    return 0;
}