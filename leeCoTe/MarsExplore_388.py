# page 388 화성 탐사

import heapq
import sys

INF = 0xFFFFFFFF
# startPoint: (x, y) 좌표
def dijkstra(startPoint, energyMatrix, n):
    # 초기 배열을 무한으로 설정
    energyConsume = [[INF] * n for _ in range(n)]
    # 시작 노드의 에너지 설정
    energyConsume[startPoint[0]][startPoint[1]] = energyMatrix[startPoint[0]][startPoint[1]]
    queue = []
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]

    heapq.heappush(queue, (energyConsume[startPoint[0]][startPoint[1]], startPoint))

    while queue:
        # 가장 적은 에너지를 가진 노드와 거리를 추출
        currentEnergy, currentPoint = heapq.heappop(queue)
        # 이미 계산되어 저장한 에너지와 추출된 거리의 에너지를 비교하여 저장된 에너지가 더 작다면 무시
        if energyConsume[currentPoint[0]][currentPoint[1]] < currentEnergy:
            continue

        # 대상인 노드에서 인접한 지점을 검색
        for i in range(4):
            nextPointX = currentPoint[0] + dx[i]
            nextPointY = currentPoint[1] + dy[i]
            if nextPointX < 0 or nextPointY < 0 or nextPointX >= n or nextPointY >= n:
                continue
            # 현재 노드에서 인접한 노드를 지나갈 때까지의 거리를 더함
            nextNodeDist = currentEnergy + energyMatrix[nextPointX][nextPointY]
            # 저장된 거리보다 더 작으면 해당 노드의 거리 변경
            if nextNodeDist < energyConsume[nextPointX][nextPointY]:
                energyConsume[nextPointX][nextPointY] = nextNodeDist
                # 최소 거리가 갱신되었으므로 큐에 삽입
                heapq.heappush(queue, (nextNodeDist, (nextPointX, nextPointY)))

    return energyConsume[n-1][n-1]

def solution(energyMatrix, n):
    answer = 0

    answer = dijkstra((0,0),energyMatrix, n)

    return answer

print(solution([[5,5,4],
                [3,9,1],
                [3,2,7]], 3))