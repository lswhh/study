#include <stdio.h>

#define ENDIAN_CONVERT2(dst, src)                    \
    do                                               \
    {                                                \
        *((char *)(dst) + 1) = *((char *)(src) + 0); \
        *((char *)(dst) + 0) = *((char *)(src) + 1); \
    } while (0)

#define ENDIAN_CONVERT4(dst, src)                    \
    do                                               \
    {                                                \
        *((char *)(dst) + 3) = *((char *)(src) + 0); \
        *((char *)(dst) + 2) = *((char *)(src) + 1); \
        *((char *)(dst) + 1) = *((char *)(src) + 2); \
        *((char *)(dst) + 0) = *((char *)(src) + 3); \
    } while (0)

#define ENDIAN_CONVERT8(dst, src)                    \
    do                                               \
    {                                                \
        *((char *)(dst) + 7) = *((char *)(src) + 0); \
        *((char *)(dst) + 6) = *((char *)(src) + 1); \
        *((char *)(dst) + 5) = *((char *)(src) + 2); \
        *((char *)(dst) + 4) = *((char *)(src) + 3); \
        *((char *)(dst) + 3) = *((char *)(src) + 4); \
        *((char *)(dst) + 2) = *((char *)(src) + 5); \
        *((char *)(dst) + 1) = *((char *)(src) + 6); \
        *((char *)(dst) + 0) = *((char *)(src) + 7); \
    } while (0)

int main()
{
    int sData = 1;
    int data2 = 2;
    int data3= 3; //0x01000000;
    unsigned long long test = 0;
    int i = 0;
    memcpy(&test, &data2, sizeof(int));
    memcpy((char*)&test + 4, &sData, sizeof(int));
    printf("%lu\n", test);
    for ( i = 0 ; i < 8 ; i++)
    {
        printf("%x ", ((char*)&test)[i]);
    }
    printf("\n");
    memcpy(&test, &sData, sizeof(int));
    memcpy((char*)&test + 4, &data2, sizeof(int));
    printf("%lu\n", test);
    for ( i = 0 ; i < 8 ; i++)
    {
        printf("%x ", ((char*)(&test))[i]);
    }
    printf("\n");
    memcpy(&test, &sData, sizeof(int));
    memcpy((char*)&test + 4, &data3, sizeof(int));
    printf("%lu\n", test);
    unsigned long long A = 0;
    unsigned long long B = 0;
    int tmp = 0;
    long ltest = 0;
    printf("sizeof(tmp):%d, sizeof(ltest):%d\n",sizeof(tmp), sizeof(ltest) );
    tmp = 1;
    memcpy(&A, &tmp, 4);
    tmp = 3;
    memcpy((char*)&A + 4, &tmp, 4);
    tmp = 2;
    memcpy(&B, &tmp, 4);
    tmp = 3;
    memcpy((char*)&B + 4, &tmp, 4);

    if ( A > B )
        printf("A %lu is greater than B %lu \n", A, B);
    else if ( A == B )
        printf("A %lu is equal B %lu \n", A, B);
    else
        printf("B %lu is greater than A %lu \n", B, A);
    
    for ( i = 0 ; i < 8 ; i++)
    {
        printf("%x ", ((char*)(&test))[i]);
    }
    if ( ((char*)(&sData))[0] == 1)
    {
        printf("little endian \n");
    }
    else
    {
        printf("big endian \n");
    }

    return 0;
}