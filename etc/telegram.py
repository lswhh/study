import heapq

INF = 0xFFFFFFFF

def dijkstra(distance, graph, c):
    distance[c] = 0
    priqueue = [] # 비용, 타겟노드
    heapq.heappush(priqueue,(0, c))
    gCityIdx = 1
    gCostIdx = 0
    while priqueue:
        dist, curCity = heapq.heappop(priqueue)
        print(dist, curCity, distance[curCity])
        if distance[curCity] < dist:
             continue
        if curCity in graph:
            for i in graph[curCity]:
                targetCity = i[gCityIdx]
                cost = dist + i[gCostIdx] # 현재까지의 거리(dist)에 내 비용을 더한 값이 targetCity까지 가는 비용
                if distance[targetCity] > cost:
                    distance[targetCity] = cost
                    heapq.heappush(priqueue, (cost, targetCity))


    return
# 노드개수: n, 통로 개수:m, 출발노드: c, 통로 연결 정보: pathList
# index of distance: 노드 번호
def solution(n, m, c, pathList):
    result1 = 0
    result2 = 0
    distance = [INF] * (n + 1)
    distance[c] = 0
    # pathList.sort()
    # graph = [[] for _ in range( n + 1 )]
    graph = {} #idx: 출발노드, (비용, 목표노드)
    for i in pathList:
        if i[0] in graph:
            graph[i[0]].append((i[2],i[1]))
        else:
            graph[i[0]] = []
            graph[i[0]].append((i[2],i[1]))

    dijkstra(distance, graph, c)
    # for i in pathList:
    count = -1
    maxValue = 0
    for i in distance:
        if i != INF:
            print(i)
            count += 1
            if i > maxValue and i != 0:
                maxValue = i

    return count, maxValue


print(solution(3, 2, 1, [[1,2,4], [1,3,2]]))