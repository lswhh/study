#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN (256)

char *search(char *aText, char *aKey)
{
    int m,n;
    char *p;

    m = strlen(aText);
    n = strlen(aKey);
    for ( p = aText; p <= (aText + m - n); p++) {
         if ( strncmp(p , aKey, n) == 0 )
         {
            return p;
         }
            
    }
    return NULL;
}

void replace(char *aText, char *aKey, char *aRep)
{
    char *sPtr = NULL;
    char sBuf[MAX_LINE_LEN];

    sPtr = search( aText, aKey );
    while ( sPtr != NULL ) 
    {
        *sPtr = '\0';
        strcpy( (char*)sBuf, sPtr + strlen(aKey));
        strcat( aText, aRep );
        strcat(aText, (const char*)sBuf );
        sPtr = search( sPtr + strlen(aRep), aKey );
    }
}

int main(void)
{
    int k;
    char* array1[] = {"leo", "kiki", "eden"};
    char* array2[] = {"marina", "josipa", "nikola", "vinko", "filipa"};
    char* array3[] = {"mislav", "stanko", "mislav", "ana"};

    static char sText[][MAX_LINE_LEN]={"   --- 진달래꽃 ---",
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
    while (sText[k][0]!='\0') {
        replace(sText[k],"진달래꽃","무궁화0000");
        replace(sText[k],"다","오");
        printf("%s\n",sText[k]);
        k++;
    }


    return 0;
}

