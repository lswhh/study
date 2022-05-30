import heapq
import sys

INF = 0xFFFFFFFF
def dijkstra(start):
    # 초기 배열 설정
    distances = {node: INF for node in graph}
    # 시작 노드의 거리는 0으로 설정
    distances[start] = 0
    queue = []
    # 시작 노드부터 탐색 시작 하기 위함. (거리, 노드) - 
    # 거리, 노드 순으로 넣은 이유는 heapq에 첫 번째 데이터를 기준으로 정렬 시키기 위함
    heapq.heappush(queue, (distances[start], start))

    # 우선 순위 큐에 데이터가 하나도 없을 때까지 반복
    while queue:
        # 가장 낮은 거리를 가진 노드와 거리를 추출
        currentDistance, node = heapq.heappop(queue)
        # 이미 계산되어 저장한 거리와 추출된 거리와 비교하여 저장된 거리가 더 작다면 무시
        if distances[node] < currentDistance:
            continue

        # 대상인 노드에서 인접한 노드와 거리를 순회
        for nextNode, distance in graph[node].items():
            # 현재 노드에서 인접한 노드를 지나갈 때까지의 거리를 더함
            nextNodeDist = currentDistance + distance
            # 저장된 거리보다 더 작으면 해당 노드의 거리 변경
            if nextNodeDist < distances[nextNode]:
                distances[nextNode] = nextNodeDist
                # 최소 거리가 갱신되었으므로 큐에 삽입
                heapq.heappush(queue, (nextNodeDist, nextNode))

    return distances

graph = {
    'A': {'B': 10, 'C': 3},
    'B': {'C': 1, 'D': 2},
    'C': {'B': 4, 'D': 8, 'E': 2},
    'D': {'E': 7},
    'E': {'D': 9},
}

result = dijkstra('A')
print(result)

# {'A': 0, 'B': 7, 'C': 3, 'D': 9, 'E': 5}