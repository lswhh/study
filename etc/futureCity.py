INF = 0xFFFFFFFF
#n: 개수, x:목표 도시, k:경유지
def solution(n, x, k, cityConnectList):
    cityMap = [[INF for j in range(n+1)] for i in range(n + 1)]

    for a in range(1, n + 1):
        cityMap[a][a] = 0

    # 전체 연결 통로 초기화
    for connectPath in cityConnectList:
        cityMap[connectPath[0]][connectPath[1]] = 1
        cityMap[connectPath[1]][connectPath[0]] = 1
    
    for k in range(1, n + 1):
        for a in range(1, n + 1):
            for b in range(1, n + 1):
                distance = (cityMap[a][k] + cityMap[k][b])
                if cityMap[a][b] > distance :
                    cityMap[a][b] = distance

    result = cityMap[1][k] + cityMap[k][x]
    if result >= INF:
        result = -1
    else:
        pass
    return result


print(solution(5, 4, 5, [[1,2], [1,3], [1, 4], [2,4], [3, 4], [3,5], [4,5]]))
print(solution(4, 3, 4, [[1,3], [2,4]]))