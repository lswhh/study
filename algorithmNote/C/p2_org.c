#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define BIN_SEARCH_NOT_FOUND (INT_MAX)

// 춘식이가 가진 장난감을 나타내는 구조체입니다.
struct toy {
    int id;
    int likes;
    int priorityIdx;
    int idIdx;
    // 자유롭게 변수를 추가하실 수 있습니다.
};
struct priorityIndex {
    unsigned long long priority;
    int toyIdx;
};
struct idIndex {
    int id;
    int toyIdx;
};
// 춘식이가 가진 장난감 상자를 나타내는 구조체입니다.
struct box {
    // 자유롭게 변수를 추가하실 수 있습니다.
    struct toy * toys;
    struct priorityIndex * priorityIndices;
    struct idIndex * idIndices;
    int count;
    int capacity;
};

struct box *create(int capacity);
void destroy(struct box *box);
void put(struct box *box, int id, int likes);
int pop(struct box *box);
int del(struct box *box, int id);
void clear(struct box *box);
int binarySearchPri(struct priorityIndex * array, int arraySize, int key)
{
    int low = 0;
    int high = 0;
    int mid = 0;
    int result = BIN_SEARCH_NOT_FOUND;
    
    low = 0;
    high = arraySize - 1;
    while ( low <= high ) 
    {
        mid = ( low + high ) / 2;
        if ( array[mid].priority == key ) 
        {
            result = mid;
            break;
        }
        if ( array[mid].priority < key )
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return result;
}
int bisectLeftPri(struct priorityIndex * array, int arraySize, unsigned long long key)
{
    int low = 0;
    int high = 0;
    int mid = 0;
    int result = BIN_SEARCH_NOT_FOUND;
    
    low = 0;
    high = arraySize - 1;
    while ( low <= high ) 
    {
        mid = ( low + high ) / 2;
        if ( array[mid].priority == key ) 
        {
            result = mid;
            break;
        }
        if ( array[mid].priority < key )
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if ( result == BIN_SEARCH_NOT_FOUND )
    {
        result = mid;
    }
    return result;
}
int binarySearchId(struct idIndex * array, int arraySize, int key)
{
    int low = 0;
    int high = 0;
    int mid = 0;
    int result = BIN_SEARCH_NOT_FOUND;
    
    low = 0;
    high = arraySize - 1;
    while ( low <= high ) 
    {
        mid = ( low + high ) / 2;
        if ( array[mid].id == key ) 
        {
            result = mid;
            break;
        }
        if ( array[mid].id < key )
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return result;
}
int bisectLeftId(struct idIndex * array, int arraySize, int key)
{
    int low = 0;
    int high = 0;
    int mid = 0;
    int result = BIN_SEARCH_NOT_FOUND;
    
    low = 0;
    high = arraySize - 1;
    while ( low <= high ) 
    {
        mid = ( low + high ) / 2;
        if ( array[mid].id == key ) 
        {
            result = mid;
            break;
        }
        if ( array[mid].id < key )
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if ( result == BIN_SEARCH_NOT_FOUND )
    {
        result = mid;
    }
    return result;
}
struct box *create(int capacity)
{
    // 최대 `size`개의 장난감을 담을 수 있는 `box`를 생성하여 리턴합니다.
    //     - 이 함수는 항상 제일 먼저 호출됩니다.
    struct box * box = NULL;
    box = calloc(sizeof(struct box), 1);
    box->toys = calloc(sizeof(struct toy), capacity);
    box->priorityIndices = calloc(sizeof(struct priorityIndex), capacity);
    box->idIndices = calloc(sizeof(struct idIndex), capacity);
    box->count = 0;
    box->capacity = capacity;

    return box;
}

void destroy(struct box *box)
{
    // `create()`된 `box`를 정리합니다.
    //    - 이 함수는 `create()` 전에 호출되지 않으며 가장 마지막에 호출됩니다.
    //    - `destroy()`된 `box`는 더 이상 사용할 수 없어야합니다.
    box->count = 0;
    box->capacity = 0;
    free(box->toys);
    free(box->idIndices);
    free(box->priorityIndices);
    free(box);
}

void put(struct box *box, int id, int likes)
{
    // 새로운 장난감을 상자에 넣습니다.
    //    - 춘식이는 `likes`가 클 수록 장난감을 더 많이 좋아합니다.
    //    - 동일한 `id`를 가진 장난감은 동일한 `likes`를 가진다고 가정하여, 중복되어 들어오지 않습니다.
    //  - 동일한 `likes`를 가진 장난감이 존재한다면 더 높은 `id`를 가진 `toy`가 먼저 반환됩니다.
    //     - `box`에 공간이 없다면 새로운 장난감을 추가하지 않습니다.
    //  - 수행 시간은 O(logN) 이하의 시간 복잡도를 가져야 합니다.
    unsigned long long priority;
    int priIndex = 0;
    int idIndex = 0;
    if ( box->capacity <= box->count )
    {
        return;
    }

    memcpy((void*)&priority, (const void*)&likes, sizeof(int));
    memcpy((char*)&priority + 4, (const void*)&id, sizeof(int));
    priIndex = bisectLeftPri(box->priorityIndices, box->count, priority);
    if ( box->count - priIndex > 0 )
    {
        memcpy(&(box->priorityIndices[priIndex + 1]), &(box->priorityIndices[priIndex]), sizeof(struct priorityIndex) * (box->count - priIndex));
    }
    box->priorityIndices[priIndex].priority = priority;
    box->priorityIndices[priIndex].toyIdx = box->count;

    idIndex = bisectLeftId(box->idIndices, box->count, id);
    if ( box->count - idIndex > 0 )
    {
        memcpy(&(box->idIndices[idIndex + 1]), &(box->idIndices[idIndex]), sizeof(struct idIndex) * (box->count - idIndex));
    }
    box->idIndices[idIndex].id = id;
    box->idIndices[idIndex].toyIdx = box->count;

    box->toys[box->count].id = id;
    box->toys[box->count].likes = likes;
    box->toys[box->count].idIdx = idIndex;
    box->toys[box->count].priorityIdx = priIndex;
    box->count++;
}
void delIdIdx(struct box * box, int idIdx)
{
    int afterCount;
    afterCount = box->count - 1 - idIdx;
    if ( afterCount > 0 )
    {
        memcpy(&box->idIndices[idIdx], &box->idIndices[idIdx + 1], afterCount); 
    }
    box->idIndices[idIdx].id = 0;
    box->idIndices[idIdx].toyIdx = 0;
}
void delPriIdx(struct box * box, int priIdx)
{
    int afterCount;
    afterCount = box->count - 1 - priIdx;
    if ( afterCount > 0 )
    {
        memcpy(&box->priorityIndices[priIdx], &box->priorityIndices[priIdx + 1], afterCount); 
    }
    box->priorityIndices[priIdx].priority = 0;
    box->priorityIndices[priIdx].toyIdx = 0;
}
void delToyIdx(struct box * box, int toyIdx)
{
    int afterCount = box->count - 1 - toyIdx;
    
    if ( afterCount > 0 )
    {
        memcpy(&box->idIndices[toyIdx],&box->idIndices[toyIdx + 1], afterCount); 
    }
    box->toys[box->count-1].id = 0;
    box->toys[box->count-1].likes = 0;
    box->toys[box->count-1].priorityIdx = 0;
    box->toys[box->count-1].idIdx = 0;
}
int pop(struct box *box)
{
    // 장난감 상자에서 춘식이가 가장 좋아하는 장난감의 id를 반환합니다.
    //    - 춘식이는 `likes`가 클 수록 장난감을 더 많이 좋아합니다.
    //  - 동일한 `likes`를 가진 장난감이 존재한다면 더 높은 `id`를 가진 `toy`가 먼저 반환됩니다.
    //     - `box`가 비어있을 경우 `-1`을 반환합니다.
    //  - `box`에서 꺼낸 `toy`는 `box`에서 제거되어야 합니다.
    //  - 수행 시간은 O(logN) 이하의 시간 복잡도를 가져야 합니다.
    int index;
    int id = 0;

    if ( box->count <= 0 )
    {
        return -1;
    }

    index = box->priorityIndices[box->count -1].toyIdx;
    id = box->toys[index].id;

    delIdIdx(box, box->toys[box->count -1].idIdx);
    delPriIdx(box, box->toys[box->count -1].priorityIdx);
    delToyIdx(box, index);
    box->count--;

    return id;
}

int del(struct box *box, int id)
{
    // 장난감 상자에서 특정 id를 가진 장난감을 찾아 제거하고 `likes`를 반환합니다.
    //     - 요청된 `id`를 가진 `toy`가 존재하지 않으면 `-1`을 반환합니다.
    //  - `box`가 비어있을 경우 `-1`을 반환합니다.
    //  - 수행 시간은 O(logN) 이하의 시간 복잡도를 가져야 합니다.
    int index;
    int likes = -1;

    if ( box->count <= 0 )
    {
        return -1;
    }

    index = binarySearchId(box->idIndices, box->count, id);
    if ( index != BIN_SEARCH_NOT_FOUND )
    {
        likes = box->toys[index].likes;

        delIdIdx(box, box->toys[box->count -1].idIdx);
        delPriIdx(box, box->toys[box->count -1].priorityIdx);
        delToyIdx(box, index);
        box->count--;
    }
    else
    {
        return -1;
    }
    return likes;

}

void clear(struct box *box)
{
    // 장난감 상자를 모두 비웁니다.
    //     - `box`는 여전히 사용가능해야합니다.
    memset(box->priorityIndices, 0, box->capacity * sizeof(struct priorityIndex));
    memset(box->toys, 0, box->capacity * sizeof(struct toy));
    memset(box->idIndices, 0, box->capacity * sizeof(struct idIndex));
    box->count = 0;
}

static int parse_params(char *s, int *k, int *v)
{
	char *tok;
	char *lasts;

	tok = strtok_r(s, " \n", &lasts);
	if (!tok) {
		return -1;
	}
	*k = (int) strtol(tok, NULL, 10);

	if (!v) {
		return 0;
	}
	tok = strtok_r(NULL, " \n", &lasts);
	if (!tok) {
		return -1;
	}
	*v = (int) strtol(tok, NULL, 10);

	return 0;
}

int main(void)
{
    char *line = malloc(512);
    FILE *infp = stdin;
    FILE *outfp = stdout;
    struct box *box = NULL;
    int ret;
    int size, key, val;

    while (fgets(line, 512, infp)) {
        if (strncmp(line, "create ", 7) == 0) {
            if (parse_params(line + 7, &size, NULL) < 0) {
                fprintf(outfp, "err on parsing create\n");
                goto err;
            }
            box = create(size);
            fprintf(outfp, "create %d\n", size);
        } else if (strncmp(line, "destroy", 7) == 0) {
            destroy(box);
            fprintf(outfp, "destroy\n");
        } else if (strncmp(line, "put ", 4) == 0) {
            if (parse_params(line + 4, &key, &val) < 0) {
                fprintf(outfp, "err on parsing put\n");
                goto err;
            }
            put(box, key, val);
            fprintf(outfp, "put %d %d\n", key, val);
        } else if (strncmp(line, "pop", 3) == 0) {
            ret = pop(box);
            fprintf(outfp, "pop %d\n", ret);
        } else if (strncmp(line, "del ", 4) == 0) {
            if (parse_params(line + 4, &key, NULL) < 0) {
                fprintf(outfp, "err on parsing del\n");
                goto err;
            }
            ret = del(box, key);
            fprintf(outfp, "del %d %d\n", key, ret);
        } else if (strncmp(line, "clear", 5) == 0) {
			clear(box);
			fprintf(outfp, "clear\n");
		}
    }

    free(line);
    return 0;

err:
    free(line);
    return 1;
}
