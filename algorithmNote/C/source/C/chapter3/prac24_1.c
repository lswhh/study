/*
 * ------------------------------
 *     문자열 치환 (replace)    *
 * ------------------------------
 */

#include <stdio.h>
#include <string.h>

void replace(char *,char *,char *);
char *search(char *,char *);

int main(void)
{
    int k;
    static char text[][256]={"   --- 진달래꽃 ---",
                                "나 보기가 역겨워",
                                "가실 때에는",
                                "말없이 고이 보내 드리오리다.",
                                "영변에 약산",
                                "진달래꽃",
                                "아름 따다 가실 길에 뿌리오리다.",
                                "가시는 걸음걸음",
                                "놓인 그 꽃을",
                                "사뿐히 즈려 밟고 가시옵소서.",
                                "나 보기가 역겨워",
                                "가실 때에는",
                                "죽어도 아니 눈물 흘리오리다.",
                                ""};
    k=0;
    while (text[k][0]!='\0') {
        replace(text[k],"진달래꽃","무궁화");
        replace(text[k],"다","오");
        printf("%s\n",text[k]);
        k++;
    }

    return 0;
}

void replace(char *text,char *key,char *rep)
{
    char *p,buf[256];

    p=search(text,key);
    while (p!=NULL) {
        *p='\0';
        strcpy(buf,p+strlen(key));
        strcat(text,rep);
        strcat(text,buf);
        p=search(p+strlen(rep),key);
    }
}

char *search(char *text,char *key)
{
    int m,n;
    char *p;

    m=strlen(text);
    n=strlen(key);
    for (p=text;p<=text+m-n;p++) {
         if (strncmp(p,key,n)==0)
            return p;
    }
    return NULL;
}
