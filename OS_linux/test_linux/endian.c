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

    if ( ((char*)(&sData))[0] == 1)
    {
        printf("little endian");
    }
    else
    {
        printf("big endian");
    }

    return 0;
}