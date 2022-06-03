from math import factorial

def solution(n, infectedHouses):
    base = 1e9 + 7
    result = 1
    dayDict = {}
    sortedInfectedHouses = infectedHouses[:]
    sortedInfectedHouses.sort()    
    
    # 첫째 집과 첫째 감염된 집의 거리
    for j in range(1, sortedInfectedHouses[0]):
        dayDict[j] = dayDict.get(j, 0) + 1

    # 감염된 집들 사이 전파 속도에 따른 개수 구하기 
    for i in range(0, len(sortedInfectedHouses) - 1):
        distBetweenInfectedHouses = sortedInfectedHouses[i + 1] - sortedInfectedHouses[i] - 1 
        share, remain = divmod(distBetweenInfectedHouses, 2)
        for j in range(1, share + 1):
            dayDict[j] = dayDict.get(j, 0) + 2
        dayDict[share + 1] = dayDict.get(share + 1, 0) + (remain * 1)

    # 마지막 집과 마지막 감염된 집의 거리
    for j in range(1, n - sortedInfectedHouses[-1] + 1):
        dayDict[j] = dayDict.get(j, 0) + 1
    
    # 날짜별 nPn 순열을 계산하여 전체 순열 가지수 구함
    for i in dayDict.values():
        result *= factorial(i)
    
    answer = int(result) % int(base)
    
    return answer

print(solution(6, [3, 5]))
print(solution(5, [1, 5]))
print(solution(4, [1]))