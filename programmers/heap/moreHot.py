# https://programmers.co.kr/learn/courses/30/lessons/42626
import heapq

INF = 0xFFFFFFFF
def solution(scoville, K):
    q = []
    minScoville = INF
    for i in scoville:
        heapq.heappush(q, i)
    count = 0
    minScoville = q[0] # 최소 값
    while minScoville < K and len(q) >= 2:
        firstMinValue = heapq.heappop(q)
        secondMinValue = heapq.heappop(q)
        newScovilleValue = firstMinValue + (secondMinValue * 2)
        heapq.heappush(q, newScovilleValue)
        minScoville = q[0]
        count += 1

    answer = 0
    if minScoville < K:
        answer = -1
    else: 
        answer = count    
    return answer


print(solution([1, 2, 3, 9, 10, 12], 7)) #2