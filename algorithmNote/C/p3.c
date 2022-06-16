#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUYER 100

struct buyer;
struct toy;
struct auction;

struct buyer {
    // 자유롭게 변수를 추가하실 수 있습니다.
    pthread_t tid;
    struct toy *toy;
    int n;
    struct auction *auction;
};

// 춘식이가 가진 장난감을 나타내는 구조체입니다.
struct toy {
    int idx;
    int price;
    // 자유롭게 변수를 추가하실 수 있습니다.
};

// 경매에 올라간 춘식이의 장난감들을 가지는 구조체입니다.
struct auction {
    pthread_mutex_t buyerMutex;
    pthread_t *buyers[MAX_BUYER];
    // 자유롭게 변수를 추가하실 수 있습니다.
    int buyer_count;
    pthread_t buyers_tid[MAX_BUYER];
    pthread_mutex_t startMutex;
    int isStart;
    int toy_num;
    int * toyIdx;
};

struct auction *create_auction(int toy_num);
void destroy_auction(struct auction *auction);
void start_auction(struct auction *auction);
int finish_auction(struct auction *auction);
void bid(struct auction *auction, int idx, int price);
void buyer_main(struct buyer *buyer);
void add_new_buyer(struct auction *auction, struct toy *toy, int n);

#define handle_error_en(en, msg) \
        do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

struct auction *create_auction(int toy_num)
{
    // `toy_num`개의 장난감을 경매로 내놓은 `auction`을 생성하여 리턴합니다.
    // - 이 함수는 항상 제일 먼저 호출됩니다.
    int i = 0;
    struct auction * auc;
    auc = calloc(sizeof(struct auction), 1);
    auc->toy_num = toy_num;
    auc->toyIdx = calloc(sizeof(int), toy_num);

    for (i = 0; i < MAX_BUYER; i++)
    {

    }
    pthread_mutex_init(&auc->buyerMutex, NULL);
    auc->isStart = 0;
    auc->buyer_count = 0;
    pthread_mutex_init(&auc->startMutex, NULL);
    return auc;
}

void destroy_auction(struct auction *auction)
{
    // `create_auction()`으로 생성된 `auction`을 정리합니다.
    // - 이 함수는 `create_auction()` 전에 호출되지 않으며 가장 마지막에 호출되는 함수입니다.
    free(auction);
}

void start_auction(struct auction *auction)
{
    // `buyer`들에게 `auction`의 시작을 알려줍니다.
    pthread_mutex_lock( &(auction->startMutex) );
    auction->isStart = 1;
    pthread_mutex_unlock( &(auction->startMutex) );

}

int finish_auction(struct auction *auction)
{
    // 모든 `buyer`의 입찰이 완료된 후 최종적으로 낙찰받은 장난감의 총 `price` 합을 반환합니다.
    //    - 아무도 입찰하지 않은 장난감의 `price`는 `0`입니다.
    //    - 입찰이 진행 중인 `buyer`가 있다면 모든 입찰이 완료될 때 까지 대기해야합니다.
}

void bid(struct auction *auction, int idx, int price)
{
    // `idx`번째의 장난감을 입찰하기 위한 가격을 부릅니다.
    //    - `idx`는 0부터 시작하며, `auction`의 `toy_num`보다 작습니다.
    //    - 동시에 여러명이 같은 `idx`로 `bid`를 부를 수 있습니다.
    //    - 같은 `idx`의 장난감에 대해, 가장 높은 `price`를 부른 `buyer`가 장난감을 낙찰받게 됩니다.

}
static void *
thread_start(void *arg)
{

}
void buyer_main(struct buyer *buyer)
{
    // `create_buyer()`된 `buyer`가 사용할 main 함수입니다.
    // 이 함수에서는 다음과 같은 작업을 수행해야합니다.
    //  (1) `start_auction()`이 호출될 때 까지 대기합니다.
    //  (2) `start_auction()`이 호출되었다면, `buyer`가 원하는 `toy`에 대해 모두 `bid()` 합니다.
    //  (3) `bid()`를 모두 완료했다면 `buyer` 구조체를 정리하고 종료합니다.
    int i = 0; 
    pthread_mutex_lock( &(buyer->auction->startMutex) );
    while (buyer->auction->isStart != 1)
    {
        pthread_mutex_unlock( &(buyer->auction->startMutex) );
        pthread_yield();
        pthread_mutex_lock( &(buyer->auction->startMutex) );
    }
    pthread_mutex_unlock( &(buyer->auction->startMutex) );

    for ( i = 0; i < buyer->n; i++ )
    {
        bid(buyer->auction, buyer->toy[i].idx, buyer->toy[i].price);
    }
    free(buyer->toy);
    free(buyer);    
}
__thread buyer_tid;
void add_new_buyer(struct auction *auction, struct toy *toy, int n)
{
    // `pthread_create`함수를 이용해 새로운 `buyer`를 새로운 쓰레드로 만들어 `auction`의 `buyers`에 추가합니다.
    // - `auction`은 `buyer`가 참여하려고 하는 경매를 가리킵니다.
    // - `toy`는 `buyer`가 구매하고자 하는 장난감의 `idx`와 `bid`할 `price`를 array 형태로 가지고 있습니다
    // - `n`은 `toy`의 크기를 나타냅니다.
    int s; 
    pthread_t thread_id;
    struct buyer *buyer;

    buyer = calloc(sizeof(struct buyer), 1);
    buyer->n = n;
    buyer->toy = toy;
    buyer->auction = auction;
    
    s = pthread_create( &buyer_tid, NULL,
                        &thread_start, (void*)buyer);
    if (s != 0)
    {
        handle_error_en(s, "pthread_create");
    }
    auction->buyers[auction->buyer_count]
}