def solution(citations):
    citations.sort(reverse = True)
    citationCnt = citations[0]
    h = 0
    if citations[0] > 0:
        h = 1
    for i in range(0,len(citations)):
        if citationCnt > citations[i]:
            citationCnt = citations[i]
        paperCnt = i + 1
        if citationCnt >= paperCnt:
            h = paperCnt

    answer = h
    return answer

print(solution([3, 0, 6, 1, 5])) #3
print(solution([0]))
print(solution([1]))