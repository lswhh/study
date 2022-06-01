# https://programmers.co.kr/learn/courses/30/lessons/43236

INF = 0xFFFFFFFF

def solution(distance, rocks, n):
    rocks.append(0)
    rocks.append(distance)
    rocks.sort()

    lowDist = 0
    highDist = distance
    maxDistOfMin = 1
    minDist = INF

    while lowDist <= highDist:
        midDist = (lowDist + highDist) //2
        tmpRocks = rocks[:]
        removeCount = 0

        minDist = INF
        for i in range(1, len(rocks) - 1):
            idx = i - removeCount
            if idx >= len(tmpRocks):
                break

            prevDist = tmpRocks[idx] - tmpRocks[idx-1]
            if prevDist < midDist:
                removeCount += 1
                del tmpRocks[idx]
                if removeCount > n:
                    minDist = INF
                    break
            else:
                if minDist > prevDist:
                    minDist = prevDist
        if minDist == INF:
            highDist = midDist - 1
        else:
            # print(midDist,tmpRocks)
            lowDist = midDist + 1
        if minDist != INF:
            if minDist > maxDistOfMin:
                maxDistOfMin = minDist
    answer = maxDistOfMin
    return answer

print(solution(25, [2, 14, 11, 21, 17], 2))

