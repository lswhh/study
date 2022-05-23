# https://programmers.co.kr/learn/courses/30/lessons/72411?language=python3

import collections
from itertools import combinations

def solution(orders, course):
    candidateSetList = []
    
    resultList = []
    for i in course:
        candidateSetList = []
        for j in orders:
            candidateSetList += combinations(sorted(list(j)), i)
        candidateCounter = collections.Counter(candidateSetList).most_common()

        for k, v in candidateCounter:
            if v > 1 and v == candidateCounter[0][1]:
                resultList.append(''.join(k))

    resultList.sort()
    answer = resultList
    return answer

print(solution(["XYZ", "XWY", "WXA"],	[2,3,4]))								#["WX", "XY"]
print(solution(["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"],	[2,3,4]))	#["AC", "ACDE", "BCFG", "CDE"]
print(solution(["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"],	[2,3,5]))	#["ACD", "AD", "ADE", "CD", "XYZ"]
